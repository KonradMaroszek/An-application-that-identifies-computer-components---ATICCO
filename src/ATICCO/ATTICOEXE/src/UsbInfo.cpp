#include <UsbInfo.h>


USBInfo::USBInfo()
{
    options.insert(USB_CLASS, SPDRP_CLASS );
    options.insert(USB_DEVICEDESC, SPDRP_DEVICEDESC);
    options.insert(USB_ENUMERATOR_NAME, SPDRP_ENUMERATOR_NAME );
    options.insert(USB_PHYSICAL_DEVICE_OBJECT_NAME, SPDRP_PHYSICAL_DEVICE_OBJECT_NAME );
    options.insert(USB_HARDWAREID, SPDRP_HARDWAREID );
}

USBInfo::~USBInfo()
{

}


void USBInfo::getInfoFromDeviceInstance(QSharedPointer<USBInformation> deviceInformation)
{
    foreach (int option ,options.values())
    {
        SetupDiGetDeviceRegistryPropertyW(deviceInfoSet,&deviceInfoData, option ,NULL,NULL,0, &bufferSize);

        buffer = new QSharedPointer<wchar_t>(new wchar_t[bufferSize*sizeof(wchar_t)]) ;

        if(SetupDiGetDeviceRegistryPropertyW(deviceInfoSet,&deviceInfoData, option , NULL ,(PBYTE)(buffer->data()) ,bufferSize, &bufferSize))
        {
            operationResultWSTR = buffer->data();
            operationResultQString = QString::fromStdWString(operationResultWSTR);
            deviceInformation.data()->deviceInfoMap.insert(options.key(option), operationResultQString);
        }
    }
}

void USBInfo::getDeviceChild(DEVINST deviceInstance, QSharedPointer<USBInformation> deviceInformation , int childNumber, QSharedPointer<USBInformation> parentInformation)
{
    DEVINST child;
    SetupDiEnumDeviceInfo(deviceInfoSet, 0 , &deviceInfoData);

    QSharedPointer<USBInformation> usbDeviceInformation;

    if (CM_Get_Child(&child,deviceInstance,0) == CR_SUCCESS)
    {
         usbDeviceInformation = QSharedPointer<USBInformation>(new USBInformation());
         deviceInformation.data()->children.append(usbDeviceInformation);
         SetupDiEnumDeviceInfo(deviceInfoSet, instanceMap.value(child), &deviceInfoData);
         getInfoFromDeviceInstance(usbDeviceInformation);

         getDeviceChild(child , usbDeviceInformation, child , deviceInformation);
    }

    if (!(childNumber == -1))
    {
        getDeviceSibiling(childNumber,usbDeviceInformation, childNumber, parentInformation);
    }
}

void USBInfo::getDeviceSibiling(DEVINST v_deviceInstance, QSharedPointer<USBInformation> v_deviceInformation , int childNumber, QSharedPointer<USBInformation> v_parentInformation)
{
    Q_UNUSED(childNumber);

    DEVINST sibiling;
    SetupDiEnumDeviceInfo(deviceInfoSet, 0 , &deviceInfoData);

    QSharedPointer<USBInformation> deviceInformation;

    if (CM_Get_Sibling(&sibiling,v_deviceInstance,0) == CR_SUCCESS)
    {
        deviceInformation = QSharedPointer<USBInformation>(new USBInformation());
        v_parentInformation.data()->children.append(deviceInformation);
        SetupDiEnumDeviceInfo(deviceInfoSet, instanceMap.value(sibiling), &deviceInfoData);
        getInfoFromDeviceInstance(deviceInformation);

        getDeviceChild(sibiling , deviceInformation, sibiling , v_parentInformation);
    }
}

QList<QSharedPointer<USBInformation>> USBInfo::getUSBInfo()
{
    deviceInfoSet = SetupDiCreateDeviceInfoList(NULL, NULL);
    SetupDiGetClassDevsExW(NULL, NULL , NULL, DIGCF_PRESENT | DIGCF_ALLCLASSES, deviceInfoSet, NULL , NULL);

    if(deviceInfoSet == INVALID_HANDLE_VALUE)
    {
        return QList<QSharedPointer<USBInformation>>();
    }

    DWORD deviceInfoSetMemberIndex = 0;

    while (true)
    {
        deviceInfoData.cbSize = sizeof(deviceInfoData);

        if (!SetupDiEnumDeviceInfo(deviceInfoSet,deviceInfoSetMemberIndex, &deviceInfoData))
        {
            break;
        }

        instanceMap.insert(deviceInfoData.DevInst,deviceInfoSetMemberIndex);

        SetupDiGetDeviceRegistryPropertyW(deviceInfoSet,&deviceInfoData, SPDRP_ENUMERATOR_NAME,NULL,NULL,0, &bufferSize);
        buffer = new QSharedPointer<wchar_t>(new wchar_t[bufferSize*sizeof(wchar_t)]) ;

        if (!SetupDiGetDeviceRegistryPropertyW(deviceInfoSet,&deviceInfoData, SPDRP_ENUMERATOR_NAME, NULL ,(PBYTE)(buffer->data()) ,bufferSize, &bufferSize))
        {
            deviceInfoSetMemberIndex++;
            continue;
        }

        operationResultWSTR = buffer->data();
        operationResultQString = QString::fromStdWString(operationResultWSTR);

        if (operationResultQString == "PCI")
        {

        }else
        {
            deviceInfoSetMemberIndex++;
            continue;
        }

        SetupDiGetDeviceRegistryPropertyW(deviceInfoSet,&deviceInfoData, SPDRP_CLASS,NULL,NULL,0, &bufferSize);
        buffer = new QSharedPointer<wchar_t>(new wchar_t[bufferSize*sizeof(wchar_t)]) ;

        if (!SetupDiGetDeviceRegistryPropertyW(deviceInfoSet,&deviceInfoData, SPDRP_CLASS, NULL ,(PBYTE)(buffer->data()) ,bufferSize, &bufferSize))
        {
            deviceInfoSetMemberIndex++;
            continue;
        }

        operationResultWSTR = buffer->data();
        operationResultQString = QString::fromStdWString(operationResultWSTR);

        if (operationResultQString == "USB")
        {
             deviceInstanceList.append(deviceInfoData.DevInst);
        }

        deviceInfoSetMemberIndex++;
    }

    foreach (DEVINST deviceInstance, deviceInstanceList)
    {
        QSharedPointer<USBInformation> deviceInformation = QSharedPointer<USBInformation>(new USBInformation());
        devices.append(deviceInformation);

        SetupDiEnumDeviceInfo(deviceInfoSet, 0 , &deviceInfoData);
        SetupDiEnumDeviceInfo(deviceInfoSet, instanceMap.value(deviceInstance) , &deviceInfoData);

        getInfoFromDeviceInstance(deviceInformation);
        getDeviceChild(deviceInstance, deviceInformation, -1, deviceInformation);
    }


    SetupDiDestroyDeviceInfoList(deviceInfoSet);
    return devices;
}

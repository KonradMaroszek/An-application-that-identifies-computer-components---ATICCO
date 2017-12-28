#include <UsbInfo.h>


USBInfo::USBInfo()
{
    m_options.insert(USB_CLASS, SPDRP_CLASS );
    m_options.insert(USB_DEVICEDESC, SPDRP_DEVICEDESC);
    m_options.insert(USB_ENUMERATOR_NAME, SPDRP_ENUMERATOR_NAME );
    m_options.insert(USB_PHYSICAL_DEVICE_OBJECT_NAME, SPDRP_PHYSICAL_DEVICE_OBJECT_NAME );
    m_options.insert(USB_HARDWAREID, SPDRP_HARDWAREID );
}

USBInfo::~USBInfo()
{

}


void USBInfo::getInfoFromDeviceInstance(QSharedPointer<USBInformation> v_deviceInformation)
{
    foreach (int option ,m_options.values())
    {
        SetupDiGetDeviceRegistryPropertyW(m_deviceInfoSet,&m_deviceInfoData, option ,NULL,NULL,0, &m_bufferSize);

        m_buffer = new QSharedPointer<wchar_t>(new wchar_t[m_bufferSize*sizeof(wchar_t)]) ;

        if(SetupDiGetDeviceRegistryPropertyW(m_deviceInfoSet,&m_deviceInfoData, option , NULL ,(PBYTE)(m_buffer->data()) ,m_bufferSize, &m_bufferSize))
        {
            m_operationResultWSTR = m_buffer->data();
            m_operationResultQString = QString::fromStdWString(m_operationResultWSTR);
            v_deviceInformation.data()->m_deviceInfoMap.insert(m_options.key(option), m_operationResultQString);
        }
    }
}

void USBInfo::getDeviceChild(DEVINST v_deviceInstance, QSharedPointer<USBInformation> v_deviceInformation , int childNumber, QSharedPointer<USBInformation> v_parentInformation)
{
    DEVINST child;
    SetupDiEnumDeviceInfo(m_deviceInfoSet, 0 , &m_deviceInfoData);

    QSharedPointer<USBInformation> deviceInformation;

    if (CM_Get_Child(&child,v_deviceInstance,0) == CR_SUCCESS)
    {
         deviceInformation = QSharedPointer<USBInformation>(new USBInformation());
         v_deviceInformation.data()->m_children.append(deviceInformation);
         SetupDiEnumDeviceInfo(m_deviceInfoSet, m_instanceMap.value(child), &m_deviceInfoData);
         getInfoFromDeviceInstance(deviceInformation);

         getDeviceChild(child , deviceInformation, child , v_deviceInformation);
    }

    if (!(childNumber == -1))
    {
        getDeviceSibiling(childNumber,deviceInformation, childNumber, v_parentInformation);
    }
}

void USBInfo::getDeviceSibiling(DEVINST v_deviceInstance, QSharedPointer<USBInformation> v_deviceInformation , int childNumber, QSharedPointer<USBInformation> v_parentInformation)
{
    Q_UNUSED(childNumber);

    DEVINST sibiling;
    SetupDiEnumDeviceInfo(m_deviceInfoSet, 0 , &m_deviceInfoData);

    QSharedPointer<USBInformation> deviceInformation;

    if (CM_Get_Sibling(&sibiling,v_deviceInstance,0) == CR_SUCCESS)
    {
        deviceInformation = QSharedPointer<USBInformation>(new USBInformation());
        v_parentInformation.data()->m_children.append(deviceInformation);
        SetupDiEnumDeviceInfo(m_deviceInfoSet, m_instanceMap.value(sibiling), &m_deviceInfoData);
        getInfoFromDeviceInstance(deviceInformation);

        getDeviceChild(sibiling , deviceInformation, sibiling , v_parentInformation);
    }
}

QList<QSharedPointer<USBInformation>> USBInfo::getUSBInfo()
{
    m_deviceInfoSet = SetupDiCreateDeviceInfoList(NULL, NULL);
    SetupDiGetClassDevsExW(NULL, NULL , NULL, DIGCF_PRESENT | DIGCF_ALLCLASSES, m_deviceInfoSet, NULL , NULL);

    if(m_deviceInfoSet == INVALID_HANDLE_VALUE)
    {
        return QList<QSharedPointer<USBInformation>>();
    }

    DWORD deviceInfoSetMemberIndex = 0;

    while (true)
    {
        m_deviceInfoData.cbSize = sizeof(m_deviceInfoData);

        if (!SetupDiEnumDeviceInfo(m_deviceInfoSet,deviceInfoSetMemberIndex, &m_deviceInfoData))
        {
            break;
        }

        m_instanceMap.insert(m_deviceInfoData.DevInst,deviceInfoSetMemberIndex);

        SetupDiGetDeviceRegistryPropertyW(m_deviceInfoSet,&m_deviceInfoData, SPDRP_ENUMERATOR_NAME,NULL,NULL,0, &m_bufferSize);
        m_buffer = new QSharedPointer<wchar_t>(new wchar_t[m_bufferSize*sizeof(wchar_t)]) ;

        if (!SetupDiGetDeviceRegistryPropertyW(m_deviceInfoSet,&m_deviceInfoData, SPDRP_ENUMERATOR_NAME, NULL ,(PBYTE)(m_buffer->data()) ,m_bufferSize, &m_bufferSize))
        {
            deviceInfoSetMemberIndex++;
            continue;
        }

        m_operationResultWSTR = m_buffer->data();
        m_operationResultQString = QString::fromStdWString(m_operationResultWSTR);

        if (m_operationResultQString == "PCI")
        {

        }else
        {
            deviceInfoSetMemberIndex++;
            continue;
        }

        SetupDiGetDeviceRegistryPropertyW(m_deviceInfoSet,&m_deviceInfoData, SPDRP_CLASS,NULL,NULL,0, &m_bufferSize);
        m_buffer = new QSharedPointer<wchar_t>(new wchar_t[m_bufferSize*sizeof(wchar_t)]) ;

        if (!SetupDiGetDeviceRegistryPropertyW(m_deviceInfoSet,&m_deviceInfoData, SPDRP_CLASS, NULL ,(PBYTE)(m_buffer->data()) ,m_bufferSize, &m_bufferSize))
        {
            deviceInfoSetMemberIndex++;
            continue;
        }

        m_operationResultWSTR = m_buffer->data();
        m_operationResultQString = QString::fromStdWString(m_operationResultWSTR);

        if (m_operationResultQString == "USB")
        {
             m_deviceInstanceList.append(m_deviceInfoData.DevInst);
        }

        deviceInfoSetMemberIndex++;
    }

    foreach (DEVINST deviceInstance, m_deviceInstanceList)
    {
        QSharedPointer<USBInformation> deviceInformation = QSharedPointer<USBInformation>(new USBInformation());
        m_devices.append(deviceInformation);

        SetupDiEnumDeviceInfo(m_deviceInfoSet, 0 , &m_deviceInfoData);
        SetupDiEnumDeviceInfo(m_deviceInfoSet, m_instanceMap.value(deviceInstance) , &m_deviceInfoData);

        getInfoFromDeviceInstance(deviceInformation);
        getDeviceChild(deviceInstance, deviceInformation, -1, deviceInformation);
    }


    SetupDiDestroyDeviceInfoList(m_deviceInfoSet);
    return m_devices;
}

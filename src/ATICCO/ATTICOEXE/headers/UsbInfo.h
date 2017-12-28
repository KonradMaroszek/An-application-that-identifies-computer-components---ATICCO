#ifndef USBINFO_H
#define USBINFO_H

#include <QList>
#include <QString>
#include <QMap>
#include <QSharedPointer>
#include <Windows.h>
#include <cfgmgr32.h>
#include <SetupAPI.h>

#define USB_CLASS                          1
#define USB_DEVICEDESC                     2
#define USB_ENUMERATOR_NAME                3
#define USB_PHYSICAL_DEVICE_OBJECT_NAME    4
#define USB_HARDWAREID                     5

struct USBInformation
{
    QMap<int,QString> m_deviceInfoMap;
    QList<QSharedPointer<USBInformation>> m_children;
};

class USBInfo
{
public:
    USBInfo();
    virtual ~USBInfo();
    virtual QList<QSharedPointer<USBInformation>> getUSBInfo();

private:
    void getInfoFromDeviceInstance(QSharedPointer<USBInformation> v_deviceInformation);
    void getDeviceChild(DEVINST v_deviceInstance, QSharedPointer<USBInformation> v_deviceInformation ,int childNumber, QSharedPointer<USBInformation> v_parentInformation);
    void getDeviceSibiling(DEVINST v_deviceInstance, QSharedPointer<USBInformation> v_deviceInformation , int childNumber, QSharedPointer<USBInformation> v_parentInformation);

private:
    QMap<int,int> m_options;
    QList<QSharedPointer<USBInformation>> m_devices;
    HDEVINFO m_deviceInfoSet;
    SP_DEVINFO_DATA m_deviceInfoData;
    ULONG m_bufferSize;
    QSharedPointer<wchar_t>* m_buffer;
    std::wstring m_operationResultWSTR;
    QString m_operationResultQString;
    QList<DEVINST> m_deviceInstanceList;
    QMap<DEVINST, DWORD> m_instanceMap;
};

#endif // USBINFO_H

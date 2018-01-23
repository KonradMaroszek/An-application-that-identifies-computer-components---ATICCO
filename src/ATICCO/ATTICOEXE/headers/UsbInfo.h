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
    QMap<int,QString> deviceInfoMap;
    QList<QSharedPointer<USBInformation>> children;
};

class USBInfo
{
public:
    USBInfo();
    virtual ~USBInfo();

public:
    virtual QList<QSharedPointer<USBInformation>> getUSBInfo();

private:
    void getInfoFromDeviceInstance(QSharedPointer<USBInformation> deviceInformation);
    void getDeviceChild(DEVINST deviceInstance, QSharedPointer<USBInformation> deviceInformation , int childNumber, QSharedPointer<USBInformation> parentInformation);
    void getDeviceSibiling(DEVINST deviceInstance, QSharedPointer<USBInformation> deviceInformation , int childNumber, QSharedPointer<USBInformation> parentInformation);

private:
    QMap<int,int> options;
    QList<QSharedPointer<USBInformation>> devices;
    HDEVINFO deviceInfoSet;
    SP_DEVINFO_DATA deviceInfoData;
    ULONG bufferSize;
    QSharedPointer<wchar_t>* buffer;
    std::wstring operationResultWSTR;
    QString operationResultQString;
    QList<DEVINST> deviceInstanceList;
    QMap<DEVINST, DWORD> instanceMap;
};

#endif // USBINFO_H

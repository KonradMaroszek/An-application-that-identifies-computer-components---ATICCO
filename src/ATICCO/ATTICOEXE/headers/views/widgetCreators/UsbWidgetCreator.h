#ifndef USBWIDGETCREATOR_H
#define USBWIDGETCREATOR_H

#include "WidgetCreator.h"
#include "USBInfo.h"

#include <QSharedPointer>
#include <QList>
#include <QTreeWidgetItem>

class UsbWidgetCreator : public WidgetCreator
{
public:
    UsbWidgetCreator() {}
    virtual ~UsbWidgetCreator() {}

    virtual void setData(QList<QSharedPointer<USBInformation>> v_data);
    virtual QWidget* createWidget();
private:
    QTreeWidgetItem *childAt(QTreeWidgetItem *parent, int v_index);
    QTreeWidgetItem *createTreeItem(QMap<int,QString> v_deviceInfoMap , QTreeWidgetItem *v_parent, int v_index);
    void printUsbTree(QSharedPointer<USBInformation> v_deviceInformation, QTreeWidgetItem *v_parent, int v_index);
    QTreeWidget* m_USBtree;
    QList<QSharedPointer<USBInformation>> m_data;
    QIcon m_keyIcon;
    void setTreeHeaders();
    void setHeadersResizeToContestMode();
    void customizeTreeHeaders();
    void fillUsbTree();
    void setTreeItemValues(QMap<int,QString> v_deviceInfoMap, QTreeWidgetItem *item);
};

#endif // USBWIDGETCREATOR_H

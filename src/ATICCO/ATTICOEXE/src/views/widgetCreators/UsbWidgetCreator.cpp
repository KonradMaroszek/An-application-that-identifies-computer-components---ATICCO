#include "views/widgetCreators/UsbWidgetCreator.h"

#include <QHeaderView>

void UsbWidgetCreator::setData(QList<QSharedPointer<USBInformation>> v_data)
{
    m_data = v_data;
}

void UsbWidgetCreator::setTreeHeaders()
{
    QStringList labels;
    labels.append(QObject::tr("Class"));
    labels.append(QObject::tr("Name"));
    labels.append(QObject::tr("Hardware ID"));
    labels.append(QObject::tr("Enumerator name"));
    labels.append(QObject::tr("Physical name"));

    m_USBtree->setHeaderLabels(labels);
}

void UsbWidgetCreator::setHeadersResizeToContestMode()
{
    m_USBtree->header()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    m_USBtree->header()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    m_USBtree->header()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    m_USBtree->header()->setSectionResizeMode(3, QHeaderView::ResizeToContents);
    m_USBtree->header()->setSectionResizeMode(4, QHeaderView::ResizeToContents);
}

void UsbWidgetCreator::customizeTreeHeaders()
{
    setTreeHeaders();
    setHeadersResizeToContestMode();
}

void UsbWidgetCreator::fillUsbTree()
{
    foreach(QSharedPointer<USBInformation> usbinformation, m_data)
    {
        printUsbTree(usbinformation,0,0);
    }
}

QWidget *UsbWidgetCreator::createWidget()
{
    m_USBtree = new QTreeWidget();

    customizeTreeHeaders();

    m_keyIcon.addPixmap(m_USBtree->style()->standardPixmap(QStyle::SP_ComputerIcon));

    fillUsbTree();

    m_USBtree->expandAll();

    return m_USBtree;
}

QTreeWidgetItem *UsbWidgetCreator::childAt(QTreeWidgetItem *parent, int v_index)
{
    if (parent)
    {
        return parent->child(v_index);
    }
    else
    {
        return m_USBtree->topLevelItem(v_index);
    }
}

void UsbWidgetCreator::setTreeItemValues(QMap<int,QString> v_deviceInfoMap, QTreeWidgetItem *item)
{
    item->setText(0, v_deviceInfoMap.value(USB_CLASS));
    item->setText(1, v_deviceInfoMap.value(USB_DEVICEDESC));
    item->setText(2, v_deviceInfoMap.value(USB_HARDWAREID));
    item->setText(3, v_deviceInfoMap.value(USB_ENUMERATOR_NAME));
    item->setText(4, v_deviceInfoMap.value(USB_PHYSICAL_DEVICE_OBJECT_NAME));

    item->setIcon(0, m_keyIcon);
}

QTreeWidgetItem *UsbWidgetCreator::createTreeItem(QMap<int,QString> v_deviceInfoMap , QTreeWidgetItem *v_parent, int v_index)
{
    QTreeWidgetItem *after = 0;

    if (v_index != 0)
    {
        after = childAt(v_parent, v_index - 1);
    }

    QTreeWidgetItem *item;

    if (v_parent)
    {
        item = new QTreeWidgetItem(v_parent, after);
    }
    else
    {
        item = new QTreeWidgetItem(m_USBtree,after,0);
    }

    setTreeItemValues(v_deviceInfoMap, item);

    return item;
}

void UsbWidgetCreator::printUsbTree(QSharedPointer<USBInformation> v_deviceInformation, QTreeWidgetItem *v_parent, int v_index)
{
    QTreeWidgetItem* child = createTreeItem(v_deviceInformation.data()->deviceInfoMap, v_parent, v_index);

    foreach (QSharedPointer<USBInformation> deviceInformation ,v_deviceInformation.data()->children)
    {
        printUsbTree(deviceInformation, child, v_index + 1);
    }
}


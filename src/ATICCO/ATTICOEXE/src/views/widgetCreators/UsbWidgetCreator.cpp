#include "views/widgetCreators/UsbWidgetCreator.h"

#include <QHeaderView>

void UsbWidgetCreator::setData(QList<QSharedPointer<USBInformation>> v_data)
{
    m_data = v_data;
}

QWidget *UsbWidgetCreator::createWidget()
{
    m_USBtree = new QTreeWidget;

    QStringList labels;
    labels << QObject::tr("Class") << QObject::tr("Name") << QObject::tr("Hardware ID");

    m_keyIcon.addPixmap(m_USBtree->style()->standardPixmap(QStyle::SP_ComputerIcon));

    m_USBtree->setHeaderLabels(labels);
    m_USBtree->header()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    m_USBtree->header()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    m_USBtree->header()->setSectionResizeMode(2, QHeaderView::ResizeToContents);

    foreach(QSharedPointer<USBInformation> usbinformation, m_data)
    {
        printUsbTree(usbinformation,0,0);
    }

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

QTreeWidgetItem *UsbWidgetCreator::createItem(QMap<int,QString> v_deviceInfoMap , QTreeWidgetItem *v_parent, int v_index)
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

    item->setText(0, v_deviceInfoMap.value(USB_CLASS));
    item->setText(1, v_deviceInfoMap.value(USB_DEVICEDESC));
    item->setText(2, v_deviceInfoMap.value(USB_HARDWAREID));

    item->setIcon(0, m_keyIcon);

    return item;
}

void UsbWidgetCreator::printUsbTree(QSharedPointer<USBInformation> v_deviceInformation, QTreeWidgetItem *v_parent, int v_index)
{
    QTreeWidgetItem* child = createItem(v_deviceInformation.data()->m_deviceInfoMap, v_parent, v_index);

    foreach (QSharedPointer<USBInformation> deviceInformation ,v_deviceInformation.data()->m_children)
    {
        printUsbTree(deviceInformation, child, v_index + 1);
    }
}


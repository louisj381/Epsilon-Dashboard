#include <QUdpSocket>

#include "CommDeviceManager.h"
#include <QDebug>

CommDeviceManager::CommDeviceManager(QUdpSocket& udpSocket)
    : udpSocket_(udpSocket)
{
}

CommDeviceManager::~CommDeviceManager()
{
}

void CommDeviceManager::connectToDevice(CommDefines::Type type)
{
    disconnectFromDevices();

    if (type == CommDefines::Udp)
    {
        connect(&udpSocket_, SIGNAL(readyRead()), this, SLOT(handleUdpDataIncoming()), Qt::UniqueConnection);
    }

    // potential to add bluetooth here as a different input device
}

void CommDeviceManager::disconnectFromDevices()
{
    disconnect(&udpSocket_, 0, this, 0);
}

void CommDeviceManager::handleUdpDataIncoming()
{
    while (udpSocket_.hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(udpSocket_.pendingDatagramSize());
        udpSocket_.readDatagram(datagram.data(), datagram.size());

        if (!datagram.isEmpty())
        {
            emit dataReceived(datagram);
        }
    }
}

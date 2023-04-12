//
// Created by oscaraad on 31/03/23.
//
#include "SerialWorker.h"
#include "ListaSimple.h"

SerialWorker::SerialWorker(QObject *parent) : QObject(parent)
{
    m_serialPort.setBaudRate(QSerialPort::Baud9600);
    m_serialPort.setPortName("/dev/ttyACM0");
    m_serialPort.open(QIODevice::ReadWrite);

    connect(&m_serialPort, &QSerialPort::readyRead, this, &SerialWorker::readData);
}

void SerialWorker::readData()
{
    QList<QString> dataList;
    ListaSimple list;
    m_data += m_serialPort.readAll();

    if (m_data.endsWith("\n")) {
        QStringList subStrings = QString(m_data).split(",");

        //dataList.append(QString(m_data));
        //emit dataReceived(QString(m_data));

        for (const QString& subString : subStrings) {
            bool ok = false;
            int value = subString.trimmed().toInt(&ok);
            if (ok) {
                list.insertHead(value);
            }
        }
        emit dataReceived(list);
        m_data.clear();
    }
}

void SerialWorker::writeData(const QByteArray &data)
{
    m_serialPort.write(data);
}


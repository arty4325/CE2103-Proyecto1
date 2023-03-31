//
// Created by oscaraad on 31/03/23.
//

#ifndef BATTLE_SPACE_SERIALWORKER_H
#define BATTLE_SPACE_SERIALWORKER_H

#include <QObject>
#include <QSerialPort>

class SerialWorker : public QObject
{
Q_OBJECT
public:
    explicit SerialWorker(QObject *parent = nullptr);
    ~SerialWorker() {}

signals:
    void dataReceived(const QString& data);
    void finished();

public slots:
    void readData();

private:
    QSerialPort m_serialPort;
    QByteArray m_data;
};



#endif //BATTLE_SPACE_SERIALWORKER_H
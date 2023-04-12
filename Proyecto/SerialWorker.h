//
// Created by oscaraad on 31/03/23.
//

#ifndef BATTLE_SPACE_SERIALWORKER_H
#define BATTLE_SPACE_SERIALWORKER_H

#include <QObject>
#include <QSerialPort>
#include "ListaSimple.h"

class SerialWorker : public QObject
{
Q_OBJECT
public:
    explicit SerialWorker(QObject *parent = nullptr);
    ~SerialWorker() {}

signals:
    void dataReceived(ListaSimple lista);
    void finished();

public slots:
    void readData();
    void writeData(const QByteArray &data);

private:
    QSerialPort m_serialPort;
    QByteArray m_data;

};



#endif //BATTLE_SPACE_SERIALWORKER_H

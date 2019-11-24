//パケットの中身を取得するクラスです。
#include "packet.h"

Packet::Packet(QObject *parent):QObject(parent)
{

}
Packet::Packet(const int number,
               const double time,
               const QString &source,
               const QString &dest,
               const QString &protocol,
               const QString length,
               QObject *packet):Packet(packet)
{
    this->number=number;
    this->time=time;
    this->source=source;
    this->dest=dest;
    this->protocol=protocol;
    this->length=length;
}
QString &Packet::getSource()
{
    return this->source;
}
QString &Packet::getDest()
{
    return this->dest;
}
QString &Packet::getProtocol()
{
    return this->protocol;
}
int Packet::getNumber()
{
    return this->number;
}
int Packet::getTime()
{
    return this->time;
}
QString &Packet::getLength()
{
    return this->length;
}

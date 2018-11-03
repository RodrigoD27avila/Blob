#ifndef INTERCEPTOR_H
#define INTERCEPTOR_H

#include <QtNetwork>

class Interceptor : public QTcpServer
{
public:
    Interceptor(qint16 port, QObject* parent = 0);
};

#endif // INTERCEPTOR_H

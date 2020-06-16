#ifndef AUTHEN_H
#define AUTHEN_H

#include <QtCore/QtGlobal>
#include <QObject>

class Authen
{
public:
    Authen();
    QString Hash_key(QString pw);
};

#endif // AUTHEN_H

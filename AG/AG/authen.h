#ifndef AUTHEN_H
#define AUTHEN_H

#include <QtCore/QtGlobal>
#include <QObject>
#include "QDebug"
#include "QtSql"
#include "QFileInfo"

class Authen
{
public:
    Authen();
    QString Hash_key(QString pw);
    void connectDB(void);
    static QSqlDatabase myDB;
    static int user_lv;
};

#endif // AUTHEN_H

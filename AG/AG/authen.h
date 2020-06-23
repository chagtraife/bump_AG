#ifndef AUTHEN_H
#define AUTHEN_H

#include <QtCore/QtGlobal>
#include <QObject>
#include "QDebug"
#include "QtSql"
#include "QFileInfo"
#ifdef Q_OS_IOS
#  include <QtPlugin>

Q_IMPORT_PLUGIN(SqliteCipherDriverPlugin)
#endif

#define CONNECTION_FAILED -1

class Authen
{
public:
    Authen();
    QString Hash_key(QString pw);
    void connectDB(void);
    int checkUser(QString pw);
    static QSqlDatabase myDB;
    static int user_lv;
};

#endif // AUTHEN_H

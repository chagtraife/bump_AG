#include "authen.h"
#define Path_to_DB "/db/Database_AG.db"
Authen::Authen()
{

}

QString Authen::Hash_key(QString pw)
{
    return pw;
}

void Authen::connectDB(void)
{
    auto path = QCoreApplication::applicationDirPath() + Path_to_DB;
    qDebug()<<path;
    myDB.setDatabaseName(path);
    QFileInfo checkFile(path);

    if (checkFile.isFile())
    {
        if (myDB.open()){
            qDebug("connected to DB");
        }else{
            qDebug("can't connected to DB");
        }

    }else{
        qDebug("no have file");
    }
}

QSqlDatabase Authen::myDB = QSqlDatabase::addDatabase("QSQLITE");

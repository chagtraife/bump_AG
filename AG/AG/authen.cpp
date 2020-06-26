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
    myDB.setPassword("9qca0n04");
    myDB.setConnectOptions("QSQLITE_USE_CIPHER=sqlcipher; QSQLITE_ENABLE_REGEXP");
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

    QSqlQuery query;
    query.exec("select ID, Password,Role  from Users");
    while (query.next()) {
        qDebug() << query.value(0).toInt() << ": " << query.value(1).toString()<< ":" <<query.value(2).toString();
    }
}
int Authen::checkUser(QString pw){
    QString role;
    qDebug() << QSqlDatabase::drivers();
     myDB = QSqlDatabase::addDatabase("SQLITECIPHER");
    auto path = QCoreApplication::applicationDirPath() + Path_to_DB;
    qDebug()<<path;
    myDB.setDatabaseName(path);
    myDB.setPassword("9qca0n04");
    myDB.setConnectOptions("QSQLITE_USE_CIPHER=sqlcipher; QSQLITE_ENABLE_REGEXP");
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

    QSqlQuery query;
//    query.exec("select ID, Password,Role  from Users");
//    while (query.next()) {
//        qDebug() << query.value(0).toInt() << ": " << query.value(1).toString()<< ":" <<query.value(2).toString();
//    }
    if (query.exec("SELECT ID, Password, Role, Threshold_Min, Threshold_Max FROM Users WHERE Password=\'"+pw+"\'")){
        if (query.next()){
            role = query.value(2).toString();
            threshold_min = query.value(3).toInt();
            threshold_max = query.value(4).toInt();
            qDebug()<<"min"<<threshold_min;
            qDebug()<<"max"<<threshold_max;
//            qDebug()<<;
        }
    }

//    qDebug()<<"threshold";
//    query.exec("select Min, Max from Set_threshold_Value");
//    while (query.next()) {
//        qDebug() << query.value(0).toInt() << ": " << query.value(1).toString();
//    }


    if(role == "admin"){
        return 1;
    }else if (role == "lv2"){
        return 2;
    }else if (role == "lv3"){
        return 3;
    } else{
        return 4;
    }
    return 4;
}


QSqlDatabase Authen::myDB;
int Authen::user_lv = 4;
int Authen::threshold_min = 0;
int Authen::threshold_max = 255;

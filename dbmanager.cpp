#include "dbmanager.h"

dbManager::dbManager()
{
    //Connects the database to the project
    tourDB = QSqlDatabase::addDatabase("QSQLITE");
    tourDB.setDatabaseName("C:/Users/wesleyc/Documents/data/Information_Database (1).db");
    if(!tourDB.open())
    {
        qDebug() << "\nError Opening Database\n";
    }

}

dbManager::~dbManager() {}

/************************************************************
 * loadCampusNamesOnly() - This function reads in the names
 * of the college campuses in the database using the "select
 * XXX from" query function. If there is an error occurs
 * while trying to access the database, a error warning is
 * printed to the console.
 * Returns: QSqlQueryModel pointer
 ************************************************************/
QSqlQueryModel* dbManager::loadCampusNamesOnly()
{
    QSqlQueryModel* model = new QSqlQueryModel();

    QString sQry = "select distStart as \"Campuses\" from Distances group by distStart;";
    QSqlQuery qry;
    qry.prepare(sQry);

    if(!qry.exec())
    {
        qDebug() << "\nError Loading Campuses\n";
    }

    model->setQuery(qry);
    return model;
}

/************************************************************
 * loadRemainingCampusNamesOnly() - This function reads in the
 * the remaining campus names from the database that the
 * user has not selected yet using the "select XXX from"
 * query function. The names of the selected colleges are held
 * in the parameter QString vector (campuses). If there is an
 * error occurs while trying to access the database, a error
 * warning is printed to the console.
 * Returns: QSqlQueryModel pointer
 ************************************************************/
QSqlQueryModel* dbManager::loadRemainingCampusNamesOnly(QVector<QString> campuses)
{
    QSqlQueryModel* model = new QSqlQueryModel();

    QString* p = campuses.begin();
    QString sQry = "select distStart as \"Campuses\" from Distances where not distStart = '" +*p+ "'";
    p++;
    while (p != campuses.end())
    {
        sQry += " and not distStart = '" +*p+ "'";
        p++;
    }
    sQry += " group by distStart;";
    QSqlQuery qry;
    qry.prepare(sQry);

    if(!qry.exec())
    {
        qDebug() << "\nError Loading Campuses\n";
    }

    model->setQuery(qry);
    return model;
}

/************************************************************
 * loadSelectedCampusNamesOnly() - This function reads in the
 * the select campus names from the database that the
 * user has selected using the "select XXX from" query
 * function. The names of the selected colleges are held
 * in the parameter QString vector (campuses). If there is an
 * error occurs while trying to access the database, a error
 * warning is printed to the console.
 * Returns: QSqlQueryModel pointer
 ************************************************************/
QSqlQueryModel* dbManager::loadSelectedCampusNamesOnly(QVector<QString> campuses)
{
    QSqlQueryModel* model = new QSqlQueryModel();

    QString* p = campuses.begin();
    QString sQry = "select distStart as \"Campuses\" from Distances where distStart = '" +*p+ "'";
    p++;
    while (p != campuses.end())
    {
        sQry += " or distStart = '" +*p+ "'";
        p++;
    }
    sQry += " group by distStart;";
    QSqlQuery qry;
    qry.prepare(sQry);

    if(!qry.exec())
    {
        qDebug() << "\nError Loading Campuses\n";
    }

    model->setQuery(qry);
    return model;
}

//Recursion
double dbManager::GetDistBtwn(QString start, QString end)
{
    double distBtwn = 0;
    QString sQry = "select distBtwn from Distances where distStart = '" +start+ "' and distEnd = '" +end+ "';";

    QSqlQuery qry;
    qry.prepare(sQry);
    qry.exec();

    if(qry.next())
    {
        distBtwn = qry.value(0).toDouble();
    }

    return distBtwn;
}




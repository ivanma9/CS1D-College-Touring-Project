#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QObject>
#include <QtSql>
#include <QVector>

class dbManager
{
public:
    dbManager();
    ~dbManager();

    /************************************************************
     * loadCampusNamesOnly() - This function reads in the names
     * of the college campuses in the database using the "select
     * XXX from" query function. If there is an error occurs
     * while trying to access the database, a error warning is
     * printed to the console.
     * Returns: QSqlQueryModel pointer
     ************************************************************/
    QSqlQueryModel *loadCampusNamesOnly();

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
    QSqlQueryModel *loadRemainingCampusNamesOnly(QVector<QString> campuses);

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
    QSqlQueryModel *loadSelectedCampusNamesOnly(QVector<QString> campuses);

    double GetDistBtwn(QString start, QString end);

private:
    QSqlDatabase tourDB; //Database variable
};

#endif // DBMANAGER_H

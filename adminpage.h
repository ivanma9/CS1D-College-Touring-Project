
#ifndef ADMINPAGE_H
#define ADMINPAGE_H

#include <QMainWindow>
#include "ui_adminpage.h"
#include "dbmanager.h"
#include "dbadminmanager.h"
#include <QtSql>
#include <QSqlQuery>
#include <QMessageBox>
#include <QInputDialog>
#include <QIntValidator>

namespace Ui {
class adminpage;
}

class adminpage : public QMainWindow
{
    Q_OBJECT

public:
    explicit adminpage(QWidget *parent = nullptr);
    ~adminpage();

    void setupConnections();

    /************************************************************
     * changeToAdminHomePage() - This function switches
     * the ui widgets. For this one, it changes to the
     * Admin home page. (By Wesley Chok)
     * **********************************************************/
    void changeToAdminHomePage();

    /************************************************************
     * changeToSouvenirPage() - This function switches
     * the ui widgets. For this one, it changes to the change
     * the Souvenir page. (By Wesley Chok)
     * **********************************************************/
    void changeToSouvenirPage();

    /************************************************************
     * changeToSouvenirPricePage() - This function switches
     * the ui widgets. For this one, it changes to the change
     * the Souvenir price page. (By Wesley Chok)
     * **********************************************************/
    void changeToSouvenirPricePage();

    void changeToSouvenirDeletePage();

    void showNewCampusSouvenirListView(QSqlQueryModel *model);

    void showSelectedSouvenirsListView(QSqlQueryModel *model);

    void showSouvenirTableViewDeletePage(QSqlQueryModel *model);

    void showSouvenirComboBoxDeletePage(QSqlQueryModel *model);

    void showCampusComboBoxAddPage(QSqlQueryModel * model);

    void showchangeSouvenirPageCampusNameComboBox(QSqlQueryModel * model);



private slots:

    void on_viewDistancesBtn_clicked();

    void on_viewSouvenirBtn_clicked();

    //*********************************************START OF STORY POINT 7A******************************************************//
    /************************************************************
    * on_addCampusAndSouvenirBtn_clicked() - This function allows
    * the user to go to the add Campus and Souvenir page through
    * a ui push button. To accommodate for the values in the
    * combo box on the Campus and Souvenir page, it calls
    * the loadSouvenirsOnly() function in dbadminmanager.cpp
    * through the showSouvenirsInComboBox function. (By Wesley Chok)
    * **********************************************************/
    void on_addCampusThroughInputFile_clicked();

    void on_addSouvenirThroughInputFile_clicked();

    //*********************************************END OF STORY POINT 7A******************************************************//



    //*********************************************START OF STORY POINT 7B******************************************************//
    void on_changeSouvPriceBackBtn_clicked();

    /************************************************************
     * on_changeSouvenirPriceBtn_clicked() - This function allows
     * the user to go to the change the Souvenir price page. It
     * sets the current widget to the changeSouvenirPricePage.
     * (By Wesley Chok)
     * **********************************************************/
    void on_changeSouvenirPriceBtn_clicked();

    /************************************************************
     * on_changeSouvenirPriceBtn_clicked() - This function
     * allows the user to change the Souvenir price on the database.
     * The QString variable souvTrad is set equal to the souvPrice
     * ChangeName_line line edit and QString variabel souvPrice is
     * set equal to the souvChangePrice_line line edit ui texts.
     * The bool variable check is used to error check the line
     * edits and is set equal to false. The for loop
     * checks the lenght of the souvPrice entry and the if statement
     * is used to check if the souvPrice entry are numbers or '.'.
     * If this is true then check will be initiliazed to true and
     * break. If the bool variable check is equal to true then it
     * will output a QMessageBox about "Invalid Input There was
     * an invalid input. Please use only Numerals(0-9) and the . ".
     * The QSqlQuery qry variable prepare is used to update the
     * Souvenirs that is set to souvTrad equal to the QString
     * variable souvTrad and souvCost equal to the QString
     * souvPrice variable where souvTrad is equal to the QString
     * variable souvTrad. If qry is executed properly then
     * it will output a QMessageBox about "Updated". Else it will
     * output a QMessageBox critical "error" with the last error.
     * **********************************************************/
    void on_updateSouvenirPriceBtn_clicked();
    //*********************************************END OF STORY POINT 7B******************************************************//




    //*********************************************START OF STORY POINT 7C******************************************************//
    /************************************************************
     * on_addSouvenirBtn_clicked() - This function allows the user
     * to go to the add Souvenir page. The widget will be then set
     * to addSouvenirPage widget. (By Wesley Chok)
     * **********************************************************/
    void on_addSouvenirBtn_clicked();
    //*********************************************END OF STORY POINT 7C******************************************************//




    //*********************************************START OF STORY POINT 7D******************************************************//
    /************************************************************
     * on_deleteSouvenirBtn_clicked() - This function allows
     * the user to delete a Souvenir item that exists on the
     * Souvenir database. The QSqlQuery variable data is used
     * to access and delete items from the database. QString
     * variable deleteSouvenir is set equal to the value inputted
     * in the QInputDialog getText() function. The QSqlQuery
     * variable data then prepares to delete the item in Souvenir
     * where souvTrad equals the QString variable deleteSouvenir.
     * If the data is executed is equal to true then the QMessage
     * Box about outputs "The item was deleted. Double check
     * if an error occured". Finally, the widget is set to the
     * adminHomePage. (By Wesley Chok)
     * **********************************************************/
    void on_deleteSouvenirBtn_clicked();

    /************************************************************
     * on_createSouvenirBtn_clicked() - This function allows the user
     * to create their desired souvenir. QSqlQuery variable data
     * is used to access and insert contents of the desired database.
     * QString souvName is set equal to the souvName_line line edit
     * and QStirng souvPrice is set equal to the souvPrice_line edit
     * ui texts. The bool variable check is used to error check
     * the line edits and is set equal to false. The for loop
     * checks the lenght of the souvPrice entry and the if statement
     * is used to check if the souvPrice entry are numbers or '.'.
     * If this is true then check will be initiliazed to true and
     * break. If the bool variable check is equal to true then it
     * will output a QMessageBox about "Invalid Input There was
     * an invalid input. Please use only Numerals(0-9) and the . ".
     * Thus, the QSqlQuery variable data will prepare to insert
     * into the database Souvenirs into the values souvTrad and
     * souvCost using the QString variables souvTrad and souvCost.
     * If the data is executed properly, the it will say "Item was
     * added. Double check if an error occured.". Else, it
     * will output a QMessageBox about "Error Database not found
     * double check path to database!". Lastly, it the widget
     * will be set to the adminHomePage. (By Wesley Chok)
     * **********************************************************/
    void on_createSouvenirBtn_clicked();


    void on_deletePageBackBtn_clicked();

    void on_deleteSouvenirConfirmBtn_clicked();





    //*********************************************END OF STORY POINT 7D******************************************************//




private:
    Ui::adminpage *ui;
    dbAdminManager database;
    dbManager database_;

    QVector<QString> selectedSouvenirs;

    QVector<QString> selectedCampuses;
};
#endif // ADMINPAGE_H

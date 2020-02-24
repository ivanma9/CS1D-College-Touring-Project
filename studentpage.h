#ifndef STUDENTPAGE_H
#define STUDENTPAGE_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlQuery>
#include <QInputDialog>
#include <QIntValidator>

#include "dbmanager.h"

namespace Ui {
class studentpage;
}

class studentpage : public QMainWindow
{
    Q_OBJECT

public:
    explicit studentpage(QWidget *parent = nullptr);
    ~studentpage();

    //START COLLEGE TOUR STUDENT PAGE
    /************************************************************
     * showStartAvaliListView() - Using a QSqlQueryModel pointer,
     * the start screen Avaliable Campuses list view will
     * display the information held in the model
     ************************************************************/
    void showStartAvaliListView(QSqlQueryModel *model);

    /************************************************************
     * showStartAvaliCombo() - Using a QSqlQueryModel pointer,
     * the start screen Avaliable Campuses combo box will
     * display the information held in the model
     ************************************************************/
    void showStartAvaliListCombo(QSqlQueryModel *model);

    //COLLEGE TOUR STUDENT PAGE
    /************************************************************
     * showAvaliListView() - Using a QSqlQueryModel pointer,
     * the main tour planning screen Avaliable Campuses list view
     * will display the information held in the model
     ************************************************************/
    void showAvaliListView(QSqlQueryModel *model);

    /************************************************************
     * showSelectListView() - Using a QSqlQueryModel pointer,
     * the main tour planning screen Selected Campuses list view
     * will display the information held in the model
     ************************************************************/
    void showSelectListView(QSqlQueryModel *model);

    /************************************************************
     * showAvaliListCombo() - Using a QSqlQueryModel pointer,
     * the main tour planning screen Avaliable Campuses combo box
     * will display the information held in the model
     ************************************************************/
    void showAvaliListCombo(QSqlQueryModel *model);

    /************************************************************
     * recursiveCollegeSort() - Recursive college sort that
     * creates the optimal college touring trip plan. For example,
     * if the trip started at Arizona State University, you would
     * visit the next closest campus to ASU, then the next closest
     * after that, and so on. Each recursive call finds the
     * closest college to visit, excluding ones that have already
     * been visited. The base case of the recursive function is
     * when the vector of selected colleges is empty (there are
     * no more colleges to visit).
     ************************************************************/
    void recursiveCollegeSort(QString currentCamp);

    /************************************************************
     * calcTotalDist() - calculates the total distance travel
     * during the college tour using the sorted campus tour plan
     ************************************************************/
    void calcTotalDist();

private slots:
    //START COLLEGE TOUR STUDENT PAGE
    /************************************************************
     * on_enter_button_1_clicked() - After the user has selected
     * this starting campus using the combo box, the enter button
     * is clicked. When button is clicked, the combo box text is
     * saved as a QString and pushed into a vector to hold their
     * selected campuses. Then, the program moves onto the main
     * college tour campus selection screen so the student can
     * continue (leaves start screen).
     ************************************************************/
    void on_enter_button_1_clicked();

    /************************************************************
     * on_back_button_clicked() - When the back button is clicked,
     * the window is closed.
     ************************************************************/
    void on_back_button_clicked();

    //COLLEGE TOUR STUDENT PAGE
    /************************************************************
     * on_enter_button_2_clicked() - After the user has selected
     * the next campus using the combo box, the enter button
     * is clicked. When button is clicked, the combo box text is
     * saved as a QString and pushed into a vector to hold their
     * selected campuses. The chooses is pushed to the back, like
     * a queue. If there are no more campuses to select, a
     * QMessageBox is shown to warn the user to click done to
     * finish. The screen's list views and combo will refresh to
     * correspond to the user's choices.
     ************************************************************/
    void on_enter_button_2_clicked();

    /************************************************************
     * on_done_button_clicked() - Sorts and sends to a rough sort
     * ui
     ************************************************************/
    void on_done_button_clicked();

    /************************************************************
     * on_viewCampusBtn_clicked() - This button displays the
     * Distances database table onto the UI table view. The
     * QSqlQuery pointer variable view is used to determine which
     * database table we want to use. After this, the table gets
     * outtputed by the QSqlQueryModel pointer variable model.
     ************************************************************/
    void on_viewCampusBtn_clicked();

private:
    QVector<QString> selectedCampuses; //vector of selected campuses
    QVector<QString> sortedCampuses; //vector of the sorted campuses
    double tourDist; //total distance traveled
    Ui::studentpage *ui; //studentpage ui variable
    dbManager database; //dbManager variable
};

#endif // STUDENTPAGE_H

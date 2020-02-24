#include "studentpage.h"
#include <QMessageBox>
#include <QComboBox>
#include "ui_studentpage.h"

studentpage::studentpage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::studentpage)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentWidget(ui->startCollegeTour);
    //Populates the start screen Avaliable Campuses list view with the names of the campuses
    showStartAvaliListView(database.loadCampusNamesOnly());
    //Populates the start screen Avaliable Campuses combo box with the names of the campuses
    showStartAvaliListCombo(database.loadCampusNamesOnly());

}

studentpage::~studentpage()
{
    delete ui;
}

//START COLLEGE TOUR STUDENT PAGE
/************************************************************
 * showStartAvaliListView() - Using a QSqlQueryModel pointer,
 * the start screen Avaliable Campuses list view will
 * display the information held in the model
 ************************************************************/
void studentpage::showStartAvaliListView(QSqlQueryModel *model)
{
    ui->start_listView->setModel(model);
}

/************************************************************
 * showStartAvaliCombo() - Using a QSqlQueryModel pointer,
 * the start screen Avaliable Campuses combo box will
 * display the information held in the model
 ************************************************************/
void studentpage::showStartAvaliListCombo(QSqlQueryModel *model)
{
    ui->start_combo->setModel(model);
}

/************************************************************
 * on_enter_button_1_clicked() - After the user has selected
 * this starting campus using the combo box, the enter button
 * is clicked. When button is clicked, the combo box text is
 * saved as a QString and pushed into a vector to hold their
 * selected campuses. Then, the program moves onto the main
 * college tour campus selection screen so the student can
 * continue (leaves start screen).
 ************************************************************/
void studentpage::on_enter_button_1_clicked()
{
    //Students choice is saved into the vector
    QString campus = ui->start_combo->currentText();
    selectedCampuses.push_back(campus);

    //The program leaves the start screen to the main tour planning screen
    ui->stackedWidget->setCurrentWidget(ui->collegeTour);

    //Populates the main tour planning screen Avaliable Campuses list view with the names of the campuses
    showAvaliListView(database.loadRemainingCampusNamesOnly(selectedCampuses));
    //Populates the main tour planning screen Selected Campus list view with the names of the campueses
    showSelectListView(database.loadSelectedCampusNamesOnly(selectedCampuses));
    //Populates the main tour planning screen Avaliable Campuses combo box with the names of the campuses
    showAvaliListCombo(database.loadRemainingCampusNamesOnly(selectedCampuses));
}

/************************************************************
 * on_back_button_clicked() - When the back button is clicked,
 * the window is closed.
 ************************************************************/
void studentpage::on_back_button_clicked()
{
    studentpage::close();
}

//COLLEGE TOUR STUDENT PAGE
/************************************************************
 * showAvaliListView() - Using a QSqlQueryModel pointer,
 * the main tour planning screen Avaliable Campuses list view
 * will display the information held in the model
 ************************************************************/
void studentpage::showAvaliListView(QSqlQueryModel *model)
{
    ui->avali_listView->setModel(model);
}

/************************************************************
 * showSelectListView() - Using a QSqlQueryModel pointer,
 * the main tour planning screen Selected Campuses list view
 * will display the information held in the model
 ************************************************************/
void studentpage::showSelectListView(QSqlQueryModel *model)
{
    ui->select_listView->setModel(model);
}

/************************************************************
 * showAvaliListCombo() - Using a QSqlQueryModel pointer,
 * the main tour planning screen Avaliable Campuses combo box
 * will display the information held in the model
 ************************************************************/
void studentpage::showAvaliListCombo(QSqlQueryModel *model)
{
    ui->next_combo->setModel(model);
}

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
void studentpage::on_enter_button_2_clicked()
{
    QString campus = ui->next_combo->currentText();
    //No campuses
    if(campus == "")
    {
        QMessageBox::warning(this, "ERROR", "NO MORE CAMPUSES! PLEASE CLICK DONE!", QMessageBox::Ok, QMessageBox::NoButton);
    }
    //Campuses remain
    else
    {
        //Pushes newly selected campus to the back of the vector
        selectedCampuses.push_back(campus);
        //Refreshes list views and combo box
        showAvaliListView(database.loadRemainingCampusNamesOnly(selectedCampuses));
        showSelectListView(database.loadSelectedCampusNamesOnly(selectedCampuses));
        showAvaliListCombo(database.loadRemainingCampusNamesOnly(selectedCampuses));
    }
}

/************************************************************
 * on_done_button_clicked() - Sorts and sends to a rough sort
 * ui
 ************************************************************/
void studentpage::on_done_button_clicked()
{
    QString start = *selectedCampuses.begin();
    sortedCampuses.push_back(start);
    selectedCampuses.removeFirst();
    recursiveCollegeSort(start);

    QString* p = sortedCampuses.begin();
    while(p != sortedCampuses.end())
    {
        qDebug() << *p;
        p++;
    }
    calcTotalDist();
    qDebug() << tourDist;

    ui->stackedWidget->setCurrentWidget(ui->SortCollegeTour);
    ui->sort_listView->setModel(new QStringListModel(QList<QString>::fromVector(sortedCampuses)));
    QString tourDistStr = QString::number(tourDist);
    ui->total_dist_line->setText(tourDistStr);
}

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
void studentpage::recursiveCollegeSort(QString currentCamp)
{
   if(selectedCampuses.isEmpty())
   {
       return;
   }
   else
   {
        QString* otherCamp = selectedCampuses.begin();
        int currentIndex = 0;

        double leastDist = database.GetDistBtwn(currentCamp, *otherCamp);
        int leastIndex = 0;

        otherCamp++;
        currentIndex++;

        while(otherCamp != selectedCampuses.end())
        {
            double currentDist = database.GetDistBtwn(currentCamp, *otherCamp);
            if (currentDist < leastDist)
            {
                leastDist = currentDist;
                leastIndex = currentIndex;
            }
            else
            {
                otherCamp++;
                currentIndex++;
            }
        }

        QString nextCamp = selectedCampuses.at(leastIndex);

        sortedCampuses.push_back(selectedCampuses.at(leastIndex));
        selectedCampuses.remove(leastIndex);

        recursiveCollegeSort(nextCamp);
   }
}

/************************************************************
 * calcTotalDist() - calculates the total distance travel
 * during the college tour using the sorted campus tour plan
 ************************************************************/
void studentpage::calcTotalDist()
{
    tourDist = 0;
    QString* start = sortedCampuses.begin();
    QString* end = sortedCampuses.begin() + 1;
    while(end != sortedCampuses.end())
    {
        double currentDistBtwn = database.GetDistBtwn(*start, *end);
        tourDist += currentDistBtwn;
        start++;
        end++;
    }
}



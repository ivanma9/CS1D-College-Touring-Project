#include "adminpage.h"
#include "QDebug"
#include <iostream>
#include <string>

adminpage::adminpage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::adminpage)
{
    ui->setupUi(this);
    // Sets default page to be the home page
//    ui->stackedWidget->setCurrentWidget(ui->AdminPage);
}

adminpage::~adminpage()
{
    delete ui;
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include <QMessageBox>
#include <QFont>
#include "QDebug"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loginButton_clicked()
{
    if(ui->UserLineEdit->text() == "admin" && ui->PWLineEdit->text() == "potato")
    {
        //ADMIN PAGE
        //PUT ADMIN PAGE HERE
//       QMessageBox::information(this, "Access Granted", "Admin: CORRECT LOGIN", QMessageBox::Ok, QMessageBox::NoButton);
       qDebug() << "Access Granted!";
       adminObj.show();
    }
    else
       QMessageBox::critical(this, "Access Denied", "INCORRECT LOGIN", QMessageBox::Ok, QMessageBox::NoButton);

}

void MainWindow::on_clearButton_clicked()
{
    ui->UserLineEdit->setText("");
    ui->PWLineEdit->setText("");

}


void MainWindow::on_pushButton_clicked()
{
    //STUDENT PAGE
    //PUT STUDENT PAGE HERE
//    QMessageBox::information(this, "Access Granted", "STUDENT", QMessageBox::Ok, QMessageBox::NoButton);
    qDebug() << "Access Granted! Welcome to College Tours!";
    studentObj.show();
}

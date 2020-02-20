#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFont>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFont headingFont;
    headingFont.setPointSize(10);
    headingFont.setBold(true);
    ui->adminLabel->setFont(headingFont);
    ui->studentLabel->setFont(headingFont);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_loginButton_clicked()
{
    if(ui->UserLineEdit->text() == "admin" && ui->PWLineEdit->text() == "potato")
    {
       QMessageBox::information(this, "Access Granted", "Admin: CORRECT LOGIN", QMessageBox::Ok, QMessageBox::NoButton);

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
    QMessageBox::information(this, "Access Granted", "STUDENT", QMessageBox::Ok, QMessageBox::NoButton);

}

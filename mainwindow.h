#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "studentpage.h"
#include "adminpage.h"
#include <QMessageBox>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_loginButton_clicked();

    void on_clearButton_clicked();

    void on_pushButton_clicked();

//private slots:

private:
    Ui::MainWindow *ui;
    studentpage studentObj;
    adminpage adminObj;

};
#endif // MAINWINDOW_H

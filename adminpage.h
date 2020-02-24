
#ifndef ADMINPAGE_H
#define ADMINPAGE_H

#include <QMainWindow>
#include "ui_adminpage.h"
#include "dbmanager.h"
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

private slots:

private:
Ui::adminpage *ui;
};
#endif // ADMINPAGE_H

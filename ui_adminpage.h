/********************************************************************************
** Form generated from reading UI file 'adminpage.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINPAGE_H
#define UI_ADMINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_adminpage
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *adminpage)
    {
        if (adminpage->objectName().isEmpty())
            adminpage->setObjectName(QString::fromUtf8("adminpage"));
        adminpage->resize(800, 600);
        centralwidget = new QWidget(adminpage);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 40, 121, 81));
        adminpage->setCentralWidget(centralwidget);
        menubar = new QMenuBar(adminpage);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        adminpage->setMenuBar(menubar);
        statusbar = new QStatusBar(adminpage);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        adminpage->setStatusBar(statusbar);

        retranslateUi(adminpage);

        QMetaObject::connectSlotsByName(adminpage);
    } // setupUi

    void retranslateUi(QMainWindow *adminpage)
    {
        adminpage->setWindowTitle(QCoreApplication::translate("adminpage", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("adminpage", "Admin Page", nullptr));
    } // retranslateUi

};

namespace Ui {
    class adminpage: public Ui_adminpage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINPAGE_H

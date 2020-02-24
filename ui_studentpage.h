/********************************************************************************
** Form generated from reading UI file 'studentpage.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTPAGE_H
#define UI_STUDENTPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_studentpage
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *collegeTour;
    QLabel *next_label;
    QPushButton *done_button;
    QPushButton *enter_button_2;
    QListView *select_listView;
    QListView *avali_listView;
    QLabel *avali_label_2;
    QLabel *select_label;
    QComboBox *next_combo;
    QWidget *startCollegeTour;
    QLabel *start_label;
    QPushButton *enter_button_1;
    QPushButton *back_button;
    QLabel *avali_label_1;
    QListView *start_listView;
    QComboBox *start_combo;
    QWidget *SortCollegeTour;
    QListView *sort_listView;
    QLineEdit *total_dist_line;
    QLabel *total_dist_label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *studentpage)
    {
        if (studentpage->objectName().isEmpty())
            studentpage->setObjectName(QString::fromUtf8("studentpage"));
        studentpage->resize(895, 600);
        centralwidget = new QWidget(studentpage);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(20, 40, 831, 491));
        collegeTour = new QWidget();
        collegeTour->setObjectName(QString::fromUtf8("collegeTour"));
        next_label = new QLabel(collegeTour);
        next_label->setObjectName(QString::fromUtf8("next_label"));
        next_label->setGeometry(QRect(40, 380, 101, 31));
        done_button = new QPushButton(collegeTour);
        done_button->setObjectName(QString::fromUtf8("done_button"));
        done_button->setGeometry(QRect(290, 430, 112, 34));
        enter_button_2 = new QPushButton(collegeTour);
        enter_button_2->setObjectName(QString::fromUtf8("enter_button_2"));
        enter_button_2->setGeometry(QRect(150, 430, 112, 34));
        select_listView = new QListView(collegeTour);
        select_listView->setObjectName(QString::fromUtf8("select_listView"));
        select_listView->setGeometry(QRect(430, 60, 361, 311));
        avali_listView = new QListView(collegeTour);
        avali_listView->setObjectName(QString::fromUtf8("avali_listView"));
        avali_listView->setEnabled(true);
        avali_listView->setGeometry(QRect(40, 60, 361, 311));
        avali_label_2 = new QLabel(collegeTour);
        avali_label_2->setObjectName(QString::fromUtf8("avali_label_2"));
        avali_label_2->setGeometry(QRect(40, 30, 151, 20));
        select_label = new QLabel(collegeTour);
        select_label->setObjectName(QString::fromUtf8("select_label"));
        select_label->setGeometry(QRect(430, 30, 151, 20));
        next_combo = new QComboBox(collegeTour);
        next_combo->setObjectName(QString::fromUtf8("next_combo"));
        next_combo->setGeometry(QRect(150, 390, 251, 26));
        stackedWidget->addWidget(collegeTour);
        startCollegeTour = new QWidget();
        startCollegeTour->setObjectName(QString::fromUtf8("startCollegeTour"));
        start_label = new QLabel(startCollegeTour);
        start_label->setObjectName(QString::fromUtf8("start_label"));
        start_label->setGeometry(QRect(40, 390, 131, 20));
        enter_button_1 = new QPushButton(startCollegeTour);
        enter_button_1->setObjectName(QString::fromUtf8("enter_button_1"));
        enter_button_1->setGeometry(QRect(170, 430, 112, 34));
        back_button = new QPushButton(startCollegeTour);
        back_button->setObjectName(QString::fromUtf8("back_button"));
        back_button->setGeometry(QRect(290, 430, 112, 34));
        avali_label_1 = new QLabel(startCollegeTour);
        avali_label_1->setObjectName(QString::fromUtf8("avali_label_1"));
        avali_label_1->setGeometry(QRect(40, 30, 151, 20));
        start_listView = new QListView(startCollegeTour);
        start_listView->setObjectName(QString::fromUtf8("start_listView"));
        start_listView->setGeometry(QRect(40, 60, 361, 311));
        start_combo = new QComboBox(startCollegeTour);
        start_combo->setObjectName(QString::fromUtf8("start_combo"));
        start_combo->setGeometry(QRect(170, 390, 231, 26));
        stackedWidget->addWidget(startCollegeTour);
        SortCollegeTour = new QWidget();
        SortCollegeTour->setObjectName(QString::fromUtf8("SortCollegeTour"));
        sort_listView = new QListView(SortCollegeTour);
        sort_listView->setObjectName(QString::fromUtf8("sort_listView"));
        sort_listView->setGeometry(QRect(30, 20, 411, 341));
        total_dist_line = new QLineEdit(SortCollegeTour);
        total_dist_line->setObjectName(QString::fromUtf8("total_dist_line"));
        total_dist_line->setGeometry(QRect(212, 430, 211, 25));
        total_dist_label = new QLabel(SortCollegeTour);
        total_dist_label->setObjectName(QString::fromUtf8("total_dist_label"));
        total_dist_label->setGeometry(QRect(58, 430, 121, 20));
        stackedWidget->addWidget(SortCollegeTour);
        studentpage->setCentralWidget(centralwidget);
        menubar = new QMenuBar(studentpage);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 895, 30));
        studentpage->setMenuBar(menubar);
        statusbar = new QStatusBar(studentpage);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        studentpage->setStatusBar(statusbar);

        retranslateUi(studentpage);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(studentpage);
    } // setupUi

    void retranslateUi(QMainWindow *studentpage)
    {
        studentpage->setWindowTitle(QCoreApplication::translate("studentpage", "MainWindow", nullptr));
        next_label->setText(QCoreApplication::translate("studentpage", "Next Campus", nullptr));
        done_button->setText(QCoreApplication::translate("studentpage", "Done", nullptr));
        enter_button_2->setText(QCoreApplication::translate("studentpage", "Enter", nullptr));
        avali_label_2->setText(QCoreApplication::translate("studentpage", "Avaliable Campuses", nullptr));
        select_label->setText(QCoreApplication::translate("studentpage", "Selected Campuses", nullptr));
        start_label->setText(QCoreApplication::translate("studentpage", "Starting Campus", nullptr));
        enter_button_1->setText(QCoreApplication::translate("studentpage", "Enter", nullptr));
        back_button->setText(QCoreApplication::translate("studentpage", "Back", nullptr));
        avali_label_1->setText(QCoreApplication::translate("studentpage", "Avaliable Campuses", nullptr));
        total_dist_label->setText(QCoreApplication::translate("studentpage", "Total Distance", nullptr));
    } // retranslateUi

};

namespace Ui {
    class studentpage: public Ui_studentpage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTPAGE_H

/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon Oct 20 08:33:09 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionImport_data_files;
    QAction *actionSave_chart;
    QAction *actionExit;
    QAction *actionContent;
    QAction *actionContact;
    QAction *actionDocumentation;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QCustomPlot *customPlot;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_GPS;
    QGridLayout *gridLayout_6;
    QLineEdit *lineEdit_GPS;
    QGroupBox *groupBox_GPS_CORR;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_GPS_CORR;
    QGroupBox *groupBox_Altimeter;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_Altimeter;
    QGroupBox *groupBox_Barometer;
    QGridLayout *gridLayout_4;
    QLineEdit *lineEdit_Barometer;
    QGroupBox *groupBox_Time;
    QGridLayout *gridLayout_7;
    QLineEdit *lineEdit_Time;
    QGroupBox *groupBox_Date;
    QGridLayout *gridLayout_5;
    QLineEdit *lineEdit_Date;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1142, 690);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8("place_icon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionImport_data_files = new QAction(MainWindow);
        actionImport_data_files->setObjectName(QString::fromUtf8("actionImport_data_files"));
        actionSave_chart = new QAction(MainWindow);
        actionSave_chart->setObjectName(QString::fromUtf8("actionSave_chart"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionContent = new QAction(MainWindow);
        actionContent->setObjectName(QString::fromUtf8("actionContent"));
        actionContact = new QAction(MainWindow);
        actionContact->setObjectName(QString::fromUtf8("actionContact"));
        actionDocumentation = new QAction(MainWindow);
        actionDocumentation->setObjectName(QString::fromUtf8("actionDocumentation"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        customPlot = new QCustomPlot(centralWidget);
        customPlot->setObjectName(QString::fromUtf8("customPlot"));

        horizontalLayout->addWidget(customPlot);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(100, -1, 100, -1);
        groupBox_GPS = new QGroupBox(centralWidget);
        groupBox_GPS->setObjectName(QString::fromUtf8("groupBox_GPS"));
        groupBox_GPS->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_GPS->sizePolicy().hasHeightForWidth());
        groupBox_GPS->setSizePolicy(sizePolicy1);
        QPalette palette;
        QBrush brush(QColor(255, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        groupBox_GPS->setPalette(palette);
        gridLayout_6 = new QGridLayout(groupBox_GPS);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        lineEdit_GPS = new QLineEdit(groupBox_GPS);
        lineEdit_GPS->setObjectName(QString::fromUtf8("lineEdit_GPS"));
        sizePolicy1.setHeightForWidth(lineEdit_GPS->sizePolicy().hasHeightForWidth());
        lineEdit_GPS->setSizePolicy(sizePolicy1);

        gridLayout_6->addWidget(lineEdit_GPS, 0, 0, 1, 1);


        verticalLayout->addWidget(groupBox_GPS);

        groupBox_GPS_CORR = new QGroupBox(centralWidget);
        groupBox_GPS_CORR->setObjectName(QString::fromUtf8("groupBox_GPS_CORR"));
        groupBox_GPS_CORR->setEnabled(true);
        sizePolicy1.setHeightForWidth(groupBox_GPS_CORR->sizePolicy().hasHeightForWidth());
        groupBox_GPS_CORR->setSizePolicy(sizePolicy1);
        gridLayout = new QGridLayout(groupBox_GPS_CORR);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit_GPS_CORR = new QLineEdit(groupBox_GPS_CORR);
        lineEdit_GPS_CORR->setObjectName(QString::fromUtf8("lineEdit_GPS_CORR"));

        gridLayout->addWidget(lineEdit_GPS_CORR, 0, 0, 1, 1);

        groupBox_GPS->raise();
        lineEdit_GPS_CORR->raise();

        verticalLayout->addWidget(groupBox_GPS_CORR);

        groupBox_Altimeter = new QGroupBox(centralWidget);
        groupBox_Altimeter->setObjectName(QString::fromUtf8("groupBox_Altimeter"));
        sizePolicy1.setHeightForWidth(groupBox_Altimeter->sizePolicy().hasHeightForWidth());
        groupBox_Altimeter->setSizePolicy(sizePolicy1);
        QPalette palette1;
        QBrush brush2(QColor(0, 0, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        groupBox_Altimeter->setPalette(palette1);
        verticalLayout_2 = new QVBoxLayout(groupBox_Altimeter);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lineEdit_Altimeter = new QLineEdit(groupBox_Altimeter);
        lineEdit_Altimeter->setObjectName(QString::fromUtf8("lineEdit_Altimeter"));

        verticalLayout_2->addWidget(lineEdit_Altimeter);


        verticalLayout->addWidget(groupBox_Altimeter);

        groupBox_Barometer = new QGroupBox(centralWidget);
        groupBox_Barometer->setObjectName(QString::fromUtf8("groupBox_Barometer"));
        sizePolicy1.setHeightForWidth(groupBox_Barometer->sizePolicy().hasHeightForWidth());
        groupBox_Barometer->setSizePolicy(sizePolicy1);
        QPalette palette2;
        QBrush brush3(QColor(0, 170, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        groupBox_Barometer->setPalette(palette2);
        gridLayout_4 = new QGridLayout(groupBox_Barometer);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        lineEdit_Barometer = new QLineEdit(groupBox_Barometer);
        lineEdit_Barometer->setObjectName(QString::fromUtf8("lineEdit_Barometer"));

        gridLayout_4->addWidget(lineEdit_Barometer, 0, 0, 1, 1);


        verticalLayout->addWidget(groupBox_Barometer);

        groupBox_Time = new QGroupBox(centralWidget);
        groupBox_Time->setObjectName(QString::fromUtf8("groupBox_Time"));
        sizePolicy1.setHeightForWidth(groupBox_Time->sizePolicy().hasHeightForWidth());
        groupBox_Time->setSizePolicy(sizePolicy1);
        gridLayout_7 = new QGridLayout(groupBox_Time);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        lineEdit_Time = new QLineEdit(groupBox_Time);
        lineEdit_Time->setObjectName(QString::fromUtf8("lineEdit_Time"));

        gridLayout_7->addWidget(lineEdit_Time, 0, 0, 1, 1);


        verticalLayout->addWidget(groupBox_Time);

        groupBox_Date = new QGroupBox(centralWidget);
        groupBox_Date->setObjectName(QString::fromUtf8("groupBox_Date"));
        sizePolicy1.setHeightForWidth(groupBox_Date->sizePolicy().hasHeightForWidth());
        groupBox_Date->setSizePolicy(sizePolicy1);
        gridLayout_5 = new QGridLayout(groupBox_Date);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        lineEdit_Date = new QLineEdit(groupBox_Date);
        lineEdit_Date->setObjectName(QString::fromUtf8("lineEdit_Date"));

        gridLayout_5->addWidget(lineEdit_Date, 0, 0, 1, 1);


        verticalLayout->addWidget(groupBox_Date);


        horizontalLayout->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1142, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionImport_data_files);
        menuFile->addAction(actionSave_chart);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuHelp->addAction(actionContent);
        menuHelp->addAction(actionContact);
        menuHelp->addSeparator();
        menuHelp->addAction(actionDocumentation);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Altitude Sensors Comparison", 0, QApplication::UnicodeUTF8));
        actionImport_data_files->setText(QApplication::translate("MainWindow", "Import data files", 0, QApplication::UnicodeUTF8));
        actionSave_chart->setText(QApplication::translate("MainWindow", "Save chart", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        actionContent->setText(QApplication::translate("MainWindow", "Content", 0, QApplication::UnicodeUTF8));
        actionContact->setText(QApplication::translate("MainWindow", "Contact", 0, QApplication::UnicodeUTF8));
        actionDocumentation->setText(QApplication::translate("MainWindow", "Documentation", 0, QApplication::UnicodeUTF8));
        groupBox_GPS->setTitle(QApplication::translate("MainWindow", "GPS", 0, QApplication::UnicodeUTF8));
        groupBox_GPS_CORR->setTitle(QApplication::translate("MainWindow", "GPS - Corrected", 0, QApplication::UnicodeUTF8));
        groupBox_Altimeter->setTitle(QApplication::translate("MainWindow", "Altimeter", 0, QApplication::UnicodeUTF8));
        groupBox_Barometer->setTitle(QApplication::translate("MainWindow", "Barometer", 0, QApplication::UnicodeUTF8));
        groupBox_Time->setTitle(QApplication::translate("MainWindow", "Time", 0, QApplication::UnicodeUTF8));
        groupBox_Date->setTitle(QApplication::translate("MainWindow", "Date", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

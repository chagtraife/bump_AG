/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout;
    QAction *actionAboutQt;
    QAction *actionConnect;
    QAction *actionDisconnect;
    QAction *actionConfigure;
    QAction *actionClear;
    QAction *actionQuit;
    QAction *actionUser;
    QAction *actionDMX_monitor;
    QAction *actionDMX_monitor_2;
    QAction *actionUser_Manager;
    QAction *actionThreshold_Manager;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGroupBox *Functions;
    QVBoxLayout *verticalLayout_3;
    QPushButton *BtnDeviceDiscovery;
    QPushButton *BtnSearchDev;
    QPushButton *BtnReadDMXID;
    QPushButton *BtnWrDMXID;
    QPushButton *BtnWriteUID;
    QPushButton *BtnWrThreshold;
    QPushButton *BtnTestMode;
    QPushButton *BtnUpdateFirmware;
    QPushButton *BtnDMXConsole;
    QSpacerItem *verticalSpacer;
    QLabel *lb_ConnectIcon;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout;
    QRadioButton *rdBtn_OthersDevices;
    QRadioButton *rdBtn_Light;
    QRadioButton *rdBtn_LightRGBW;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLineEdit *TxtMaxHeight;
    QLabel *label_2;
    QLineEdit *TxtDMXID;
    QLineEdit *TxtUID;
    QLabel *label;
    QLabel *lb_MaxHeight;
    QLabel *lb_MinHeight;
    QLineEdit *TxtSEQID;
    QLineEdit *TxtMinHeight;
    QLabel *label_3;
    QGroupBox *gboptionRGB;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *rdOneOne;
    QRadioButton *rdLoop;
    QMenuBar *menuBar;
    QMenu *menuCalls;
    QMenu *menuTools;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(707, 508);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/AG-logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionAboutQt = new QAction(MainWindow);
        actionAboutQt->setObjectName(QString::fromUtf8("actionAboutQt"));
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName(QString::fromUtf8("actionConnect"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/connect.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConnect->setIcon(icon1);
        actionDisconnect = new QAction(MainWindow);
        actionDisconnect->setObjectName(QString::fromUtf8("actionDisconnect"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/disconnect.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDisconnect->setIcon(icon2);
        actionConfigure = new QAction(MainWindow);
        actionConfigure->setObjectName(QString::fromUtf8("actionConfigure"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConfigure->setIcon(icon3);
        actionClear = new QAction(MainWindow);
        actionClear->setObjectName(QString::fromUtf8("actionClear"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClear->setIcon(icon4);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/application-exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuit->setIcon(icon5);
        actionUser = new QAction(MainWindow);
        actionUser->setObjectName(QString::fromUtf8("actionUser"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/Account and Control.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUser->setIcon(icon6);
        actionDMX_monitor = new QAction(MainWindow);
        actionDMX_monitor->setObjectName(QString::fromUtf8("actionDMX_monitor"));
        actionDMX_monitor_2 = new QAction(MainWindow);
        actionDMX_monitor_2->setObjectName(QString::fromUtf8("actionDMX_monitor_2"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/DMX-monitor.png"), QSize(), QIcon::Normal, QIcon::On);
        actionDMX_monitor_2->setIcon(icon7);
        actionUser_Manager = new QAction(MainWindow);
        actionUser_Manager->setObjectName(QString::fromUtf8("actionUser_Manager"));
        actionThreshold_Manager = new QAction(MainWindow);
        actionThreshold_Manager->setObjectName(QString::fromUtf8("actionThreshold_Manager"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Functions = new QGroupBox(centralWidget);
        Functions->setObjectName(QString::fromUtf8("Functions"));
        QFont font;
        font.setPointSize(12);
        Functions->setFont(font);
        verticalLayout_3 = new QVBoxLayout(Functions);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        BtnDeviceDiscovery = new QPushButton(Functions);
        BtnDeviceDiscovery->setObjectName(QString::fromUtf8("BtnDeviceDiscovery"));

        verticalLayout_3->addWidget(BtnDeviceDiscovery);

        BtnSearchDev = new QPushButton(Functions);
        BtnSearchDev->setObjectName(QString::fromUtf8("BtnSearchDev"));
        BtnSearchDev->setFont(font);

        verticalLayout_3->addWidget(BtnSearchDev);

        BtnReadDMXID = new QPushButton(Functions);
        BtnReadDMXID->setObjectName(QString::fromUtf8("BtnReadDMXID"));

        verticalLayout_3->addWidget(BtnReadDMXID);

        BtnWrDMXID = new QPushButton(Functions);
        BtnWrDMXID->setObjectName(QString::fromUtf8("BtnWrDMXID"));
        BtnWrDMXID->setFont(font);

        verticalLayout_3->addWidget(BtnWrDMXID);

        BtnWriteUID = new QPushButton(Functions);
        BtnWriteUID->setObjectName(QString::fromUtf8("BtnWriteUID"));
        BtnWriteUID->setEnabled(true);
        BtnWriteUID->setFont(font);

        verticalLayout_3->addWidget(BtnWriteUID);

        BtnWrThreshold = new QPushButton(Functions);
        BtnWrThreshold->setObjectName(QString::fromUtf8("BtnWrThreshold"));
        BtnWrThreshold->setFont(font);

        verticalLayout_3->addWidget(BtnWrThreshold);

        BtnTestMode = new QPushButton(Functions);
        BtnTestMode->setObjectName(QString::fromUtf8("BtnTestMode"));
        BtnTestMode->setFont(font);

        verticalLayout_3->addWidget(BtnTestMode);

        BtnUpdateFirmware = new QPushButton(Functions);
        BtnUpdateFirmware->setObjectName(QString::fromUtf8("BtnUpdateFirmware"));
        BtnUpdateFirmware->setFont(font);

        verticalLayout_3->addWidget(BtnUpdateFirmware);


        gridLayout->addWidget(Functions, 3, 1, 3, 1);

        BtnDMXConsole = new QPushButton(centralWidget);
        BtnDMXConsole->setObjectName(QString::fromUtf8("BtnDMXConsole"));
        BtnDMXConsole->setFont(font);

        gridLayout->addWidget(BtnDMXConsole, 5, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 1);

        lb_ConnectIcon = new QLabel(centralWidget);
        lb_ConnectIcon->setObjectName(QString::fromUtf8("lb_ConnectIcon"));
        lb_ConnectIcon->setMaximumSize(QSize(60, 60));
        lb_ConnectIcon->setScaledContents(true);
        lb_ConnectIcon->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lb_ConnectIcon, 0, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 6, 0, 1, 1);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setAutoFillBackground(false);
        groupBox_2->setStyleSheet(QString::fromUtf8("font: 87 italic 11pt \"Arial Black\";"));
        horizontalLayout = new QHBoxLayout(groupBox_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        rdBtn_OthersDevices = new QRadioButton(groupBox_2);
        rdBtn_OthersDevices->setObjectName(QString::fromUtf8("rdBtn_OthersDevices"));
        rdBtn_OthersDevices->setChecked(true);

        horizontalLayout->addWidget(rdBtn_OthersDevices);

        rdBtn_Light = new QRadioButton(groupBox_2);
        rdBtn_Light->setObjectName(QString::fromUtf8("rdBtn_Light"));

        horizontalLayout->addWidget(rdBtn_Light);

        rdBtn_LightRGBW = new QRadioButton(groupBox_2);
        rdBtn_LightRGBW->setObjectName(QString::fromUtf8("rdBtn_LightRGBW"));

        horizontalLayout->addWidget(rdBtn_LightRGBW);


        gridLayout->addWidget(groupBox_2, 0, 0, 1, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setFont(font);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout_2->setHorizontalSpacing(5);
        gridLayout_2->setVerticalSpacing(1);
        gridLayout_2->setContentsMargins(1, 1, 1, 1);
        TxtMaxHeight = new QLineEdit(groupBox);
        TxtMaxHeight->setObjectName(QString::fromUtf8("TxtMaxHeight"));

        gridLayout_2->addWidget(TxtMaxHeight, 3, 2, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        gridLayout_2->addWidget(label_2, 2, 0, 1, 1);

        TxtDMXID = new QLineEdit(groupBox);
        TxtDMXID->setObjectName(QString::fromUtf8("TxtDMXID"));

        gridLayout_2->addWidget(TxtDMXID, 2, 2, 1, 1);

        TxtUID = new QLineEdit(groupBox);
        TxtUID->setObjectName(QString::fromUtf8("TxtUID"));

        gridLayout_2->addWidget(TxtUID, 0, 2, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        lb_MaxHeight = new QLabel(groupBox);
        lb_MaxHeight->setObjectName(QString::fromUtf8("lb_MaxHeight"));
        lb_MaxHeight->setFont(font);

        gridLayout_2->addWidget(lb_MaxHeight, 3, 0, 1, 1);

        lb_MinHeight = new QLabel(groupBox);
        lb_MinHeight->setObjectName(QString::fromUtf8("lb_MinHeight"));
        lb_MinHeight->setFont(font);

        gridLayout_2->addWidget(lb_MinHeight, 4, 0, 1, 1);

        TxtSEQID = new QLineEdit(groupBox);
        TxtSEQID->setObjectName(QString::fromUtf8("TxtSEQID"));

        gridLayout_2->addWidget(TxtSEQID, 5, 2, 1, 1);

        TxtMinHeight = new QLineEdit(groupBox);
        TxtMinHeight->setObjectName(QString::fromUtf8("TxtMinHeight"));

        gridLayout_2->addWidget(TxtMinHeight, 4, 2, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 5, 0, 1, 1);


        gridLayout->addWidget(groupBox, 3, 0, 2, 1);

        gboptionRGB = new QGroupBox(centralWidget);
        gboptionRGB->setObjectName(QString::fromUtf8("gboptionRGB"));
        horizontalLayout_2 = new QHBoxLayout(gboptionRGB);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        rdOneOne = new QRadioButton(gboptionRGB);
        rdOneOne->setObjectName(QString::fromUtf8("rdOneOne"));

        horizontalLayout_2->addWidget(rdOneOne);

        rdLoop = new QRadioButton(gboptionRGB);
        rdLoop->setObjectName(QString::fromUtf8("rdLoop"));

        horizontalLayout_2->addWidget(rdLoop);


        gridLayout->addWidget(gboptionRGB, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 707, 21));
        menuCalls = new QMenu(menuBar);
        menuCalls->setObjectName(QString::fromUtf8("menuCalls"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuCalls->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuCalls->addAction(actionConnect);
        menuCalls->addAction(actionDisconnect);
        menuCalls->addSeparator();
        menuCalls->addAction(actionQuit);
        menuTools->addAction(actionConfigure);
        menuTools->addAction(actionClear);
        menuTools->addAction(actionUser);
        menuTools->addAction(actionUser_Manager);
        menuTools->addAction(actionThreshold_Manager);
        menuTools->addSeparator();
        menuTools->addSeparator();
        menuTools->addSeparator();
        menuTools->addAction(actionDMX_monitor_2);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionAboutQt);
        mainToolBar->addAction(actionConnect);
        mainToolBar->addAction(actionDisconnect);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionConfigure);
        mainToolBar->addAction(actionClear);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "AG DMX Device manager", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "&About", nullptr));
#if QT_CONFIG(tooltip)
        actionAbout->setToolTip(QCoreApplication::translate("MainWindow", "About program", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionAbout->setShortcut(QCoreApplication::translate("MainWindow", "Alt+A", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAboutQt->setText(QCoreApplication::translate("MainWindow", "About Qt", nullptr));
        actionConnect->setText(QCoreApplication::translate("MainWindow", "C&onnect", nullptr));
#if QT_CONFIG(tooltip)
        actionConnect->setToolTip(QCoreApplication::translate("MainWindow", "Connect to serial port", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionConnect->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionDisconnect->setText(QCoreApplication::translate("MainWindow", "&Disconnect", nullptr));
#if QT_CONFIG(tooltip)
        actionDisconnect->setToolTip(QCoreApplication::translate("MainWindow", "Disconnect from serial port", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionDisconnect->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+D", nullptr));
#endif // QT_CONFIG(shortcut)
        actionConfigure->setText(QCoreApplication::translate("MainWindow", "&Configure", nullptr));
#if QT_CONFIG(tooltip)
        actionConfigure->setToolTip(QCoreApplication::translate("MainWindow", "Configure serial port", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionConfigure->setShortcut(QCoreApplication::translate("MainWindow", "Alt+C", nullptr));
#endif // QT_CONFIG(shortcut)
        actionClear->setText(QCoreApplication::translate("MainWindow", "C&lear", nullptr));
#if QT_CONFIG(tooltip)
        actionClear->setToolTip(QCoreApplication::translate("MainWindow", "Clear data", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionClear->setShortcut(QCoreApplication::translate("MainWindow", "Alt+L", nullptr));
#endif // QT_CONFIG(shortcut)
        actionQuit->setText(QCoreApplication::translate("MainWindow", "&Quit", nullptr));
#if QT_CONFIG(shortcut)
        actionQuit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        actionUser->setText(QCoreApplication::translate("MainWindow", "User", nullptr));
        actionDMX_monitor->setText(QCoreApplication::translate("MainWindow", "DMX monitor", nullptr));
        actionDMX_monitor_2->setText(QCoreApplication::translate("MainWindow", "DMX monitor", nullptr));
        actionUser_Manager->setText(QCoreApplication::translate("MainWindow", "User Manager", nullptr));
        actionThreshold_Manager->setText(QCoreApplication::translate("MainWindow", "Threshold Manager", nullptr));
        Functions->setTitle(QCoreApplication::translate("MainWindow", "Functions", nullptr));
        BtnDeviceDiscovery->setText(QCoreApplication::translate("MainWindow", "Discovery", nullptr));
        BtnSearchDev->setText(QCoreApplication::translate("MainWindow", "Ping Device", nullptr));
        BtnReadDMXID->setText(QCoreApplication::translate("MainWindow", "Read DMX ID", nullptr));
        BtnWrDMXID->setText(QCoreApplication::translate("MainWindow", "Write DMX ID", nullptr));
        BtnWriteUID->setText(QCoreApplication::translate("MainWindow", "Write UID", nullptr));
        BtnWrThreshold->setText(QCoreApplication::translate("MainWindow", "Write Level", nullptr));
        BtnTestMode->setText(QCoreApplication::translate("MainWindow", "Test device", nullptr));
        BtnUpdateFirmware->setText(QCoreApplication::translate("MainWindow", "Update Firmware", nullptr));
        BtnDMXConsole->setText(QCoreApplication::translate("MainWindow", "DMX", nullptr));
        lb_ConnectIcon->setText(QString());
        rdBtn_OthersDevices->setText(QCoreApplication::translate("MainWindow", "Others devices", nullptr));
        rdBtn_Light->setText(QCoreApplication::translate("MainWindow", "RGB LED", nullptr));
        rdBtn_LightRGBW->setText(QCoreApplication::translate("MainWindow", "RGBW LED", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Device info", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "DMX ID", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "UID", nullptr));
        lb_MaxHeight->setText(QCoreApplication::translate("MainWindow", "MAX Height", nullptr));
        lb_MinHeight->setText(QCoreApplication::translate("MainWindow", "MIN Height", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Position", nullptr));
        gboptionRGB->setTitle(QString());
        rdOneOne->setText(QCoreApplication::translate("MainWindow", "One-One", nullptr));
        rdLoop->setText(QCoreApplication::translate("MainWindow", "LOOP", nullptr));
        menuCalls->setTitle(QCoreApplication::translate("MainWindow", "Calls", nullptr));
        menuTools->setTitle(QCoreApplication::translate("MainWindow", "Tools", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

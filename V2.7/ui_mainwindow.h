/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
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
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout;
    QRadioButton *rdBtn_OthersDevices;
    QRadioButton *rdBtn_Light;
    QRadioButton *rdBtn_LightRGBW;
    QGroupBox *Functions;
    QVBoxLayout *verticalLayout_3;
    QPushButton *BtnDeviceDiscovery;
    QPushButton *BtnSearchDev;
    QPushButton *BtnWrDMXID;
    QPushButton *BtnWriteUID;
    QPushButton *BtnWrThreshold;
    QPushButton *BtnTestMode;
    QPushButton *BtnUpdateFirmware;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;
    QLabel *lb_ConnectIcon;
    QPushButton *BtnDMXConsole;
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
    QMenuBar *menuBar;
    QMenu *menuCalls;
    QMenu *menuTools;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(710, 480);
        QIcon icon;
        icon.addFile(QStringLiteral(":/AG-logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionAboutQt = new QAction(MainWindow);
        actionAboutQt->setObjectName(QStringLiteral("actionAboutQt"));
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName(QStringLiteral("actionConnect"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/connect.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConnect->setIcon(icon1);
        actionDisconnect = new QAction(MainWindow);
        actionDisconnect->setObjectName(QStringLiteral("actionDisconnect"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/disconnect.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDisconnect->setIcon(icon2);
        actionConfigure = new QAction(MainWindow);
        actionConfigure->setObjectName(QStringLiteral("actionConfigure"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConfigure->setIcon(icon3);
        actionClear = new QAction(MainWindow);
        actionClear->setObjectName(QStringLiteral("actionClear"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClear->setIcon(icon4);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/application-exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuit->setIcon(icon5);
        actionUser = new QAction(MainWindow);
        actionUser->setObjectName(QStringLiteral("actionUser"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/images/Account and Control.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUser->setIcon(icon6);
        actionDMX_monitor = new QAction(MainWindow);
        actionDMX_monitor->setObjectName(QStringLiteral("actionDMX_monitor"));
        actionDMX_monitor_2 = new QAction(MainWindow);
        actionDMX_monitor_2->setObjectName(QStringLiteral("actionDMX_monitor_2"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/images/DMX-monitor.png"), QSize(), QIcon::Normal, QIcon::On);
        actionDMX_monitor_2->setIcon(icon7);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setAutoFillBackground(false);
        groupBox_2->setStyleSheet(QStringLiteral("font: 87 italic 11pt \"Arial Black\";"));
        horizontalLayout = new QHBoxLayout(groupBox_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        rdBtn_OthersDevices = new QRadioButton(groupBox_2);
        rdBtn_OthersDevices->setObjectName(QStringLiteral("rdBtn_OthersDevices"));
        rdBtn_OthersDevices->setChecked(true);

        horizontalLayout->addWidget(rdBtn_OthersDevices);

        rdBtn_Light = new QRadioButton(groupBox_2);
        rdBtn_Light->setObjectName(QStringLiteral("rdBtn_Light"));

        horizontalLayout->addWidget(rdBtn_Light);

        rdBtn_LightRGBW = new QRadioButton(groupBox_2);
        rdBtn_LightRGBW->setObjectName(QStringLiteral("rdBtn_LightRGBW"));

        horizontalLayout->addWidget(rdBtn_LightRGBW);


        gridLayout->addWidget(groupBox_2, 0, 0, 1, 1);

        Functions = new QGroupBox(centralWidget);
        Functions->setObjectName(QStringLiteral("Functions"));
        QFont font;
        font.setPointSize(12);
        Functions->setFont(font);
        verticalLayout_3 = new QVBoxLayout(Functions);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        BtnDeviceDiscovery = new QPushButton(Functions);
        BtnDeviceDiscovery->setObjectName(QStringLiteral("BtnDeviceDiscovery"));

        verticalLayout_3->addWidget(BtnDeviceDiscovery);

        BtnSearchDev = new QPushButton(Functions);
        BtnSearchDev->setObjectName(QStringLiteral("BtnSearchDev"));
        BtnSearchDev->setFont(font);

        verticalLayout_3->addWidget(BtnSearchDev);

        BtnWrDMXID = new QPushButton(Functions);
        BtnWrDMXID->setObjectName(QStringLiteral("BtnWrDMXID"));
        BtnWrDMXID->setFont(font);

        verticalLayout_3->addWidget(BtnWrDMXID);

        BtnWriteUID = new QPushButton(Functions);
        BtnWriteUID->setObjectName(QStringLiteral("BtnWriteUID"));
        BtnWriteUID->setEnabled(true);
        BtnWriteUID->setFont(font);

        verticalLayout_3->addWidget(BtnWriteUID);

        BtnWrThreshold = new QPushButton(Functions);
        BtnWrThreshold->setObjectName(QStringLiteral("BtnWrThreshold"));
        BtnWrThreshold->setFont(font);

        verticalLayout_3->addWidget(BtnWrThreshold);

        BtnTestMode = new QPushButton(Functions);
        BtnTestMode->setObjectName(QStringLiteral("BtnTestMode"));
        BtnTestMode->setFont(font);

        verticalLayout_3->addWidget(BtnTestMode);

        BtnUpdateFirmware = new QPushButton(Functions);
        BtnUpdateFirmware->setObjectName(QStringLiteral("BtnUpdateFirmware"));
        BtnUpdateFirmware->setFont(font);

        verticalLayout_3->addWidget(BtnUpdateFirmware);


        gridLayout->addWidget(Functions, 2, 1, 3, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 5, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);

        lb_ConnectIcon = new QLabel(centralWidget);
        lb_ConnectIcon->setObjectName(QStringLiteral("lb_ConnectIcon"));
        lb_ConnectIcon->setMaximumSize(QSize(60, 60));
        lb_ConnectIcon->setScaledContents(true);
        lb_ConnectIcon->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lb_ConnectIcon, 0, 1, 1, 1);

        BtnDMXConsole = new QPushButton(centralWidget);
        BtnDMXConsole->setObjectName(QStringLiteral("BtnDMXConsole"));
        BtnDMXConsole->setFont(font);

        gridLayout->addWidget(BtnDMXConsole, 4, 0, 1, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setFont(font);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout_2->setHorizontalSpacing(5);
        gridLayout_2->setVerticalSpacing(1);
        gridLayout_2->setContentsMargins(1, 1, 1, 1);
        TxtMaxHeight = new QLineEdit(groupBox);
        TxtMaxHeight->setObjectName(QStringLiteral("TxtMaxHeight"));

        gridLayout_2->addWidget(TxtMaxHeight, 3, 2, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout_2->addWidget(label_2, 2, 0, 1, 1);

        TxtDMXID = new QLineEdit(groupBox);
        TxtDMXID->setObjectName(QStringLiteral("TxtDMXID"));

        gridLayout_2->addWidget(TxtDMXID, 2, 2, 1, 1);

        TxtUID = new QLineEdit(groupBox);
        TxtUID->setObjectName(QStringLiteral("TxtUID"));

        gridLayout_2->addWidget(TxtUID, 0, 2, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        lb_MaxHeight = new QLabel(groupBox);
        lb_MaxHeight->setObjectName(QStringLiteral("lb_MaxHeight"));
        lb_MaxHeight->setFont(font);

        gridLayout_2->addWidget(lb_MaxHeight, 3, 0, 1, 1);

        lb_MinHeight = new QLabel(groupBox);
        lb_MinHeight->setObjectName(QStringLiteral("lb_MinHeight"));
        lb_MinHeight->setFont(font);

        gridLayout_2->addWidget(lb_MinHeight, 4, 0, 1, 1);

        TxtSEQID = new QLineEdit(groupBox);
        TxtSEQID->setObjectName(QStringLiteral("TxtSEQID"));

        gridLayout_2->addWidget(TxtSEQID, 5, 2, 1, 1);

        TxtMinHeight = new QLineEdit(groupBox);
        TxtMinHeight->setObjectName(QStringLiteral("TxtMinHeight"));

        gridLayout_2->addWidget(TxtMinHeight, 4, 2, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 5, 0, 1, 1);


        gridLayout->addWidget(groupBox, 2, 0, 2, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 710, 20));
        menuCalls = new QMenu(menuBar);
        menuCalls->setObjectName(QStringLiteral("menuCalls"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "AG DMX Device manager", 0));
        actionAbout->setText(QApplication::translate("MainWindow", "&About", 0));
#ifndef QT_NO_TOOLTIP
        actionAbout->setToolTip(QApplication::translate("MainWindow", "About program", 0));
#endif // QT_NO_TOOLTIP
        actionAbout->setShortcut(QApplication::translate("MainWindow", "Alt+A", 0));
        actionAboutQt->setText(QApplication::translate("MainWindow", "About Qt", 0));
        actionConnect->setText(QApplication::translate("MainWindow", "C&onnect", 0));
#ifndef QT_NO_TOOLTIP
        actionConnect->setToolTip(QApplication::translate("MainWindow", "Connect to serial port", 0));
#endif // QT_NO_TOOLTIP
        actionConnect->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        actionDisconnect->setText(QApplication::translate("MainWindow", "&Disconnect", 0));
#ifndef QT_NO_TOOLTIP
        actionDisconnect->setToolTip(QApplication::translate("MainWindow", "Disconnect from serial port", 0));
#endif // QT_NO_TOOLTIP
        actionDisconnect->setShortcut(QApplication::translate("MainWindow", "Ctrl+D", 0));
        actionConfigure->setText(QApplication::translate("MainWindow", "&Configure", 0));
#ifndef QT_NO_TOOLTIP
        actionConfigure->setToolTip(QApplication::translate("MainWindow", "Configure serial port", 0));
#endif // QT_NO_TOOLTIP
        actionConfigure->setShortcut(QApplication::translate("MainWindow", "Alt+C", 0));
        actionClear->setText(QApplication::translate("MainWindow", "C&lear", 0));
#ifndef QT_NO_TOOLTIP
        actionClear->setToolTip(QApplication::translate("MainWindow", "Clear data", 0));
#endif // QT_NO_TOOLTIP
        actionClear->setShortcut(QApplication::translate("MainWindow", "Alt+L", 0));
        actionQuit->setText(QApplication::translate("MainWindow", "&Quit", 0));
        actionQuit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0));
        actionUser->setText(QApplication::translate("MainWindow", "User", 0));
        actionDMX_monitor->setText(QApplication::translate("MainWindow", "DMX monitor", 0));
        actionDMX_monitor_2->setText(QApplication::translate("MainWindow", "DMX monitor", 0));
        rdBtn_OthersDevices->setText(QApplication::translate("MainWindow", "Others devices", 0));
        rdBtn_Light->setText(QApplication::translate("MainWindow", "RGB LED", 0));
        rdBtn_LightRGBW->setText(QApplication::translate("MainWindow", "RGBW LED", 0));
        Functions->setTitle(QApplication::translate("MainWindow", "Functions", 0));
        BtnDeviceDiscovery->setText(QApplication::translate("MainWindow", "Discovery", 0));
        BtnSearchDev->setText(QApplication::translate("MainWindow", "Ping Device", 0));
        BtnWrDMXID->setText(QApplication::translate("MainWindow", "Write DMX ID", 0));
        BtnWriteUID->setText(QApplication::translate("MainWindow", "Write UID", 0));
        BtnWrThreshold->setText(QApplication::translate("MainWindow", "Write Level", 0));
        BtnTestMode->setText(QApplication::translate("MainWindow", "Test device", 0));
        BtnUpdateFirmware->setText(QApplication::translate("MainWindow", "Update Firmware", 0));
        lb_ConnectIcon->setText(QString());
        BtnDMXConsole->setText(QApplication::translate("MainWindow", "DMX", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Device info", 0));
        label_2->setText(QApplication::translate("MainWindow", "DMX ID", 0));
        label->setText(QApplication::translate("MainWindow", "UID", 0));
        lb_MaxHeight->setText(QApplication::translate("MainWindow", "MAX Height", 0));
        lb_MinHeight->setText(QApplication::translate("MainWindow", "MIN Height", 0));
        label_3->setText(QApplication::translate("MainWindow", "Position", 0));
        menuCalls->setTitle(QApplication::translate("MainWindow", "Calls", 0));
        menuTools->setTitle(QApplication::translate("MainWindow", "Tools", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

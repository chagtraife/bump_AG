/********************************************************************************
** Form generated from reading UI file 'deviceview.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVICEVIEW_H
#define UI_DEVICEVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeviceView
{
public:
    QAction *actionSave;
    QAction *actionLoad;
    QAction *actionRefresh_Position;
    QAction *actionUpdate_Sub_Driver_Firmware;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QPushButton *BtnBeginDiscovery;
    QPushButton *BtnAddNewDev;
    QPushButton *BtnReadPosition;
    QPushButton *BtnReadParameters;
    QPushButton *BtnSelectAll;
    QPushButton *BtnDeselectAll;
    QPushButton *BtnWriteDMXAddress;
    QPushButton *BtnWriteLevel;
    QPushButton *BtnWriteParameter;
    QPushButton *BtnSetTestMode;
    QSpacerItem *verticalSpacer;
    QTableView *tableView_Device;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuFunctions;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *DeviceView)
    {
        if (DeviceView->objectName().isEmpty())
            DeviceView->setObjectName(QString::fromUtf8("DeviceView"));
        DeviceView->resize(650, 401);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/AG-logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        DeviceView->setWindowIcon(icon);
        actionSave = new QAction(DeviceView);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/save (2).ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon1);
        QFont font;
        font.setPointSize(10);
        actionSave->setFont(font);
        actionLoad = new QAction(DeviceView);
        actionLoad->setObjectName(QString::fromUtf8("actionLoad"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/folder_open.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionLoad->setIcon(icon2);
        actionLoad->setFont(font);
        actionRefresh_Position = new QAction(DeviceView);
        actionRefresh_Position->setObjectName(QString::fromUtf8("actionRefresh_Position"));
        actionUpdate_Sub_Driver_Firmware = new QAction(DeviceView);
        actionUpdate_Sub_Driver_Firmware->setObjectName(QString::fromUtf8("actionUpdate_Sub_Driver_Firmware"));
        centralwidget = new QWidget(DeviceView);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        BtnBeginDiscovery = new QPushButton(groupBox);
        BtnBeginDiscovery->setObjectName(QString::fromUtf8("BtnBeginDiscovery"));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        BtnBeginDiscovery->setFont(font1);
        BtnBeginDiscovery->setCheckable(false);

        verticalLayout->addWidget(BtnBeginDiscovery);

        BtnAddNewDev = new QPushButton(groupBox);
        BtnAddNewDev->setObjectName(QString::fromUtf8("BtnAddNewDev"));
        BtnAddNewDev->setFont(font);

        verticalLayout->addWidget(BtnAddNewDev);

        BtnReadPosition = new QPushButton(groupBox);
        BtnReadPosition->setObjectName(QString::fromUtf8("BtnReadPosition"));
        BtnReadPosition->setFont(font);

        verticalLayout->addWidget(BtnReadPosition);

        BtnReadParameters = new QPushButton(groupBox);
        BtnReadParameters->setObjectName(QString::fromUtf8("BtnReadParameters"));
        BtnReadParameters->setFont(font);

        verticalLayout->addWidget(BtnReadParameters);

        BtnSelectAll = new QPushButton(groupBox);
        BtnSelectAll->setObjectName(QString::fromUtf8("BtnSelectAll"));
        BtnSelectAll->setFont(font);

        verticalLayout->addWidget(BtnSelectAll);

        BtnDeselectAll = new QPushButton(groupBox);
        BtnDeselectAll->setObjectName(QString::fromUtf8("BtnDeselectAll"));
        BtnDeselectAll->setFont(font);

        verticalLayout->addWidget(BtnDeselectAll);

        BtnWriteDMXAddress = new QPushButton(groupBox);
        BtnWriteDMXAddress->setObjectName(QString::fromUtf8("BtnWriteDMXAddress"));
        BtnWriteDMXAddress->setFont(font);

        verticalLayout->addWidget(BtnWriteDMXAddress);

        BtnWriteLevel = new QPushButton(groupBox);
        BtnWriteLevel->setObjectName(QString::fromUtf8("BtnWriteLevel"));
        BtnWriteLevel->setFont(font);

        verticalLayout->addWidget(BtnWriteLevel);

        BtnWriteParameter = new QPushButton(groupBox);
        BtnWriteParameter->setObjectName(QString::fromUtf8("BtnWriteParameter"));
        BtnWriteParameter->setFont(font);

        verticalLayout->addWidget(BtnWriteParameter);

        BtnSetTestMode = new QPushButton(groupBox);
        BtnSetTestMode->setObjectName(QString::fromUtf8("BtnSetTestMode"));
        BtnSetTestMode->setFont(font);

        verticalLayout->addWidget(BtnSetTestMode);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout->addWidget(groupBox, 0, 1, 1, 1);

        tableView_Device = new QTableView(centralwidget);
        tableView_Device->setObjectName(QString::fromUtf8("tableView_Device"));
        tableView_Device->setMouseTracking(false);
        tableView_Device->setAutoFillBackground(true);
        tableView_Device->setAlternatingRowColors(true);
        tableView_Device->setSelectionMode(QAbstractItemView::ExtendedSelection);
        tableView_Device->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView_Device->setGridStyle(Qt::SolidLine);
        tableView_Device->setSortingEnabled(true);
        tableView_Device->setWordWrap(true);
        tableView_Device->horizontalHeader()->setCascadingSectionResizes(false);
        tableView_Device->horizontalHeader()->setStretchLastSection(false);

        gridLayout->addWidget(tableView_Device, 0, 0, 1, 1);

        DeviceView->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DeviceView);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 650, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuFunctions = new QMenu(menubar);
        menuFunctions->setObjectName(QString::fromUtf8("menuFunctions"));
        DeviceView->setMenuBar(menubar);
        statusbar = new QStatusBar(DeviceView);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        DeviceView->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuFunctions->menuAction());
        menuFile->addAction(actionSave);
        menuFile->addAction(actionLoad);
        menuFunctions->addAction(actionRefresh_Position);
        menuFunctions->addAction(actionUpdate_Sub_Driver_Firmware);

        retranslateUi(DeviceView);

        QMetaObject::connectSlotsByName(DeviceView);
    } // setupUi

    void retranslateUi(QMainWindow *DeviceView)
    {
        DeviceView->setWindowTitle(QCoreApplication::translate("DeviceView", "Device Manager", nullptr));
        actionSave->setText(QCoreApplication::translate("DeviceView", "Save", nullptr));
#if QT_CONFIG(shortcut)
        actionSave->setShortcut(QCoreApplication::translate("DeviceView", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionLoad->setText(QCoreApplication::translate("DeviceView", "Load", nullptr));
#if QT_CONFIG(shortcut)
        actionLoad->setShortcut(QCoreApplication::translate("DeviceView", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRefresh_Position->setText(QCoreApplication::translate("DeviceView", "Refresh Position", nullptr));
        actionUpdate_Sub_Driver_Firmware->setText(QCoreApplication::translate("DeviceView", "Update Sub-Driver Firmware", nullptr));
        groupBox->setTitle(QString());
        BtnBeginDiscovery->setText(QCoreApplication::translate("DeviceView", "Begin Discovery", nullptr));
        BtnAddNewDev->setText(QCoreApplication::translate("DeviceView", "Add new Device", nullptr));
        BtnReadPosition->setText(QCoreApplication::translate("DeviceView", "Refresh Position", nullptr));
        BtnReadParameters->setText(QCoreApplication::translate("DeviceView", "Read Parameters", nullptr));
        BtnSelectAll->setText(QCoreApplication::translate("DeviceView", "Select All", nullptr));
        BtnDeselectAll->setText(QCoreApplication::translate("DeviceView", "Deselect All", nullptr));
        BtnWriteDMXAddress->setText(QCoreApplication::translate("DeviceView", "Write DMX Address", nullptr));
        BtnWriteLevel->setText(QCoreApplication::translate("DeviceView", "Write Level", nullptr));
        BtnWriteParameter->setText(QCoreApplication::translate("DeviceView", "Write EEprom", nullptr));
        BtnSetTestMode->setText(QCoreApplication::translate("DeviceView", "Set Test Mode", nullptr));
        menuFile->setTitle(QCoreApplication::translate("DeviceView", "File", nullptr));
        menuFunctions->setTitle(QCoreApplication::translate("DeviceView", "Functions", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeviceView: public Ui_DeviceView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVICEVIEW_H

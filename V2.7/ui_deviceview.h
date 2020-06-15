/********************************************************************************
** Form generated from reading UI file 'deviceview.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVICEVIEW_H
#define UI_DEVICEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
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
            DeviceView->setObjectName(QStringLiteral("DeviceView"));
        DeviceView->resize(650, 401);
        actionSave = new QAction(DeviceView);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/save (2).ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon);
        QFont font;
        font.setPointSize(10);
        actionSave->setFont(font);
        actionLoad = new QAction(DeviceView);
        actionLoad->setObjectName(QStringLiteral("actionLoad"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/folder_open.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionLoad->setIcon(icon1);
        actionLoad->setFont(font);
        actionRefresh_Position = new QAction(DeviceView);
        actionRefresh_Position->setObjectName(QStringLiteral("actionRefresh_Position"));
        actionUpdate_Sub_Driver_Firmware = new QAction(DeviceView);
        actionUpdate_Sub_Driver_Firmware->setObjectName(QStringLiteral("actionUpdate_Sub_Driver_Firmware"));
        centralwidget = new QWidget(DeviceView);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        BtnBeginDiscovery = new QPushButton(groupBox);
        BtnBeginDiscovery->setObjectName(QStringLiteral("BtnBeginDiscovery"));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        BtnBeginDiscovery->setFont(font1);
        BtnBeginDiscovery->setCheckable(false);

        verticalLayout->addWidget(BtnBeginDiscovery);

        BtnAddNewDev = new QPushButton(groupBox);
        BtnAddNewDev->setObjectName(QStringLiteral("BtnAddNewDev"));
        BtnAddNewDev->setFont(font);

        verticalLayout->addWidget(BtnAddNewDev);

        BtnReadPosition = new QPushButton(groupBox);
        BtnReadPosition->setObjectName(QStringLiteral("BtnReadPosition"));
        BtnReadPosition->setFont(font);

        verticalLayout->addWidget(BtnReadPosition);

        BtnReadParameters = new QPushButton(groupBox);
        BtnReadParameters->setObjectName(QStringLiteral("BtnReadParameters"));
        BtnReadParameters->setFont(font);

        verticalLayout->addWidget(BtnReadParameters);

        BtnSelectAll = new QPushButton(groupBox);
        BtnSelectAll->setObjectName(QStringLiteral("BtnSelectAll"));
        BtnSelectAll->setFont(font);

        verticalLayout->addWidget(BtnSelectAll);

        BtnDeselectAll = new QPushButton(groupBox);
        BtnDeselectAll->setObjectName(QStringLiteral("BtnDeselectAll"));
        BtnDeselectAll->setFont(font);

        verticalLayout->addWidget(BtnDeselectAll);

        BtnWriteDMXAddress = new QPushButton(groupBox);
        BtnWriteDMXAddress->setObjectName(QStringLiteral("BtnWriteDMXAddress"));
        BtnWriteDMXAddress->setFont(font);

        verticalLayout->addWidget(BtnWriteDMXAddress);

        BtnWriteLevel = new QPushButton(groupBox);
        BtnWriteLevel->setObjectName(QStringLiteral("BtnWriteLevel"));
        BtnWriteLevel->setFont(font);

        verticalLayout->addWidget(BtnWriteLevel);

        BtnWriteParameter = new QPushButton(groupBox);
        BtnWriteParameter->setObjectName(QStringLiteral("BtnWriteParameter"));
        BtnWriteParameter->setFont(font);

        verticalLayout->addWidget(BtnWriteParameter);

        BtnSetTestMode = new QPushButton(groupBox);
        BtnSetTestMode->setObjectName(QStringLiteral("BtnSetTestMode"));
        BtnSetTestMode->setFont(font);

        verticalLayout->addWidget(BtnSetTestMode);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout->addWidget(groupBox, 0, 1, 1, 1);

        tableView_Device = new QTableView(centralwidget);
        tableView_Device->setObjectName(QStringLiteral("tableView_Device"));
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
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 650, 20));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuFunctions = new QMenu(menubar);
        menuFunctions->setObjectName(QStringLiteral("menuFunctions"));
        DeviceView->setMenuBar(menubar);
        statusbar = new QStatusBar(DeviceView);
        statusbar->setObjectName(QStringLiteral("statusbar"));
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
        DeviceView->setWindowTitle(QApplication::translate("DeviceView", "Device Manager", 0));
        actionSave->setText(QApplication::translate("DeviceView", "Save", 0));
        actionSave->setShortcut(QApplication::translate("DeviceView", "Ctrl+S", 0));
        actionLoad->setText(QApplication::translate("DeviceView", "Load", 0));
        actionLoad->setShortcut(QApplication::translate("DeviceView", "Ctrl+O", 0));
        actionRefresh_Position->setText(QApplication::translate("DeviceView", "Refresh Position", 0));
        actionUpdate_Sub_Driver_Firmware->setText(QApplication::translate("DeviceView", "Update Sub-Driver Firmware", 0));
        groupBox->setTitle(QString());
        BtnBeginDiscovery->setText(QApplication::translate("DeviceView", "Begin Discovery", 0));
        BtnAddNewDev->setText(QApplication::translate("DeviceView", "Add new Device", 0));
        BtnReadPosition->setText(QApplication::translate("DeviceView", "Refresh Position", 0));
        BtnReadParameters->setText(QApplication::translate("DeviceView", "Read Parameters", 0));
        BtnSelectAll->setText(QApplication::translate("DeviceView", "Select All", 0));
        BtnDeselectAll->setText(QApplication::translate("DeviceView", "Deselect All", 0));
        BtnWriteDMXAddress->setText(QApplication::translate("DeviceView", "Write DMX Address", 0));
        BtnWriteLevel->setText(QApplication::translate("DeviceView", "Write Level", 0));
        BtnWriteParameter->setText(QApplication::translate("DeviceView", "Write EEprom", 0));
        BtnSetTestMode->setText(QApplication::translate("DeviceView", "Set Test Mode", 0));
        menuFile->setTitle(QApplication::translate("DeviceView", "File", 0));
        menuFunctions->setTitle(QApplication::translate("DeviceView", "Functions", 0));
    } // retranslateUi

};

namespace Ui {
    class DeviceView: public Ui_DeviceView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVICEVIEW_H

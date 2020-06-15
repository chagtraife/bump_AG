/********************************************************************************
** Form generated from reading UI file 'loadingdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADINGDIALOG_H
#define UI_LOADINGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoadingDialog
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *lb_loadingImg;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LoadingDialog)
    {
        if (LoadingDialog->objectName().isEmpty())
            LoadingDialog->setObjectName(QStringLiteral("LoadingDialog"));
        LoadingDialog->setWindowModality(Qt::NonModal);
        LoadingDialog->setEnabled(true);
        LoadingDialog->resize(62, 73);
        LoadingDialog->setMaximumSize(QSize(62, 73));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        QBrush brush1(QColor(160, 160, 160, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        LoadingDialog->setPalette(palette);
        LoadingDialog->setContextMenuPolicy(Qt::PreventContextMenu);
        LoadingDialog->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        LoadingDialog->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        centralwidget = new QWidget(LoadingDialog);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lb_loadingImg = new QLabel(centralwidget);
        lb_loadingImg->setObjectName(QStringLiteral("lb_loadingImg"));
        lb_loadingImg->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(lb_loadingImg, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        LoadingDialog->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LoadingDialog);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 62, 20));
        LoadingDialog->setMenuBar(menubar);
        statusbar = new QStatusBar(LoadingDialog);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        LoadingDialog->setStatusBar(statusbar);

        retranslateUi(LoadingDialog);

        QMetaObject::connectSlotsByName(LoadingDialog);
    } // setupUi

    void retranslateUi(QMainWindow *LoadingDialog)
    {
        LoadingDialog->setWindowTitle(QApplication::translate("LoadingDialog", "MainWindow", 0));
        lb_loadingImg->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LoadingDialog: public Ui_LoadingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADINGDIALOG_H

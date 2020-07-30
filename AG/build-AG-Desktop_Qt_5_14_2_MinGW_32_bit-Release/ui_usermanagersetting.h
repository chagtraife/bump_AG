/********************************************************************************
** Form generated from reading UI file 'usermanagersetting.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERMANAGERSETTING_H
#define UI_USERMANAGERSETTING_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_UserManagerSetting
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *txtPwLv1;
    QPushButton *pushButton;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLineEdit *txtPwLv2;
    QPushButton *pushButton_2;

    void setupUi(QDialog *UserManagerSetting)
    {
        if (UserManagerSetting->objectName().isEmpty())
            UserManagerSetting->setObjectName(QString::fromUtf8("UserManagerSetting"));
        UserManagerSetting->resize(393, 231);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/AG-logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        UserManagerSetting->setWindowIcon(icon);
        gridLayout = new QGridLayout(UserManagerSetting);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(UserManagerSetting);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_4 = new QVBoxLayout(groupBox);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout = new QHBoxLayout(groupBox_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        txtPwLv1 = new QLineEdit(groupBox_2);
        txtPwLv1->setObjectName(QString::fromUtf8("txtPwLv1"));

        horizontalLayout->addWidget(txtPwLv1);

        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout_4->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        txtPwLv2 = new QLineEdit(groupBox_3);
        txtPwLv2->setObjectName(QString::fromUtf8("txtPwLv2"));

        horizontalLayout_2->addWidget(txtPwLv2);

        pushButton_2 = new QPushButton(groupBox_3);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);


        verticalLayout_4->addWidget(groupBox_3);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);


        retranslateUi(UserManagerSetting);

        QMetaObject::connectSlotsByName(UserManagerSetting);
    } // setupUi

    void retranslateUi(QDialog *UserManagerSetting)
    {
        UserManagerSetting->setWindowTitle(QCoreApplication::translate("UserManagerSetting", "User Manager Setting", nullptr));
        groupBox->setTitle(QCoreApplication::translate("UserManagerSetting", "User Manager", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("UserManagerSetting", "Admin", nullptr));
        label_2->setText(QCoreApplication::translate("UserManagerSetting", "Password", nullptr));
        pushButton->setText(QCoreApplication::translate("UserManagerSetting", "OK", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("UserManagerSetting", "Customer", nullptr));
        label_4->setText(QCoreApplication::translate("UserManagerSetting", "Password", nullptr));
        pushButton_2->setText(QCoreApplication::translate("UserManagerSetting", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserManagerSetting: public Ui_UserManagerSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERMANAGERSETTING_H

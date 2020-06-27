/********************************************************************************
** Form generated from reading UI file 'ledrgbwctrl.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEDRGBWCTRL_H
#define UI_LEDRGBWCTRL_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LedRGBWCtrl
{
public:
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QRadioButton *rb_OneOne;
    QRadioButton *rb_Loop;
    QLabel *label;
    QLineEdit *txtDMX_ID;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QPushButton *btnRead;
    QPushButton *btnWrite;

    void setupUi(QDialog *LedRGBWCtrl)
    {
        if (LedRGBWCtrl->objectName().isEmpty())
            LedRGBWCtrl->setObjectName(QString::fromUtf8("LedRGBWCtrl"));
        LedRGBWCtrl->resize(378, 137);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/AG-logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        LedRGBWCtrl->setWindowIcon(icon);
        groupBox = new QGroupBox(LedRGBWCtrl);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(39, 19, 190, 50));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        rb_OneOne = new QRadioButton(groupBox);
        rb_OneOne->setObjectName(QString::fromUtf8("rb_OneOne"));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        rb_OneOne->setFont(font);

        horizontalLayout->addWidget(rb_OneOne);

        rb_Loop = new QRadioButton(groupBox);
        rb_Loop->setObjectName(QString::fromUtf8("rb_Loop"));
        rb_Loop->setFont(font);

        horizontalLayout->addWidget(rb_Loop);

        label = new QLabel(LedRGBWCtrl);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 80, 81, 31));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        txtDMX_ID = new QLineEdit(LedRGBWCtrl);
        txtDMX_ID->setObjectName(QString::fromUtf8("txtDMX_ID"));
        txtDMX_ID->setGeometry(QRect(120, 80, 121, 31));
        groupBox_2 = new QGroupBox(LedRGBWCtrl);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(260, 20, 101, 91));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        btnRead = new QPushButton(groupBox_2);
        btnRead->setObjectName(QString::fromUtf8("btnRead"));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setWeight(50);
        btnRead->setFont(font2);

        verticalLayout->addWidget(btnRead);

        btnWrite = new QPushButton(groupBox_2);
        btnWrite->setObjectName(QString::fromUtf8("btnWrite"));
        QFont font3;
        font3.setPointSize(12);
        btnWrite->setFont(font3);

        verticalLayout->addWidget(btnWrite);


        retranslateUi(LedRGBWCtrl);

        QMetaObject::connectSlotsByName(LedRGBWCtrl);
    } // setupUi

    void retranslateUi(QDialog *LedRGBWCtrl)
    {
        LedRGBWCtrl->setWindowTitle(QCoreApplication::translate("LedRGBWCtrl", "LED RGBW V1.0", nullptr));
        groupBox->setTitle(QString());
        rb_OneOne->setText(QCoreApplication::translate("LedRGBWCtrl", "One-One", nullptr));
        rb_Loop->setText(QCoreApplication::translate("LedRGBWCtrl", "Loop", nullptr));
        label->setText(QCoreApplication::translate("LedRGBWCtrl", "DMX ID", nullptr));
        groupBox_2->setTitle(QString());
        btnRead->setText(QCoreApplication::translate("LedRGBWCtrl", "Read", nullptr));
        btnWrite->setText(QCoreApplication::translate("LedRGBWCtrl", "Write", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LedRGBWCtrl: public Ui_LedRGBWCtrl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEDRGBWCTRL_H

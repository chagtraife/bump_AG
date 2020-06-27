/********************************************************************************
** Form generated from reading UI file 'ledrgbctrl.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEDRGBCTRL_H
#define UI_LEDRGBCTRL_H

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

class Ui_LedRGBCtrl
{
public:
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QRadioButton *rbOneOne;
    QRadioButton *rb_Loop;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QPushButton *btnRead;
    QPushButton *btnWrite;
    QLabel *label;
    QLineEdit *txt_DMX_ID;

    void setupUi(QDialog *LedRGBCtrl)
    {
        if (LedRGBCtrl->objectName().isEmpty())
            LedRGBCtrl->setObjectName(QString::fromUtf8("LedRGBCtrl"));
        LedRGBCtrl->resize(371, 127);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/AG-logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        LedRGBCtrl->setWindowIcon(icon);
        groupBox = new QGroupBox(LedRGBCtrl);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(29, 19, 190, 50));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        rbOneOne = new QRadioButton(groupBox);
        rbOneOne->setObjectName(QString::fromUtf8("rbOneOne"));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        rbOneOne->setFont(font);

        horizontalLayout->addWidget(rbOneOne);

        rb_Loop = new QRadioButton(groupBox);
        rb_Loop->setObjectName(QString::fromUtf8("rb_Loop"));
        rb_Loop->setFont(font);

        horizontalLayout->addWidget(rb_Loop);

        groupBox_2 = new QGroupBox(LedRGBCtrl);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(250, 20, 101, 91));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        btnRead = new QPushButton(groupBox_2);
        btnRead->setObjectName(QString::fromUtf8("btnRead"));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        btnRead->setFont(font1);

        verticalLayout->addWidget(btnRead);

        btnWrite = new QPushButton(groupBox_2);
        btnWrite->setObjectName(QString::fromUtf8("btnWrite"));
        QFont font2;
        font2.setPointSize(12);
        btnWrite->setFont(font2);

        verticalLayout->addWidget(btnWrite);

        label = new QLabel(LedRGBCtrl);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 80, 81, 31));
        QFont font3;
        font3.setPointSize(15);
        font3.setBold(true);
        font3.setWeight(75);
        label->setFont(font3);
        txt_DMX_ID = new QLineEdit(LedRGBCtrl);
        txt_DMX_ID->setObjectName(QString::fromUtf8("txt_DMX_ID"));
        txt_DMX_ID->setGeometry(QRect(110, 80, 121, 31));

        retranslateUi(LedRGBCtrl);

        QMetaObject::connectSlotsByName(LedRGBCtrl);
    } // setupUi

    void retranslateUi(QDialog *LedRGBCtrl)
    {
        LedRGBCtrl->setWindowTitle(QCoreApplication::translate("LedRGBCtrl", "LED RGB V1.0", nullptr));
        groupBox->setTitle(QString());
        rbOneOne->setText(QCoreApplication::translate("LedRGBCtrl", "One-One", nullptr));
        rb_Loop->setText(QCoreApplication::translate("LedRGBCtrl", "Loop", nullptr));
        groupBox_2->setTitle(QString());
        btnRead->setText(QCoreApplication::translate("LedRGBCtrl", "Read", nullptr));
        btnWrite->setText(QCoreApplication::translate("LedRGBCtrl", "Write", nullptr));
        label->setText(QCoreApplication::translate("LedRGBCtrl", "DMX ID", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LedRGBCtrl: public Ui_LedRGBCtrl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEDRGBCTRL_H

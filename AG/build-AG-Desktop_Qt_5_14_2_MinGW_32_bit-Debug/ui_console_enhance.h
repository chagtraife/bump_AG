/********************************************************************************
** Form generated from reading UI file 'console_enhance.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONSOLE_ENHANCE_H
#define UI_CONSOLE_ENHANCE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Console_Enhance
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *txtFrom;
    QLabel *label_2;
    QLineEdit *txtTo;
    QLabel *label_3;
    QLineEdit *txtOffset;
    QPushButton *btnOk;

    void setupUi(QDialog *Console_Enhance)
    {
        if (Console_Enhance->objectName().isEmpty())
            Console_Enhance->setObjectName(QString::fromUtf8("Console_Enhance"));
        Console_Enhance->resize(160, 158);
        gridLayout_2 = new QGridLayout(Console_Enhance);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox = new QGroupBox(Console_Enhance);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        txtFrom = new QLineEdit(groupBox);
        txtFrom->setObjectName(QString::fromUtf8("txtFrom"));

        gridLayout->addWidget(txtFrom, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        txtTo = new QLineEdit(groupBox);
        txtTo->setObjectName(QString::fromUtf8("txtTo"));

        gridLayout->addWidget(txtTo, 1, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        txtOffset = new QLineEdit(groupBox);
        txtOffset->setObjectName(QString::fromUtf8("txtOffset"));

        gridLayout->addWidget(txtOffset, 2, 1, 1, 1);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);

        btnOk = new QPushButton(Console_Enhance);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));

        gridLayout_2->addWidget(btnOk, 1, 0, 1, 1);


        retranslateUi(Console_Enhance);

        QMetaObject::connectSlotsByName(Console_Enhance);
    } // setupUi

    void retranslateUi(QDialog *Console_Enhance)
    {
        Console_Enhance->setWindowTitle(QCoreApplication::translate("Console_Enhance", "Enhance Config", nullptr));
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("Console_Enhance", "From:", nullptr));
        label_2->setText(QCoreApplication::translate("Console_Enhance", "To:", nullptr));
        label_3->setText(QCoreApplication::translate("Console_Enhance", "Offset:", nullptr));
        btnOk->setText(QCoreApplication::translate("Console_Enhance", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Console_Enhance: public Ui_Console_Enhance {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONSOLE_ENHANCE_H
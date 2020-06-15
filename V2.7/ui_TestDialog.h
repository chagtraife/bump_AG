/********************************************************************************
** Form generated from reading UI file 'TestDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTDIALOG_H
#define UI_TESTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TestDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLCDNumber *lcd_TimeRemain;
    QPushButton *Btn_Test1;
    QPushButton *Btn_Test2;
    QPushButton *Btn_Test3;
    QPushButton *Btn_Test4;

    void setupUi(QDialog *TestDialog)
    {
        if (TestDialog->objectName().isEmpty())
            TestDialog->setObjectName(QStringLiteral("TestDialog"));
        TestDialog->resize(151, 190);
        verticalLayout = new QVBoxLayout(TestDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lcd_TimeRemain = new QLCDNumber(TestDialog);
        lcd_TimeRemain->setObjectName(QStringLiteral("lcd_TimeRemain"));
        lcd_TimeRemain->setProperty("intValue", QVariant(0));

        verticalLayout->addWidget(lcd_TimeRemain);

        Btn_Test1 = new QPushButton(TestDialog);
        Btn_Test1->setObjectName(QStringLiteral("Btn_Test1"));

        verticalLayout->addWidget(Btn_Test1);

        Btn_Test2 = new QPushButton(TestDialog);
        Btn_Test2->setObjectName(QStringLiteral("Btn_Test2"));

        verticalLayout->addWidget(Btn_Test2);

        Btn_Test3 = new QPushButton(TestDialog);
        Btn_Test3->setObjectName(QStringLiteral("Btn_Test3"));

        verticalLayout->addWidget(Btn_Test3);

        Btn_Test4 = new QPushButton(TestDialog);
        Btn_Test4->setObjectName(QStringLiteral("Btn_Test4"));

        verticalLayout->addWidget(Btn_Test4);


        retranslateUi(TestDialog);

        QMetaObject::connectSlotsByName(TestDialog);
    } // setupUi

    void retranslateUi(QDialog *TestDialog)
    {
        TestDialog->setWindowTitle(QApplication::translate("TestDialog", "Test Mode", 0));
        Btn_Test1->setText(QApplication::translate("TestDialog", "Test 1", 0));
        Btn_Test2->setText(QApplication::translate("TestDialog", "Test 2", 0));
        Btn_Test3->setText(QApplication::translate("TestDialog", "Test 3", 0));
        Btn_Test4->setText(QApplication::translate("TestDialog", "Test 4", 0));
    } // retranslateUi

};

namespace Ui {
    class TestDialog: public Ui_TestDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTDIALOG_H

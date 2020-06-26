/********************************************************************************
** Form generated from reading UI file 'thresholdmanagersetting.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THRESHOLDMANAGERSETTING_H
#define UI_THRESHOLDMANAGERSETTING_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ThresholdManagerSetting
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLineEdit *txt_Min;
    QLabel *label;
    QLabel *label_2;
    QPushButton *btnSetMin;
    QLineEdit *txt_Max;
    QPushButton *btnSetMax;

    void setupUi(QDialog *ThresholdManagerSetting)
    {
        if (ThresholdManagerSetting->objectName().isEmpty())
            ThresholdManagerSetting->setObjectName(QString::fromUtf8("ThresholdManagerSetting"));
        ThresholdManagerSetting->resize(346, 152);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/AG-logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        ThresholdManagerSetting->setWindowIcon(icon);
        gridLayout_2 = new QGridLayout(ThresholdManagerSetting);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox = new QGroupBox(ThresholdManagerSetting);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        txt_Min = new QLineEdit(groupBox);
        txt_Min->setObjectName(QString::fromUtf8("txt_Min"));

        gridLayout->addWidget(txt_Min, 0, 1, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        btnSetMin = new QPushButton(groupBox);
        btnSetMin->setObjectName(QString::fromUtf8("btnSetMin"));

        gridLayout->addWidget(btnSetMin, 0, 2, 1, 1);

        txt_Max = new QLineEdit(groupBox);
        txt_Max->setObjectName(QString::fromUtf8("txt_Max"));

        gridLayout->addWidget(txt_Max, 2, 1, 1, 1);

        btnSetMax = new QPushButton(groupBox);
        btnSetMax->setObjectName(QString::fromUtf8("btnSetMax"));

        gridLayout->addWidget(btnSetMax, 2, 2, 1, 1);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);


        retranslateUi(ThresholdManagerSetting);

        QMetaObject::connectSlotsByName(ThresholdManagerSetting);
    } // setupUi

    void retranslateUi(QDialog *ThresholdManagerSetting)
    {
        ThresholdManagerSetting->setWindowTitle(QCoreApplication::translate("ThresholdManagerSetting", "Threshold Manager Setting", nullptr));
        groupBox->setTitle(QCoreApplication::translate("ThresholdManagerSetting", "Customer", nullptr));
        label->setText(QCoreApplication::translate("ThresholdManagerSetting", "Min", nullptr));
        label_2->setText(QCoreApplication::translate("ThresholdManagerSetting", "Max", nullptr));
        btnSetMin->setText(QCoreApplication::translate("ThresholdManagerSetting", "OK", nullptr));
        btnSetMax->setText(QCoreApplication::translate("ThresholdManagerSetting", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ThresholdManagerSetting: public Ui_ThresholdManagerSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THRESHOLDMANAGERSETTING_H

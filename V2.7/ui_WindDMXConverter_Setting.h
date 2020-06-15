/********************************************************************************
** Form generated from reading UI file 'WindDMXConverter_Setting.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDDMXCONVERTER_SETTING_H
#define UI_WINDDMXCONVERTER_SETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_WindDMXConverter_Setting
{
public:
    QHBoxLayout *horizontalLayout;
    QTableView *tableView_DMXMap;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QPushButton *Btn_ReadFromDev;
    QPushButton *Btn_WriteToDev;
    QPushButton *Btn_Cancel;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *WindDMXConverter_Setting)
    {
        if (WindDMXConverter_Setting->objectName().isEmpty())
            WindDMXConverter_Setting->setObjectName(QStringLiteral("WindDMXConverter_Setting"));
        WindDMXConverter_Setting->resize(820, 367);
        horizontalLayout = new QHBoxLayout(WindDMXConverter_Setting);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tableView_DMXMap = new QTableView(WindDMXConverter_Setting);
        tableView_DMXMap->setObjectName(QStringLiteral("tableView_DMXMap"));
        tableView_DMXMap->setContextMenuPolicy(Qt::CustomContextMenu);
        tableView_DMXMap->horizontalHeader()->setDefaultSectionSize(33);

        horizontalLayout->addWidget(tableView_DMXMap);

        groupBox = new QGroupBox(WindDMXConverter_Setting);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        Btn_ReadFromDev = new QPushButton(groupBox);
        Btn_ReadFromDev->setObjectName(QStringLiteral("Btn_ReadFromDev"));

        verticalLayout->addWidget(Btn_ReadFromDev);

        Btn_WriteToDev = new QPushButton(groupBox);
        Btn_WriteToDev->setObjectName(QStringLiteral("Btn_WriteToDev"));

        verticalLayout->addWidget(Btn_WriteToDev);

        Btn_Cancel = new QPushButton(groupBox);
        Btn_Cancel->setObjectName(QStringLiteral("Btn_Cancel"));

        verticalLayout->addWidget(Btn_Cancel);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addWidget(groupBox);


        retranslateUi(WindDMXConverter_Setting);

        QMetaObject::connectSlotsByName(WindDMXConverter_Setting);
    } // setupUi

    void retranslateUi(QDialog *WindDMXConverter_Setting)
    {
        WindDMXConverter_Setting->setWindowTitle(QApplication::translate("WindDMXConverter_Setting", "Dialog", 0));
        groupBox->setTitle(QString());
        Btn_ReadFromDev->setText(QApplication::translate("WindDMXConverter_Setting", "Read device", 0));
        Btn_WriteToDev->setText(QApplication::translate("WindDMXConverter_Setting", "Write to device", 0));
        Btn_Cancel->setText(QApplication::translate("WindDMXConverter_Setting", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class WindDMXConverter_Setting: public Ui_WindDMXConverter_Setting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDDMXCONVERTER_SETTING_H

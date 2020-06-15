/********************************************************************************
** Form generated from reading UI file 'dmx_monitor.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DMX_MONITOR_H
#define UI_DMX_MONITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DMX_Monitor
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *txt_DMXinfo;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QTableView *tableView_DMXval;
    QGroupBox *DMX_Recorder;
    QGridLayout *gridLayout_2;
    QLineEdit *txt_RecordedChannel;
    QLabel *label_3;
    QPushButton *btn_Rec;
    QLabel *label;
    QLineEdit *txt_SampleRate;
    QPushButton *btn_Export;
    QSpacerItem *horizontalSpacer;
    QLabel *txt_Status;

    void setupUi(QDialog *DMX_Monitor)
    {
        if (DMX_Monitor->objectName().isEmpty())
            DMX_Monitor->setObjectName(QStringLiteral("DMX_Monitor"));
        DMX_Monitor->resize(713, 446);
        verticalLayout = new QVBoxLayout(DMX_Monitor);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(DMX_Monitor);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMaximumSize(QSize(16777215, 100));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        txt_DMXinfo = new QTextEdit(groupBox);
        txt_DMXinfo->setObjectName(QStringLiteral("txt_DMXinfo"));

        verticalLayout_2->addWidget(txt_DMXinfo);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(DMX_Monitor);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tableView_DMXval = new QTableView(groupBox_2);
        tableView_DMXval->setObjectName(QStringLiteral("tableView_DMXval"));
        tableView_DMXval->setToolTipDuration(500);
        tableView_DMXval->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView_DMXval->setAlternatingRowColors(true);
        tableView_DMXval->horizontalHeader()->setDefaultSectionSize(33);

        gridLayout->addWidget(tableView_DMXval, 0, 0, 1, 1);

        DMX_Recorder = new QGroupBox(groupBox_2);
        DMX_Recorder->setObjectName(QStringLiteral("DMX_Recorder"));
        gridLayout_2 = new QGridLayout(DMX_Recorder);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        txt_RecordedChannel = new QLineEdit(DMX_Recorder);
        txt_RecordedChannel->setObjectName(QStringLiteral("txt_RecordedChannel"));
        txt_RecordedChannel->setMaximumSize(QSize(100, 16777215));

        gridLayout_2->addWidget(txt_RecordedChannel, 0, 3, 1, 1);

        label_3 = new QLabel(DMX_Recorder);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 0, 2, 1, 1);

        btn_Rec = new QPushButton(DMX_Recorder);
        btn_Rec->setObjectName(QStringLiteral("btn_Rec"));

        gridLayout_2->addWidget(btn_Rec, 0, 5, 1, 1);

        label = new QLabel(DMX_Recorder);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        txt_SampleRate = new QLineEdit(DMX_Recorder);
        txt_SampleRate->setObjectName(QStringLiteral("txt_SampleRate"));
        txt_SampleRate->setMaximumSize(QSize(100, 16777215));

        gridLayout_2->addWidget(txt_SampleRate, 0, 1, 1, 1);

        btn_Export = new QPushButton(DMX_Recorder);
        btn_Export->setObjectName(QStringLiteral("btn_Export"));

        gridLayout_2->addWidget(btn_Export, 0, 6, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 4, 1, 1);

        txt_Status = new QLabel(DMX_Recorder);
        txt_Status->setObjectName(QStringLiteral("txt_Status"));

        gridLayout_2->addWidget(txt_Status, 1, 0, 1, 1);


        gridLayout->addWidget(DMX_Recorder, 1, 0, 1, 1);


        verticalLayout->addWidget(groupBox_2);


        retranslateUi(DMX_Monitor);

        QMetaObject::connectSlotsByName(DMX_Monitor);
    } // setupUi

    void retranslateUi(QDialog *DMX_Monitor)
    {
        DMX_Monitor->setWindowTitle(QApplication::translate("DMX_Monitor", "DMX monitor", 0));
        groupBox->setTitle(QApplication::translate("DMX_Monitor", "DMX verification", 0));
        groupBox_2->setTitle(QApplication::translate("DMX_Monitor", "DMX view", 0));
#ifndef QT_NO_TOOLTIP
        tableView_DMXval->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        DMX_Recorder->setTitle(QApplication::translate("DMX_Monitor", "DMX recorder", 0));
        txt_RecordedChannel->setText(QApplication::translate("DMX_Monitor", "1-7", 0));
        label_3->setText(QApplication::translate("DMX_Monitor", "Recorded channel", 0));
        btn_Rec->setText(QApplication::translate("DMX_Monitor", "Record", 0));
        label->setText(QApplication::translate("DMX_Monitor", "Sample rate (fps)", 0));
        txt_SampleRate->setText(QApplication::translate("DMX_Monitor", "1", 0));
        btn_Export->setText(QApplication::translate("DMX_Monitor", "Export", 0));
        txt_Status->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DMX_Monitor: public Ui_DMX_Monitor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DMX_MONITOR_H

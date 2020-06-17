/********************************************************************************
** Form generated from reading UI file 'dmx_monitor.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DMX_MONITOR_H
#define UI_DMX_MONITOR_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
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
            DMX_Monitor->setObjectName(QString::fromUtf8("DMX_Monitor"));
        DMX_Monitor->resize(713, 446);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/AG-logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        DMX_Monitor->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(DMX_Monitor);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(DMX_Monitor);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMaximumSize(QSize(16777215, 100));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        txt_DMXinfo = new QTextEdit(groupBox);
        txt_DMXinfo->setObjectName(QString::fromUtf8("txt_DMXinfo"));

        verticalLayout_2->addWidget(txt_DMXinfo);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(DMX_Monitor);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableView_DMXval = new QTableView(groupBox_2);
        tableView_DMXval->setObjectName(QString::fromUtf8("tableView_DMXval"));
        tableView_DMXval->setToolTipDuration(500);
        tableView_DMXval->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView_DMXval->setAlternatingRowColors(true);
        tableView_DMXval->horizontalHeader()->setDefaultSectionSize(35);

        gridLayout->addWidget(tableView_DMXval, 0, 0, 1, 1);

        DMX_Recorder = new QGroupBox(groupBox_2);
        DMX_Recorder->setObjectName(QString::fromUtf8("DMX_Recorder"));
        gridLayout_2 = new QGridLayout(DMX_Recorder);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        txt_RecordedChannel = new QLineEdit(DMX_Recorder);
        txt_RecordedChannel->setObjectName(QString::fromUtf8("txt_RecordedChannel"));
        txt_RecordedChannel->setMaximumSize(QSize(100, 16777215));

        gridLayout_2->addWidget(txt_RecordedChannel, 0, 3, 1, 1);

        label_3 = new QLabel(DMX_Recorder);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 0, 2, 1, 1);

        btn_Rec = new QPushButton(DMX_Recorder);
        btn_Rec->setObjectName(QString::fromUtf8("btn_Rec"));

        gridLayout_2->addWidget(btn_Rec, 0, 5, 1, 1);

        label = new QLabel(DMX_Recorder);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        txt_SampleRate = new QLineEdit(DMX_Recorder);
        txt_SampleRate->setObjectName(QString::fromUtf8("txt_SampleRate"));
        txt_SampleRate->setMaximumSize(QSize(100, 16777215));

        gridLayout_2->addWidget(txt_SampleRate, 0, 1, 1, 1);

        btn_Export = new QPushButton(DMX_Recorder);
        btn_Export->setObjectName(QString::fromUtf8("btn_Export"));

        gridLayout_2->addWidget(btn_Export, 0, 6, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 4, 1, 1);

        txt_Status = new QLabel(DMX_Recorder);
        txt_Status->setObjectName(QString::fromUtf8("txt_Status"));

        gridLayout_2->addWidget(txt_Status, 1, 0, 1, 1);


        gridLayout->addWidget(DMX_Recorder, 1, 0, 1, 1);


        verticalLayout->addWidget(groupBox_2);


        retranslateUi(DMX_Monitor);

        QMetaObject::connectSlotsByName(DMX_Monitor);
    } // setupUi

    void retranslateUi(QDialog *DMX_Monitor)
    {
        DMX_Monitor->setWindowTitle(QCoreApplication::translate("DMX_Monitor", "DMX monitor", nullptr));
        groupBox->setTitle(QCoreApplication::translate("DMX_Monitor", "DMX verification", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("DMX_Monitor", "DMX view", nullptr));
#if QT_CONFIG(tooltip)
        tableView_DMXval->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        DMX_Recorder->setTitle(QCoreApplication::translate("DMX_Monitor", "DMX recorder", nullptr));
        txt_RecordedChannel->setText(QCoreApplication::translate("DMX_Monitor", "1-7", nullptr));
        label_3->setText(QCoreApplication::translate("DMX_Monitor", "Recorded channel", nullptr));
        btn_Rec->setText(QCoreApplication::translate("DMX_Monitor", "Record", nullptr));
        label->setText(QCoreApplication::translate("DMX_Monitor", "Sample rate (fps)", nullptr));
        txt_SampleRate->setText(QCoreApplication::translate("DMX_Monitor", "1", nullptr));
        btn_Export->setText(QCoreApplication::translate("DMX_Monitor", "Export", nullptr));
        txt_Status->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DMX_Monitor: public Ui_DMX_Monitor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DMX_MONITOR_H

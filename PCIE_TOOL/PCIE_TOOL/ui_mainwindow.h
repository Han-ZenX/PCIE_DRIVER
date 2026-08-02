/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab_5;
    QGridLayout *gridLayout_23;
    QGroupBox *groupBox_15;
    QGridLayout *gridLayout_16;
    QPushButton *pushButton;
    QPushButton *reset_btn;
    QPushButton *Init_btn;
    QPushButton *START_btn;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_6;
    QComboBox *Register_comboBox;
    QLabel *label_2;
    QSpinBox *SetRgister_Data_box;
    QPushButton *SetRgister_btn;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox_17;
    QGridLayout *gridLayout_18;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_5;
    QLabel *label_3;
    QLineEdit *Temp_lineEdit;
    QPushButton *GetTemp_btn;
    QGroupBox *groupBox_10;
    QGridLayout *gridLayout_11;
    QLineEdit *OFFSET_lineEdit;
    QPushButton *GetOFFSET_btn;
    QGroupBox *groupBox_9;
    QGridLayout *gridLayout_10;
    QLabel *label_15;
    QLineEdit *VCC_lineEdit;
    QPushButton *GetVCC_btn;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_3;
    QPushButton *GetVREF_btn;
    QLabel *label_5;
    QLineEdit *VREF_lineEdit;
    QGroupBox *groupBox_13;
    QGridLayout *gridLayout_20;
    QPushButton *GetGAIN_btn;
    QLineEdit *GAIN_lineEdit;
    QGroupBox *groupBox_18;
    QGridLayout *gridLayout_19;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_7;
    QLineEdit *AIN2_lineEdit;
    QPushButton *GetAIN2_btn;
    QComboBox *AIN2_combox;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QPushButton *GetAIN1_btn;
    QLineEdit *AIN1_lineEdit;
    QComboBox *AIN1_combox;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_8;
    QPushButton *GetAIN3_btn;
    QLineEdit *AIN3_lineEdit;
    QComboBox *AIN3_combox;
    QGroupBox *groupBox_16;
    QGridLayout *gridLayout_17;
    QPushButton *GetAIN0_btn;
    QLineEdit *AIN0_lineEdit;
    QComboBox *AIN0_combox;
    QGroupBox *groupBox_8;
    QGridLayout *gridLayout_9;
    QLineEdit *AIN4_lineEdit;
    QPushButton *GetAIN4_btn;
    QComboBox *AIN4_combox;
    QGroupBox *groupBox_12;
    QGridLayout *gridLayout_13;
    QGroupBox *DUT_Box;
    QGridLayout *gridLayout_14;
    QPushButton *DUT4_btn;
    QPushButton *DUT3_btn;
    QPushButton *DUT1_btn;
    QPushButton *DUT2_btn;
    QGroupBox *CURR_Box;
    QGridLayout *gridLayout_15;
    QPushButton *CURR3_btn;
    QPushButton *CURR2_btn;
    QPushButton *CURR1_btn;
    QPushButton *CURR4_btn;
    QGroupBox *groupBox_11;
    QGridLayout *gridLayout_12;
    QPushButton *ReadRegister_btn;
    QPushButton *ReadChannelData_btn;
    QGroupBox *groupBox_14;
    QGridLayout *gridLayout_21;
    QGroupBox *groupBox_19;
    QGridLayout *gridLayout_22;
    QComboBox *AUTO_SCAN_DRATE_combox;
    QLabel *label_4;
    QPushButton *AUTO_SCAN_DRATE_SET_btn;
    QWidget *tab_6;
    QComboBox *combox_dut_select;
    QTableWidget *tableWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(962, 484);
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font.setBold(true);
        font.setWeight(75);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setSpacing(3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(3, 3, 3, 3);
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        gridLayout_23 = new QGridLayout(tab_5);
        gridLayout_23->setObjectName(QString::fromUtf8("gridLayout_23"));
        groupBox_15 = new QGroupBox(tab_5);
        groupBox_15->setObjectName(QString::fromUtf8("groupBox_15"));
        gridLayout_16 = new QGridLayout(groupBox_15);
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        pushButton = new QPushButton(groupBox_15);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_16->addWidget(pushButton, 1, 0, 1, 1);

        reset_btn = new QPushButton(groupBox_15);
        reset_btn->setObjectName(QString::fromUtf8("reset_btn"));

        gridLayout_16->addWidget(reset_btn, 0, 0, 1, 1);

        Init_btn = new QPushButton(groupBox_15);
        Init_btn->setObjectName(QString::fromUtf8("Init_btn"));

        gridLayout_16->addWidget(Init_btn, 0, 1, 1, 1);

        START_btn = new QPushButton(groupBox_15);
        START_btn->setObjectName(QString::fromUtf8("START_btn"));

        gridLayout_16->addWidget(START_btn, 1, 1, 1, 1);


        gridLayout_23->addWidget(groupBox_15, 0, 0, 1, 1);

        groupBox_5 = new QGroupBox(tab_5);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        gridLayout_6 = new QGridLayout(groupBox_5);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setHorizontalSpacing(5);
        gridLayout_6->setContentsMargins(5, 5, 5, 5);
        Register_comboBox = new QComboBox(groupBox_5);
        Register_comboBox->addItem(QString());
        Register_comboBox->addItem(QString());
        Register_comboBox->addItem(QString());
        Register_comboBox->addItem(QString());
        Register_comboBox->addItem(QString());
        Register_comboBox->addItem(QString());
        Register_comboBox->addItem(QString());
        Register_comboBox->addItem(QString());
        Register_comboBox->addItem(QString());
        Register_comboBox->addItem(QString());
        Register_comboBox->setObjectName(QString::fromUtf8("Register_comboBox"));

        gridLayout_6->addWidget(Register_comboBox, 0, 0, 1, 2);

        label_2 = new QLabel(groupBox_5);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_2, 1, 0, 1, 1);

        SetRgister_Data_box = new QSpinBox(groupBox_5);
        SetRgister_Data_box->setObjectName(QString::fromUtf8("SetRgister_Data_box"));
        SetRgister_Data_box->setMaximum(256);

        gridLayout_6->addWidget(SetRgister_Data_box, 1, 1, 1, 1);

        SetRgister_btn = new QPushButton(groupBox_5);
        SetRgister_btn->setObjectName(QString::fromUtf8("SetRgister_btn"));

        gridLayout_6->addWidget(SetRgister_btn, 2, 0, 1, 2);


        gridLayout_23->addWidget(groupBox_5, 0, 1, 1, 1);

        groupBox_2 = new QGroupBox(tab_5);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_4 = new QGridLayout(groupBox_2);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        groupBox_17 = new QGroupBox(groupBox_2);
        groupBox_17->setObjectName(QString::fromUtf8("groupBox_17"));
        gridLayout_18 = new QGridLayout(groupBox_17);
        gridLayout_18->setObjectName(QString::fromUtf8("gridLayout_18"));
        groupBox_3 = new QGroupBox(groupBox_17);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_5 = new QGridLayout(groupBox_3);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_3, 0, 2, 1, 1);

        Temp_lineEdit = new QLineEdit(groupBox_3);
        Temp_lineEdit->setObjectName(QString::fromUtf8("Temp_lineEdit"));
        Temp_lineEdit->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(Temp_lineEdit, 0, 1, 1, 1);

        GetTemp_btn = new QPushButton(groupBox_3);
        GetTemp_btn->setObjectName(QString::fromUtf8("GetTemp_btn"));

        gridLayout_5->addWidget(GetTemp_btn, 0, 0, 1, 1);


        gridLayout_18->addWidget(groupBox_3, 0, 0, 1, 1);

        groupBox_10 = new QGroupBox(groupBox_17);
        groupBox_10->setObjectName(QString::fromUtf8("groupBox_10"));
        gridLayout_11 = new QGridLayout(groupBox_10);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        OFFSET_lineEdit = new QLineEdit(groupBox_10);
        OFFSET_lineEdit->setObjectName(QString::fromUtf8("OFFSET_lineEdit"));
        OFFSET_lineEdit->setAlignment(Qt::AlignCenter);

        gridLayout_11->addWidget(OFFSET_lineEdit, 0, 1, 1, 1);

        GetOFFSET_btn = new QPushButton(groupBox_10);
        GetOFFSET_btn->setObjectName(QString::fromUtf8("GetOFFSET_btn"));

        gridLayout_11->addWidget(GetOFFSET_btn, 0, 0, 1, 1);


        gridLayout_18->addWidget(groupBox_10, 4, 0, 1, 1);

        groupBox_9 = new QGroupBox(groupBox_17);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        gridLayout_10 = new QGridLayout(groupBox_9);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        label_15 = new QLabel(groupBox_9);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setAlignment(Qt::AlignCenter);

        gridLayout_10->addWidget(label_15, 0, 2, 1, 1);

        VCC_lineEdit = new QLineEdit(groupBox_9);
        VCC_lineEdit->setObjectName(QString::fromUtf8("VCC_lineEdit"));
        VCC_lineEdit->setAlignment(Qt::AlignCenter);

        gridLayout_10->addWidget(VCC_lineEdit, 0, 1, 1, 1);

        GetVCC_btn = new QPushButton(groupBox_9);
        GetVCC_btn->setObjectName(QString::fromUtf8("GetVCC_btn"));

        gridLayout_10->addWidget(GetVCC_btn, 0, 0, 1, 1);


        gridLayout_18->addWidget(groupBox_9, 2, 0, 1, 1);

        groupBox_4 = new QGroupBox(groupBox_17);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout_3 = new QGridLayout(groupBox_4);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        GetVREF_btn = new QPushButton(groupBox_4);
        GetVREF_btn->setObjectName(QString::fromUtf8("GetVREF_btn"));

        gridLayout_3->addWidget(GetVREF_btn, 0, 0, 1, 1);

        label_5 = new QLabel(groupBox_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_3->addWidget(label_5, 0, 2, 1, 1);

        VREF_lineEdit = new QLineEdit(groupBox_4);
        VREF_lineEdit->setObjectName(QString::fromUtf8("VREF_lineEdit"));
        VREF_lineEdit->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(VREF_lineEdit, 0, 1, 1, 1);


        gridLayout_18->addWidget(groupBox_4, 1, 0, 1, 1);

        groupBox_13 = new QGroupBox(groupBox_17);
        groupBox_13->setObjectName(QString::fromUtf8("groupBox_13"));
        gridLayout_20 = new QGridLayout(groupBox_13);
        gridLayout_20->setObjectName(QString::fromUtf8("gridLayout_20"));
        GetGAIN_btn = new QPushButton(groupBox_13);
        GetGAIN_btn->setObjectName(QString::fromUtf8("GetGAIN_btn"));

        gridLayout_20->addWidget(GetGAIN_btn, 0, 0, 1, 1);

        GAIN_lineEdit = new QLineEdit(groupBox_13);
        GAIN_lineEdit->setObjectName(QString::fromUtf8("GAIN_lineEdit"));
        GAIN_lineEdit->setAlignment(Qt::AlignCenter);

        gridLayout_20->addWidget(GAIN_lineEdit, 0, 1, 1, 1);


        gridLayout_18->addWidget(groupBox_13, 3, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_17, 0, 0, 3, 1);

        groupBox_18 = new QGroupBox(groupBox_2);
        groupBox_18->setObjectName(QString::fromUtf8("groupBox_18"));
        gridLayout_19 = new QGridLayout(groupBox_18);
        gridLayout_19->setObjectName(QString::fromUtf8("gridLayout_19"));
        groupBox_6 = new QGroupBox(groupBox_18);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        gridLayout_7 = new QGridLayout(groupBox_6);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        AIN2_lineEdit = new QLineEdit(groupBox_6);
        AIN2_lineEdit->setObjectName(QString::fromUtf8("AIN2_lineEdit"));
        AIN2_lineEdit->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(AIN2_lineEdit, 0, 1, 1, 1);

        GetAIN2_btn = new QPushButton(groupBox_6);
        GetAIN2_btn->setObjectName(QString::fromUtf8("GetAIN2_btn"));

        gridLayout_7->addWidget(GetAIN2_btn, 0, 0, 1, 1);

        AIN2_combox = new QComboBox(groupBox_6);
        AIN2_combox->addItem(QString());
        AIN2_combox->addItem(QString());
        AIN2_combox->addItem(QString());
        AIN2_combox->setObjectName(QString::fromUtf8("AIN2_combox"));

        gridLayout_7->addWidget(AIN2_combox, 0, 2, 1, 1);


        gridLayout_19->addWidget(groupBox_6, 2, 0, 1, 1);

        groupBox = new QGroupBox(groupBox_18);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        GetAIN1_btn = new QPushButton(groupBox);
        GetAIN1_btn->setObjectName(QString::fromUtf8("GetAIN1_btn"));

        gridLayout_2->addWidget(GetAIN1_btn, 0, 0, 1, 1);

        AIN1_lineEdit = new QLineEdit(groupBox);
        AIN1_lineEdit->setObjectName(QString::fromUtf8("AIN1_lineEdit"));
        AIN1_lineEdit->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(AIN1_lineEdit, 0, 1, 1, 1);

        AIN1_combox = new QComboBox(groupBox);
        AIN1_combox->addItem(QString());
        AIN1_combox->addItem(QString());
        AIN1_combox->addItem(QString());
        AIN1_combox->setObjectName(QString::fromUtf8("AIN1_combox"));

        gridLayout_2->addWidget(AIN1_combox, 0, 2, 1, 1);


        gridLayout_19->addWidget(groupBox, 1, 0, 1, 1);

        groupBox_7 = new QGroupBox(groupBox_18);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        gridLayout_8 = new QGridLayout(groupBox_7);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        GetAIN3_btn = new QPushButton(groupBox_7);
        GetAIN3_btn->setObjectName(QString::fromUtf8("GetAIN3_btn"));

        gridLayout_8->addWidget(GetAIN3_btn, 0, 0, 1, 1);

        AIN3_lineEdit = new QLineEdit(groupBox_7);
        AIN3_lineEdit->setObjectName(QString::fromUtf8("AIN3_lineEdit"));
        AIN3_lineEdit->setAlignment(Qt::AlignCenter);

        gridLayout_8->addWidget(AIN3_lineEdit, 0, 1, 1, 1);

        AIN3_combox = new QComboBox(groupBox_7);
        AIN3_combox->addItem(QString());
        AIN3_combox->addItem(QString());
        AIN3_combox->addItem(QString());
        AIN3_combox->setObjectName(QString::fromUtf8("AIN3_combox"));

        gridLayout_8->addWidget(AIN3_combox, 0, 2, 1, 1);


        gridLayout_19->addWidget(groupBox_7, 3, 0, 1, 1);

        groupBox_16 = new QGroupBox(groupBox_18);
        groupBox_16->setObjectName(QString::fromUtf8("groupBox_16"));
        gridLayout_17 = new QGridLayout(groupBox_16);
        gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        GetAIN0_btn = new QPushButton(groupBox_16);
        GetAIN0_btn->setObjectName(QString::fromUtf8("GetAIN0_btn"));

        gridLayout_17->addWidget(GetAIN0_btn, 0, 0, 1, 1);

        AIN0_lineEdit = new QLineEdit(groupBox_16);
        AIN0_lineEdit->setObjectName(QString::fromUtf8("AIN0_lineEdit"));
        AIN0_lineEdit->setAlignment(Qt::AlignCenter);

        gridLayout_17->addWidget(AIN0_lineEdit, 0, 1, 1, 1);

        AIN0_combox = new QComboBox(groupBox_16);
        AIN0_combox->addItem(QString());
        AIN0_combox->addItem(QString());
        AIN0_combox->addItem(QString());
        AIN0_combox->setObjectName(QString::fromUtf8("AIN0_combox"));

        gridLayout_17->addWidget(AIN0_combox, 0, 2, 1, 1);


        gridLayout_19->addWidget(groupBox_16, 0, 0, 1, 1);

        groupBox_8 = new QGroupBox(groupBox_18);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        gridLayout_9 = new QGridLayout(groupBox_8);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        AIN4_lineEdit = new QLineEdit(groupBox_8);
        AIN4_lineEdit->setObjectName(QString::fromUtf8("AIN4_lineEdit"));
        AIN4_lineEdit->setAlignment(Qt::AlignCenter);

        gridLayout_9->addWidget(AIN4_lineEdit, 0, 1, 1, 1);

        GetAIN4_btn = new QPushButton(groupBox_8);
        GetAIN4_btn->setObjectName(QString::fromUtf8("GetAIN4_btn"));

        gridLayout_9->addWidget(GetAIN4_btn, 0, 0, 1, 1);

        AIN4_combox = new QComboBox(groupBox_8);
        AIN4_combox->addItem(QString());
        AIN4_combox->addItem(QString());
        AIN4_combox->addItem(QString());
        AIN4_combox->setObjectName(QString::fromUtf8("AIN4_combox"));

        gridLayout_9->addWidget(AIN4_combox, 0, 2, 1, 1);


        gridLayout_19->addWidget(groupBox_8, 4, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_18, 0, 1, 3, 1);


        gridLayout_23->addWidget(groupBox_2, 0, 2, 3, 1);

        groupBox_12 = new QGroupBox(tab_5);
        groupBox_12->setObjectName(QString::fromUtf8("groupBox_12"));
        gridLayout_13 = new QGridLayout(groupBox_12);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        DUT_Box = new QGroupBox(groupBox_12);
        DUT_Box->setObjectName(QString::fromUtf8("DUT_Box"));
        gridLayout_14 = new QGridLayout(DUT_Box);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        DUT4_btn = new QPushButton(DUT_Box);
        DUT4_btn->setObjectName(QString::fromUtf8("DUT4_btn"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        DUT4_btn->setFont(font1);

        gridLayout_14->addWidget(DUT4_btn, 3, 0, 1, 1);

        DUT3_btn = new QPushButton(DUT_Box);
        DUT3_btn->setObjectName(QString::fromUtf8("DUT3_btn"));
        DUT3_btn->setFont(font1);

        gridLayout_14->addWidget(DUT3_btn, 2, 0, 1, 1);

        DUT1_btn = new QPushButton(DUT_Box);
        DUT1_btn->setObjectName(QString::fromUtf8("DUT1_btn"));
        DUT1_btn->setFont(font1);

        gridLayout_14->addWidget(DUT1_btn, 0, 0, 1, 1);

        DUT2_btn = new QPushButton(DUT_Box);
        DUT2_btn->setObjectName(QString::fromUtf8("DUT2_btn"));
        DUT2_btn->setFont(font1);

        gridLayout_14->addWidget(DUT2_btn, 1, 0, 1, 1);


        gridLayout_13->addWidget(DUT_Box, 0, 0, 1, 1);

        CURR_Box = new QGroupBox(groupBox_12);
        CURR_Box->setObjectName(QString::fromUtf8("CURR_Box"));
        gridLayout_15 = new QGridLayout(CURR_Box);
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        CURR3_btn = new QPushButton(CURR_Box);
        CURR3_btn->setObjectName(QString::fromUtf8("CURR3_btn"));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        CURR3_btn->setFont(font2);

        gridLayout_15->addWidget(CURR3_btn, 2, 0, 1, 1);

        CURR2_btn = new QPushButton(CURR_Box);
        CURR2_btn->setObjectName(QString::fromUtf8("CURR2_btn"));
        CURR2_btn->setFont(font2);

        gridLayout_15->addWidget(CURR2_btn, 1, 0, 1, 1);

        CURR1_btn = new QPushButton(CURR_Box);
        CURR1_btn->setObjectName(QString::fromUtf8("CURR1_btn"));
        CURR1_btn->setFont(font2);

        gridLayout_15->addWidget(CURR1_btn, 0, 0, 1, 1);

        CURR4_btn = new QPushButton(CURR_Box);
        CURR4_btn->setObjectName(QString::fromUtf8("CURR4_btn"));
        CURR4_btn->setFont(font2);

        gridLayout_15->addWidget(CURR4_btn, 3, 0, 1, 1);


        gridLayout_13->addWidget(CURR_Box, 0, 1, 1, 1);


        gridLayout_23->addWidget(groupBox_12, 1, 0, 2, 1);

        groupBox_11 = new QGroupBox(tab_5);
        groupBox_11->setObjectName(QString::fromUtf8("groupBox_11"));
        gridLayout_12 = new QGridLayout(groupBox_11);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        ReadRegister_btn = new QPushButton(groupBox_11);
        ReadRegister_btn->setObjectName(QString::fromUtf8("ReadRegister_btn"));

        gridLayout_12->addWidget(ReadRegister_btn, 0, 0, 1, 1);

        ReadChannelData_btn = new QPushButton(groupBox_11);
        ReadChannelData_btn->setObjectName(QString::fromUtf8("ReadChannelData_btn"));

        gridLayout_12->addWidget(ReadChannelData_btn, 1, 0, 1, 1);


        gridLayout_23->addWidget(groupBox_11, 1, 1, 1, 1);

        groupBox_14 = new QGroupBox(tab_5);
        groupBox_14->setObjectName(QString::fromUtf8("groupBox_14"));
        gridLayout_21 = new QGridLayout(groupBox_14);
        gridLayout_21->setObjectName(QString::fromUtf8("gridLayout_21"));
        groupBox_19 = new QGroupBox(groupBox_14);
        groupBox_19->setObjectName(QString::fromUtf8("groupBox_19"));
        gridLayout_22 = new QGridLayout(groupBox_19);
        gridLayout_22->setObjectName(QString::fromUtf8("gridLayout_22"));
        AUTO_SCAN_DRATE_combox = new QComboBox(groupBox_19);
        AUTO_SCAN_DRATE_combox->addItem(QString());
        AUTO_SCAN_DRATE_combox->addItem(QString());
        AUTO_SCAN_DRATE_combox->addItem(QString());
        AUTO_SCAN_DRATE_combox->addItem(QString());
        AUTO_SCAN_DRATE_combox->setObjectName(QString::fromUtf8("AUTO_SCAN_DRATE_combox"));

        gridLayout_22->addWidget(AUTO_SCAN_DRATE_combox, 0, 0, 1, 1);

        label_4 = new QLabel(groupBox_19);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout_22->addWidget(label_4, 0, 1, 1, 1);

        AUTO_SCAN_DRATE_SET_btn = new QPushButton(groupBox_19);
        AUTO_SCAN_DRATE_SET_btn->setObjectName(QString::fromUtf8("AUTO_SCAN_DRATE_SET_btn"));

        gridLayout_22->addWidget(AUTO_SCAN_DRATE_SET_btn, 1, 0, 1, 2);


        gridLayout_21->addWidget(groupBox_19, 0, 0, 1, 1);


        gridLayout_23->addWidget(groupBox_14, 2, 1, 1, 1);

        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        combox_dut_select = new QComboBox(tab_6);
        combox_dut_select->addItem(QString());
        combox_dut_select->addItem(QString());
        combox_dut_select->addItem(QString());
        combox_dut_select->addItem(QString());
        combox_dut_select->addItem(QString());
        combox_dut_select->addItem(QString());
        combox_dut_select->addItem(QString());
        combox_dut_select->addItem(QString());
        combox_dut_select->addItem(QString());
        combox_dut_select->addItem(QString());
        combox_dut_select->setObjectName(QString::fromUtf8("combox_dut_select"));
        combox_dut_select->setGeometry(QRect(140, 30, 101, 22));
        tableWidget = new QTableWidget(tab_6);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(330, 30, 340, 350));
        tabWidget->addTab(tab_6, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 2, 1);

        gridLayout->setColumnStretch(0, 1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 962, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        AIN2_combox->setCurrentIndex(1);
        AIN1_combox->setCurrentIndex(1);
        AIN3_combox->setCurrentIndex(1);
        AIN0_combox->setCurrentIndex(1);
        AIN4_combox->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "PCIE-Tool", nullptr));
        groupBox_15->setTitle(QCoreApplication::translate("MainWindow", "Func", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "CS", nullptr));
        reset_btn->setText(QCoreApplication::translate("MainWindow", "\345\244\215\344\275\215AD(RST)", nullptr));
        Init_btn->setText(QCoreApplication::translate("MainWindow", "Init", nullptr));
        START_btn->setText(QCoreApplication::translate("MainWindow", "start", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "Register", nullptr));
        Register_comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "ADDR:00h  CONFIG0", nullptr));
        Register_comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "ADDR:01h  CONFIG1", nullptr));
        Register_comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "ADDR:02h  MUXSCH", nullptr));
        Register_comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "ADDR:03h  MUXDIF", nullptr));
        Register_comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "ADDR:04h  MUXSG0", nullptr));
        Register_comboBox->setItemText(5, QCoreApplication::translate("MainWindow", "ADDR:05h  MUXSG1", nullptr));
        Register_comboBox->setItemText(6, QCoreApplication::translate("MainWindow", "ADDR:06h  SYSRED", nullptr));
        Register_comboBox->setItemText(7, QCoreApplication::translate("MainWindow", "ADDR:07h  GPIOC", nullptr));
        Register_comboBox->setItemText(8, QCoreApplication::translate("MainWindow", "ADDR:08h  GPIOD", nullptr));
        Register_comboBox->setItemText(9, QCoreApplication::translate("MainWindow", "ADDR:09h  ID", nullptr));

        label_2->setText(QCoreApplication::translate("MainWindow", "Data", nullptr));
        SetRgister_btn->setText(QCoreApplication::translate("MainWindow", "SetRgister", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "AD", nullptr));
        groupBox_17->setTitle(QCoreApplication::translate("MainWindow", "\345\206\205\351\203\250\350\257\273\346\225\260", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Temp", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\342\204\203", nullptr));
        GetTemp_btn->setText(QCoreApplication::translate("MainWindow", "ADC\346\270\251\345\272\246", nullptr));
        groupBox_10->setTitle(QCoreApplication::translate("MainWindow", "OFFSET", nullptr));
        GetOFFSET_btn->setText(QCoreApplication::translate("MainWindow", "OFFSET", nullptr));
        groupBox_9->setTitle(QCoreApplication::translate("MainWindow", "VCC", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "V", nullptr));
        GetVCC_btn->setText(QCoreApplication::translate("MainWindow", "VCC", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "VREF", nullptr));
        GetVREF_btn->setText(QCoreApplication::translate("MainWindow", "VREF", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "V", nullptr));
        groupBox_13->setTitle(QCoreApplication::translate("MainWindow", "GAIN", nullptr));
        GetGAIN_btn->setText(QCoreApplication::translate("MainWindow", "GAIN", nullptr));
        groupBox_18->setTitle(QCoreApplication::translate("MainWindow", "\345\244\226\351\203\250\350\257\273\346\225\260", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("MainWindow", "AIN2", nullptr));
        GetAIN2_btn->setText(QCoreApplication::translate("MainWindow", "AIN2", nullptr));
        AIN2_combox->setItemText(0, QCoreApplication::translate("MainWindow", "V", nullptr));
        AIN2_combox->setItemText(1, QCoreApplication::translate("MainWindow", "mV", nullptr));
        AIN2_combox->setItemText(2, QCoreApplication::translate("MainWindow", "uV", nullptr));

        groupBox->setTitle(QCoreApplication::translate("MainWindow", "AIN1", nullptr));
        GetAIN1_btn->setText(QCoreApplication::translate("MainWindow", "AIN1", nullptr));
        AIN1_combox->setItemText(0, QCoreApplication::translate("MainWindow", "V", nullptr));
        AIN1_combox->setItemText(1, QCoreApplication::translate("MainWindow", "mV", nullptr));
        AIN1_combox->setItemText(2, QCoreApplication::translate("MainWindow", "uV", nullptr));

        groupBox_7->setTitle(QCoreApplication::translate("MainWindow", "AIN3", nullptr));
        GetAIN3_btn->setText(QCoreApplication::translate("MainWindow", "AIN3", nullptr));
        AIN3_combox->setItemText(0, QCoreApplication::translate("MainWindow", "V", nullptr));
        AIN3_combox->setItemText(1, QCoreApplication::translate("MainWindow", "mV", nullptr));
        AIN3_combox->setItemText(2, QCoreApplication::translate("MainWindow", "uV", nullptr));

        groupBox_16->setTitle(QCoreApplication::translate("MainWindow", "AIN0", nullptr));
        GetAIN0_btn->setText(QCoreApplication::translate("MainWindow", "AIN0", nullptr));
        AIN0_combox->setItemText(0, QCoreApplication::translate("MainWindow", "V", nullptr));
        AIN0_combox->setItemText(1, QCoreApplication::translate("MainWindow", "mV", nullptr));
        AIN0_combox->setItemText(2, QCoreApplication::translate("MainWindow", "uV", nullptr));

        groupBox_8->setTitle(QCoreApplication::translate("MainWindow", "AIN4", nullptr));
        GetAIN4_btn->setText(QCoreApplication::translate("MainWindow", "AIN4", nullptr));
        AIN4_combox->setItemText(0, QCoreApplication::translate("MainWindow", "V", nullptr));
        AIN4_combox->setItemText(1, QCoreApplication::translate("MainWindow", "mV", nullptr));
        AIN4_combox->setItemText(2, QCoreApplication::translate("MainWindow", "uV", nullptr));

        groupBox_12->setTitle(QCoreApplication::translate("MainWindow", "Channel", nullptr));
        DUT_Box->setTitle(QCoreApplication::translate("MainWindow", "DUT", nullptr));
        DUT4_btn->setText(QCoreApplication::translate("MainWindow", "DUT4", nullptr));
        DUT3_btn->setText(QCoreApplication::translate("MainWindow", "DUT3", nullptr));
        DUT1_btn->setText(QCoreApplication::translate("MainWindow", "DUT1", nullptr));
        DUT2_btn->setText(QCoreApplication::translate("MainWindow", "DUT2", nullptr));
        CURR_Box->setTitle(QCoreApplication::translate("MainWindow", "CURR", nullptr));
        CURR3_btn->setText(QCoreApplication::translate("MainWindow", "CURR3", nullptr));
        CURR2_btn->setText(QCoreApplication::translate("MainWindow", "CURR2", nullptr));
        CURR1_btn->setText(QCoreApplication::translate("MainWindow", "CURR1", nullptr));
        CURR4_btn->setText(QCoreApplication::translate("MainWindow", "CURR4", nullptr));
        groupBox_11->setTitle(QCoreApplication::translate("MainWindow", "Read", nullptr));
        ReadRegister_btn->setText(QCoreApplication::translate("MainWindow", "ReadRegister1-10", nullptr));
        ReadChannelData_btn->setText(QCoreApplication::translate("MainWindow", "ReadChannelData", nullptr));
        groupBox_14->setTitle(QCoreApplication::translate("MainWindow", "DRATE", nullptr));
        groupBox_19->setTitle(QCoreApplication::translate("MainWindow", "AUTO-SCAN(DEFALUT)", nullptr));
        AUTO_SCAN_DRATE_combox->setItemText(0, QCoreApplication::translate("MainWindow", "23739", nullptr));
        AUTO_SCAN_DRATE_combox->setItemText(1, QCoreApplication::translate("MainWindow", "15123", nullptr));
        AUTO_SCAN_DRATE_combox->setItemText(2, QCoreApplication::translate("MainWindow", "6168", nullptr));
        AUTO_SCAN_DRATE_combox->setItemText(3, QCoreApplication::translate("MainWindow", "1831", nullptr));

        label_4->setText(QCoreApplication::translate("MainWindow", "SPS", nullptr));
        AUTO_SCAN_DRATE_SET_btn->setText(QCoreApplication::translate("MainWindow", "SET", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
        combox_dut_select->setItemText(0, QCoreApplication::translate("MainWindow", "DUT-1", nullptr));
        combox_dut_select->setItemText(1, QCoreApplication::translate("MainWindow", "DUT-2", nullptr));
        combox_dut_select->setItemText(2, QCoreApplication::translate("MainWindow", "DUT-3", nullptr));
        combox_dut_select->setItemText(3, QCoreApplication::translate("MainWindow", "DUT-4", nullptr));
        combox_dut_select->setItemText(4, QCoreApplication::translate("MainWindow", "DUT-5", nullptr));
        combox_dut_select->setItemText(5, QCoreApplication::translate("MainWindow", "DUT-6", nullptr));
        combox_dut_select->setItemText(6, QCoreApplication::translate("MainWindow", "DUT-7", nullptr));
        combox_dut_select->setItemText(7, QCoreApplication::translate("MainWindow", "DUT-8", nullptr));
        combox_dut_select->setItemText(8, QCoreApplication::translate("MainWindow", "DUT-9", nullptr));
        combox_dut_select->setItemText(9, QCoreApplication::translate("MainWindow", "DUT-10", nullptr));

        tabWidget->setTabText(tabWidget->indexOf(tab_6), QCoreApplication::translate("MainWindow", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

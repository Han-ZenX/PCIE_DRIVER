#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QtCore>
#include <QtGui>
#include <QLabel>
#include "pcie.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void InitUI();

    void InitStationTable();

    uint8_t SOFT_SPI_RW_MODE1(int ndata);
private slots:
    void on_DUT1_btn_clicked();

    void on_DUT2_btn_clicked();

    void on_DUT3_btn_clicked();

    void on_DUT4_btn_clicked();

    void on_START_btn_clicked(bool checked);

    void on_pushButton_pressed();

    void on_pushButton_released();

    void on_CURR1_btn_clicked(bool checked);

    void on_CURR2_btn_clicked(bool checked);

    void on_CURR3_btn_clicked(bool checked);

    void on_CURR4_btn_clicked(bool checked);

    void on_ReadRegister_btn_clicked();

    void on_Init_btn_clicked();

    void on_SetRgister_btn_clicked();

    void on_ReadChannelData_btn_clicked();

    void on_reset_btn_clicked();

    void on_GetTemp_btn_clicked();

    void on_GetVREF_btn_clicked();

    void on_GetAIN1_btn_clicked();

    void on_GetAIN2_btn_clicked();

    void on_GetAIN3_btn_clicked();

    void on_GetAIN4_btn_clicked();

    void on_GetVCC_btn_clicked();

    void on_GetOFFSET_btn_clicked();

    void on_GetAIN0_btn_clicked();

    void on_GetGAIN_btn_clicked();

    void on_AUTO_SCAN_DRATE_SET_btn_clicked();

    void on_combox_dut_select_currentIndexChanged(int index);

    void on_tableWidget_cellClicked(int row, int column);

private:
    Ui::MainWindow *ui;

    Pcie *m_Pcie;

    QLabel *m_pStatusLabel;
};
#endif // MAINWINDOW_H

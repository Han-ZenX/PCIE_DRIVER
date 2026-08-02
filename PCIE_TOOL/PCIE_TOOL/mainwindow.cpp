#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    InitUI();

    InitStationTable();

    m_Pcie = new Pcie();
    m_Pcie->Init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InitUI()
{
    m_pStatusLabel = new QLabel(this);
    ui->statusbar->addWidget(m_pStatusLabel);
    m_pStatusLabel->setText("v1.0.0");
}

void MainWindow::InitStationTable()
{
    QStringList strList;
    strList<<"1"<<"2"<<"3"<<"4"<<"5"<<"6"<<"7"<<"8";

    ui->tableWidget->setRowCount(8);
    ui->tableWidget->setColumnCount(8);

    ui->tableWidget->setVerticalHeaderLabels(strList);

    ui->tableWidget->setHorizontalHeaderLabels(strList);

    for(int nCol=0;nCol<8;nCol++)
        ui->tableWidget->setColumnWidth(nCol,40);

    for(int nRow=0;nRow<8;nRow++)
        ui->tableWidget->setRowHeight(nRow,40);

    for(int col = 0;col<8;col++)
    {
        for(int row=0;row<8;row++)
        {
            int num = col * 8+(row+1);
            QTableWidgetItem * Item = new QTableWidgetItem(QString::number(num));

            Item->setTextAlignment(Qt::AlignCenter);

            ui->tableWidget->setItem(row,col,Item);
        }
    }

    ui->tableWidget->setStyleSheet("QTableWidget::item{ selection-background-color: blue;selection-color:white}");
}

uint8_t MainWindow::SOFT_SPI_RW_MODE1(int ndata)
{
    uint8_t i,Temp=0;

    uint8_t Data[8];

      for(i=0;i<8;i++)     // 循环8次,8位bit
      {
          if(ndata%2 == 0)
          {
              if(i==1 || i==4 || i==7) //i==1 || i==4 || i==7  01001001 //读取 AD 芯片的 ID寄存器指令
              {
                  m_Pcie->WriteBit(1,1,1);  //DIN 1
              }
              else
              {
                  m_Pcie->WriteBit(1,1,0);  //DIN 0
              }
          }
          else
          {
            m_Pcie->WriteBit(1,1,0); //DIN 0
          }

          m_Pcie->WriteBit(1,2,1);  //SCKL 1

          m_Pcie->WriteBit(0,1,Data[i]);  //DOUT 读取数据

          m_Pcie->WriteBit(1,1,0);  //DIN 0

          m_Pcie->WriteBit(1,2,0);  //SCKL 0

          //m_Pcie->WriteBit(1,1,0);  //DIN 0
      }

      return (Temp);     //返回数据
}

void MainWindow::on_DUT1_btn_clicked()
{
    if(m_Pcie->SetDUT1())
        ui->DUT_Box->setTitle("DUT---1");
}

void MainWindow::on_DUT2_btn_clicked()
{
    if(m_Pcie->SetDUT2())
        ui->DUT_Box->setTitle("DUT---2");
}

void MainWindow::on_DUT3_btn_clicked()
{
    if(m_Pcie->SetDUT3())
        ui->DUT_Box->setTitle("DUT---3");
}

void MainWindow::on_DUT4_btn_clicked()
{
    if(m_Pcie->SetDUT4())
        ui->DUT_Box->setTitle("DUT---4");
}

void MainWindow::on_START_btn_clicked(bool checked)
{
    int i = 0;

    m_Pcie->WriteBit(1,2,0);  //SCKL 0 时钟信号应从 低电平开始，防止SCLK初始化状态为 1 ,再经过一段延时后开始起振

    m_Pcie->WriteBit(1,3,1);  //CS 1

    m_Pcie->WriteBit(1,4,1);  //RST 1

    m_Pcie->WriteBit(0,7,1);  //PWDN 1

    QThread::msleep(10); //CS片选延时

    while(1)
    {
        m_Pcie->WriteBit(1,3,0); //CS 0,片选置低

        SOFT_SPI_RW_MODE1(i);

        i++;
    }
}

void MainWindow::on_pushButton_pressed()
{
    m_Pcie->WriteBit(1,3,1);
}

void MainWindow::on_pushButton_released()
{
    m_Pcie->WriteBit(1,3,0);
}

void MainWindow::on_CURR1_btn_clicked(bool checked)
{
    if(m_Pcie->SetCURR1())
        ui->CURR_Box->setTitle("CURR---1");
}

void MainWindow::on_CURR2_btn_clicked(bool checked)
{
    if(m_Pcie->SetCURR2())
        ui->CURR_Box->setTitle("CURR---2");
}

void MainWindow::on_CURR3_btn_clicked(bool checked)
{
    if(m_Pcie->SetCURR3())
        ui->CURR_Box->setTitle("CURR---3");
}

void MainWindow::on_CURR4_btn_clicked(bool checked)
{
    if(m_Pcie->SetCURR4())
        ui->CURR_Box->setTitle("CURR---4");
}

void MainWindow::on_ReadRegister_btn_clicked()
{
    uint8 i;

    uint8 ReadData;

    for(i = 0;i<10;i++)
    {
       ReadData =  m_Pcie->ReadRegister(i);

       printf("Register: 0x%X ,HEX: 0x%X ,DEC: %d \n",i,ReadData,ReadData);
    }

    printf("\n");
}

void MainWindow::on_Init_btn_clicked()
{
    m_Pcie->WriteBit(1,2,0);  //SCKL 0 时钟信号应从 低电平开始，防止SCLK初始化状态为 1 ,再经过一段延时后开始起振

    m_Pcie->WriteBit(1,3,1);  //CS  1，片选信号初始化置高

    m_Pcie->WriteBit(1,0,0);  //START  0，START信号初始化置低，需要进行AD转换读取数据时再置高

    m_Pcie->WriteBit(1,4,1);  //RST 1,经测试，此位需要置高，否则读取不到数据

    m_Pcie->WriteBit(0,7,1);  //PWDN 1,经测试，此位需要置高，否则读取不到数据

    QThread::msleep(10); //CS片选延时
}

void MainWindow::on_SetRgister_btn_clicked()
{
    uint8 Addr = ui->Register_comboBox->currentIndex();

    uint8 Data = ui->SetRgister_Data_box->value();

    m_Pcie->SetRegister(Addr,Data);
}

void MainWindow::on_ReadChannelData_btn_clicked()
{
    int32 Data;

    Data = m_Pcie->ReadChannelData();

    printf("AD_DATA: 0x%X ,%d  \n",Data,Data);

    printf("\n");
}

void MainWindow::on_reset_btn_clicked()
{
    m_Pcie->Reset();
}

void MainWindow::on_GetTemp_btn_clicked()
{
    double temp = m_Pcie->ADCTemp();

    ui->Temp_lineEdit->setText(QString::number(temp,'f',2));
}

void MainWindow::on_GetVREF_btn_clicked()
{
   double VREF = m_Pcie->VREF();

   ui->VREF_lineEdit->setText(QString::number(VREF,'f',3));
}

void MainWindow::on_GetAIN0_btn_clicked()
{
    double AIN0 = m_Pcie->AIN0(ui->AIN0_combox->currentIndex());

    ui->AIN0_lineEdit->setText(QString::number(AIN0,'f',3));
}

void MainWindow::on_GetAIN1_btn_clicked()
{
    double AIN1 = 0;
    double sum = 0;
    double temp[20];
    int i,j;

    double change;

    for(int i=0;i<20;i++)
    {
        temp[i] = m_Pcie->AIN1(ui->AIN1_combox->currentIndex());
    }

    for(i=1; i<20; i++)
    {
            for(j=0; j<20-i; j++)
            {
                if(temp[j] > temp[j+1])
                {
                    change = temp[j];
                    temp[j] = temp[j+1];
                    temp[j+1] = change;
                }
            }
    }
        //求和
    for(i=5; i<15; i++)
    {
         sum = sum + temp[i];
    }

    AIN1 = sum / 10;

    ui->AIN1_lineEdit->setText(QString::number(AIN1,'f',3));
}

void MainWindow::on_GetAIN2_btn_clicked()
{
    double AIN2 = m_Pcie->AIN2(ui->AIN2_combox->currentIndex());

    ui->AIN2_lineEdit->setText(QString::number(AIN2,'f',3));
}

void MainWindow::on_GetAIN3_btn_clicked()
{
    double AIN3 = m_Pcie->AIN3(ui->AIN3_combox->currentIndex());

    ui->AIN3_lineEdit->setText(QString::number(AIN3,'f',3));
}

void MainWindow::on_GetAIN4_btn_clicked()
{
    double AIN4 = m_Pcie->AIN4(ui->AIN4_combox->currentIndex());

    ui->AIN4_lineEdit->setText(QString::number(AIN4,'f',3));
}

void MainWindow::on_GetVCC_btn_clicked()
{
    double VCC = m_Pcie->VCC();

    ui->VCC_lineEdit->setText(QString::number(VCC,'f',3));
}

void MainWindow::on_GetGAIN_btn_clicked()
{
    double GAIN = m_Pcie->GAIN();

    ui->GAIN_lineEdit->setText(QString::number(GAIN,'f',4));
}

void MainWindow::on_GetOFFSET_btn_clicked()
{
    double OFFSET = m_Pcie->OFFSET();

    ui->OFFSET_lineEdit->setText(QString::number(OFFSET,'f',3));
}

void MainWindow::on_AUTO_SCAN_DRATE_SET_btn_clicked()
{

    uint8 REGDATA,DRATE = 0;
    switch (ui->AUTO_SCAN_DRATE_combox->currentIndex())
    {
    case 0:
        DRATE =0x83;
        break;
    case 1:
        DRATE =0x82;
        break;
    case 2:
        DRATE =0x81;
        break;
    case 3:
        DRATE =0x80;
        break;
    default:
        break;
    }

    m_Pcie->SetRegister(REG_CONFIG1, DRATE);
}

void MainWindow::on_combox_dut_select_currentIndexChanged(int index)
{
    m_Pcie->SetDUT(index);
}

void MainWindow::on_tableWidget_cellClicked(int row, int column)
{
    qDebug()<<"COL:ROW = "<<column<<":"<<row;

    m_Pcie->SetStation(column,row);
}

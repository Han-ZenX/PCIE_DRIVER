#include "pcie.h"

Pcie::Pcie()
{

    m_bOpen = false;

}

bool Pcie::Init()
{
    if(!InitPCIE())
        return false;

    if(!InitADS1258())
        return false;

    m_bOpen = true;

    printf("Init Success\n\n");

    return true;

}


bool Pcie::InitPCIE()
{
    m_instantDoCtrl = InstantDoCtrl::Create();
    m_description = DEVICE;
    std::wstring description = m_description.toStdWString();
    DeviceInformation devInfo(description.c_str());
    ErrorCode ret = Success;
    ret = m_instantDoCtrl->setSelectedDevice(devInfo);

    printf("PCIE:ret: 0x%X\n",ret);

    if(ret != Success)
    {
        if(ret == ErrorPrivilegeNotAvailable )
            printf("PCIE:The device has been used by other applications\n");
        else if(ret == ErrorDeviceNotExist)
            printf("PCIE:The device is not Exist\n");

        return false;
    }

    m_portDirection = m_instantDoCtrl->getPortDirection();

    if(m_portDirection !=NULL)
    {
        qDebug()<<"m_portDirection !=NULL";
        DioPortDir dirInput = Input;
        m_portDirection->getItem(0).setDirection(dirInput);
    }

    InitTTL();

    Sleep(300); //InitTTL后延时300ms

    printf("PCIE: True\n\n");

    return true;
}

bool Pcie::InitADS1258()
{
    Reset(); //先复位

    if(ReadRegister(REG_CONFIG0) !=REG_CONFIG0_DEFAULT_VALUE)
    {
        printf("ReadRegister(REG_CONFIG0) =0x%X\n",ReadRegister(REG_CONFIG0));
        printf("ADS1258:REG_CONFIG0_VALUE !=REG_CONFIG0_DEFAULT_VALUE\n");
        return false;
    }

    if(ReadRegister(REG_CONFIG1) !=REG_CONFIG1_DEFAULT_VALUE)
    {
        printf("ADS1258:REG_CONFIG1_VALUE !=REG_CONFIG1_DEFAULT_VALUE\n");
        return false;
    }

    if(ReadRegister(REG_ID) !=REG_ID_DEFAULT_VALUE)
    {
        printf("ADS1258:REG_ID_VALUE !=REG_ID_DEFAULT_VALUE\n");
        return false;
    }

    printf("ADS1258: True\n\n");
    return true;
}

bool Pcie::InitTTL()
{
    DRDY.port = 0;DRDY.bit = 0;
    DOUT.port = 0;DOUT.bit = 1;
    PWDN.port = 0;PWDN.bit = 7;

    START.port = 1;START.bit = 0;
    DIN.port = 1;DIN.bit = 1;
    SCLK.port = 1;SCLK.bit = 2;
    CS.port = 1; CS.bit = 3;
    RST.port = 1;RST.bit = 4;


    m_instantDoCtrl->WriteBit(SCLK.port,SCLK.bit,0);  //SCKL 0 时钟信号应从 低电平开始，防止SCLK初始化状态为 1 ,再经过一段延时后开始起振

    m_instantDoCtrl->WriteBit(CS.port,CS.bit,1);  //CS  1，片选信号初始化置高

    m_instantDoCtrl->WriteBit(START.port,START.bit,0);  //START  0，START信号初始化置低，需要进行AD转换读取数据时再置高

    m_instantDoCtrl->WriteBit(RST.port,RST.bit,1);  //RST 1,经测试，此位需要置高，否则读取不到数据

    m_instantDoCtrl->WriteBit(PWDN.port,PWDN.bit,1);  //PWDN 1,经测试，此位需要置高，否则读取不到数据

    QThread::msleep(10); //CS片选延时

    return true;
}

void Pcie::CheckError(ErrorCode errorCode)
{
    if (BioFailed(errorCode))
    {
        QString message = QObject::tr("Sorry, there are some errors occurred, Error Code: 0x") +
            QString::number(errorCode, 16).right(8).toUpper();
        //QMessageBox::information(this, "Warning Information", message);
    }
}

bool Pcie::WriteBit(int32 port, int32 bit, uint8 data)
{
    ErrorCode errorCode = Success;

    errorCode = m_instantDoCtrl->WriteBit(port,bit,data);

    return true;
}

bool Pcie::ReadBit(int32 port, int32 bit, uint8 &data)
{
    ErrorCode errorCode = Success;

    errorCode = m_instantDoCtrl->ReadBit(port,bit,&data);

    return true;
}

void Pcie::Reset()
{
     m_instantDoCtrl->WriteBit(RST.port,RST.bit,0);  //RST 0

     QThread::msleep(1); //低电平保持大于两个fclk的时间

     m_instantDoCtrl->WriteBit(RST.port,RST.bit,1);  //RST 1
}

double Pcie::ADCTemp()
{
    int32 Temp = 0;
    double temp = 0;
    Reset();

    SetRegister(REG_MUXSG0,0);
    SetRegister(REG_MUXSG1,0);
    SetRegister(REG_SYSRED,8);

    Temp = ReadChannelData();

    temp = ((((double)Temp * V_REF / 7864320 * 1000000)-168000)/563)+25;

    printf("ADC Temp: %f\n\n",temp);

    return  temp;
}

double Pcie::VREF()
{
    int32 Vref = 0;
    double VREF = 0;
    Reset();

    SetRegister(REG_MUXSG0,0);
    SetRegister(REG_MUXSG1,0);
    SetRegister(REG_SYSRED,0x20); //SYSRED 寄存器设置为 00100000

    Vref = ReadChannelData();

    VREF = (double)Vref / 786432;

    printf("VREF: %f V\n\n",VREF);

    return  VREF;
}

double Pcie::VCC()
{
    int32 Vcc = 0;
    double VCC = 0;
    Reset();

    SetRegister(REG_MUXSG0,0);
    SetRegister(REG_MUXSG1,0);
    SetRegister(REG_SYSRED,0x04); //SYSRED 寄存器设置为 00000100

    Vcc = ReadChannelData();

    VCC = (double)Vcc / 786432;

    printf("VCC: %f V\n\n",VCC);

    return  VCC;
}

double Pcie::OFFSET()
{
    int32 Offset = 0;
    double OFFSET = 0;
    Reset();

    SetRegister(REG_MUXSG0,0);
    SetRegister(REG_MUXSG1,0);
    SetRegister(REG_SYSRED,0x01); //SYSRED 寄存器设置为 00000001

    Offset = ReadChannelData();

    OFFSET = (double)Offset;

    printf("OFFSET: %f V\n\n",OFFSET);

    return  OFFSET;
}

double Pcie::AIN0(int Unit)
{
    int32 Ain0 = 0;
    double AIN0 = 0;
    //Reset();

    SetRegister(REG_MUXSG0,0x01); //MUXSG0 寄存器设置为 00000001
    SetRegister(REG_MUXSG1,0);
    SetRegister(REG_SYSRED,0);

    Ain0 = ReadChannelData();

    AIN0 = (double)Ain0  *V_REF /7864320 ;

    //AIN0 = (double)Ain0  *V_REF /7864320 ;

    printf("AIN0: %f V\n\n",AIN0);

    return  VoltUnitConvert(AIN0,Unit);
}

double Pcie::AIN1(int Unit)
{
    int32 Ain1 = 0;
    double AIN1 = 0;
    //Reset();

    SetRegister(REG_MUXSG0,0x02); //MUXSG0 寄存器设置为 00000010
    SetRegister(REG_MUXSG1,0);
    SetRegister(REG_SYSRED,0);

    Ain1 = ReadChannelData();

    AIN1 = (double)Ain1  *V_REF /7864320 ;

    printf("AIN1: %f V\n\n",AIN1);

    return  VoltUnitConvert(AIN1,Unit);
}

double Pcie::AIN2(int Unit)
{
    int32 Ain2 = 0;
    double AIN2 = 0;
    //Reset();

    SetRegister(REG_MUXSG0,0x04); //MUXSG0 寄存器设置为 00000100
    SetRegister(REG_MUXSG1,0);
    SetRegister(REG_SYSRED,0);

    Ain2 = ReadChannelData();
    printf("^-----------\n");

    AIN2 = (double)Ain2  *V_REF  /7864320;

    printf("AIN2: %f V\n\n",AIN2);

    return  VoltUnitConvert(AIN2,Unit);
}

double Pcie::AIN3(int Unit)
{
    int32 Ain3 = 0;
    double AIN3 = 0;
    //Reset();

    SetRegister(REG_MUXSG0,0x08); //SYSRED 寄存器设置为 00001000
    SetRegister(REG_MUXSG1,0);
    SetRegister(REG_SYSRED,0);

    Ain3 = ReadChannelData();
    printf("^-----------\n");

    AIN3 = (double)Ain3  *V_REF /7864320;

    printf("AIN3: %f V\n\n",AIN3);

    return  VoltUnitConvert(AIN3,Unit);
}

double Pcie::AIN4(int Unit)
{
    int32 Ain4 = 0;
    double AIN4 = 0;
    //Reset();

    SetRegister(REG_MUXSG0,0x10); //MUXSG0 寄存器设置为 00010000
    SetRegister(REG_MUXSG1,0);
    SetRegister(REG_SYSRED,0);

    Ain4 = ReadChannelData();
    printf("^-----------\n");

    AIN4 = (double)Ain4  *V_REF /7864320;

    printf("AIN4: %f V\n\n",AIN4);

    return  VoltUnitConvert(AIN4,Unit);
}

double Pcie::AIN5(int Unit)
{
    int32 Ain5 = 0;
    double AIN5 = 0;
    //Reset();

    SetRegister(REG_MUXSG0,0x20); //MUXSG0 寄存器设置为 00100000
    SetRegister(REG_MUXSG1,0);
    SetRegister(REG_SYSRED,0);

    Ain5 = ReadChannelData();
    printf("^-----------\n");

    AIN5 = (double)Ain5  *V_REF /7864320;

    printf("AIN5: %f V\n\n",AIN5);

    return  VoltUnitConvert(AIN5,Unit);
}

double Pcie::AIN6(int Unit)
{
    int32 Ain6 = 0;
    double AIN6 = 0;
    //Reset();

    SetRegister(REG_MUXSG0,0x40); //MUXSG0 寄存器设置为 01000000
    SetRegister(REG_MUXSG1,0);
    SetRegister(REG_SYSRED,0);

    Ain6 = ReadChannelData();
    printf("^-----------\n");

    AIN6 = (double)Ain6  *V_REF /7864320;

    printf("AIN6: %f V\n\n",AIN6);

    return  VoltUnitConvert(AIN6,Unit);
}

double Pcie::AIN7(int Unit)
{
    int32 Ain7 = 0;
    double AIN7 = 0;
    //Reset();

    SetRegister(REG_MUXSG0,0x80); //MUXSG0 寄存器设置为 10000000
    SetRegister(REG_MUXSG1,0);
    SetRegister(REG_SYSRED,0);

    Ain7 = ReadChannelData();
    printf("^-----------\n");

    AIN7 = (double)Ain7  *V_REF /7864320;

    printf("AIN7: %f V\n\n",AIN7);

    return  VoltUnitConvert(AIN7,Unit);
}

double Pcie::AIN8(int Unit)
{
    int32 Ain8 = 0;
    double AIN8 = 0;
    //Reset();

    SetRegister(REG_MUXSG0,0);
    SetRegister(REG_MUXSG1,0x01); //MUXSG1 寄存器设置为 00000001
    SetRegister(REG_SYSRED,0);

    Ain8 = ReadChannelData();
    printf("^-----------\n");

    AIN8 = (double)Ain8  *V_REF /7864320;

    printf("AIN8: %f V\n\n",AIN8);

    return  VoltUnitConvert(AIN8,Unit);
}

double Pcie::AIN9(int Unit)
{
    int32 Ain9 = 0;
    double AIN9 = 0;
    //Reset();

    SetRegister(REG_MUXSG0,0);
    SetRegister(REG_MUXSG1,0x02); //MUXSG1 寄存器设置为 00000010
    SetRegister(REG_SYSRED,0);

    Ain9 = ReadChannelData();
    printf("^-----------\n");

    AIN9 = (double)Ain9  *V_REF /7864320;

    printf("AIN9: %f V\n\n",AIN9);

    return  VoltUnitConvert(AIN9,Unit);
}

double Pcie::AIN10(int Unit)
{
    int32 Ain10 = 0;
    double AIN10 = 0;
    //Reset();

    SetRegister(REG_MUXSG0,0);
    SetRegister(REG_MUXSG1,0x04); //MUXSG1 寄存器设置为 00000100
    SetRegister(REG_SYSRED,0);

    Ain10 = ReadChannelData();
    printf("^-----------\n");

    AIN10 = (double)Ain10  *V_REF /7864320;

    printf("AIN10: %f V\n\n",AIN10);

    return  VoltUnitConvert(AIN10,Unit);
}

double Pcie::AIN11(int Unit)
{
    int32 Ain11 = 0;
    double AIN11 = 0;
    //Reset();

    SetRegister(REG_MUXSG0,0);
    SetRegister(REG_MUXSG1,0x08); //MUXSG1 寄存器设置为 00001000
    SetRegister(REG_SYSRED,0);

    Ain11 = ReadChannelData();
    printf("^-----------\n");

    AIN11 = (double)Ain11  *V_REF /7864320;

    printf("AIN11: %f V\n\n",AIN11);

    return  VoltUnitConvert(AIN11,Unit);
}

double Pcie::AIN12(int Unit)
{
    int32 Ain12 = 0;
    double AIN12 = 0;
    //Reset();

    SetRegister(REG_MUXSG0,0);
    SetRegister(REG_MUXSG1,0x10); //MUXSG1 寄存器设置为 00010000
    SetRegister(REG_SYSRED,0);

    Ain12 = ReadChannelData();
    printf("^-----------\n");

    AIN12 = (double)Ain12  *V_REF /7864320;

    printf("AIN12: %f V\n\n",AIN12);

    return  VoltUnitConvert(AIN12,Unit);
}

double Pcie::AIN13(int Unit)
{
    int32 Ain13 = 0;
    double AIN13 = 0;
    //Reset();

    SetRegister(REG_MUXSG0,0);
    SetRegister(REG_MUXSG1,0x20); //MUXSG1 寄存器设置为 00100000
    SetRegister(REG_SYSRED,0);

    Ain13 = ReadChannelData();
    printf("^-----------\n");

    AIN13 = (double)Ain13  *V_REF /7864320;

    printf("AIN13: %f V\n\n",AIN13);

    return  VoltUnitConvert(AIN13,Unit);
}

double Pcie::AIN14(int Unit)
{
    int32 Ain14 = 0;
    double AIN14 = 0;
    //Reset();

    SetRegister(REG_MUXSG0,0);
    SetRegister(REG_MUXSG1,0x40); //MUXSG1 寄存器设置为 01000000
    SetRegister(REG_SYSRED,0);

    Ain14 = ReadChannelData();
    printf("^-----------\n");

    AIN14 = (double)Ain14  *V_REF /7864320;

    printf("AIN14: %f V\n\n",AIN14);

    return  VoltUnitConvert(AIN14,Unit);
}

double Pcie::AIN15(int Unit)
{
    int32 Ain15 = 0;
    double AIN15 = 0;
    //Reset();

    SetRegister(REG_MUXSG0,0);
    SetRegister(REG_MUXSG1,0x80); //MUXSG1 寄存器设置为 10000000
    SetRegister(REG_SYSRED,0);

    Ain15 = ReadChannelData();
    printf("^-----------\n");

    AIN15 = (double)Ain15  *V_REF /7864320;

    printf("AIN15: %f V\n\n",AIN15);

    return  VoltUnitConvert(AIN15,Unit);
}

double Pcie::VoltUnitConvert(double value,int unit)
{
    switch (unit)
    {
    case UNIT_V:
        value = value;
        break;
    case UNIT_mV:
        value = value * 1000;
        break;
    case UNIT_uV:
        value = value * 1000000;
        break;
    default:
        break;
    }

    return value;
}

double Pcie::GAIN()
{
    int32 Gain = 0;
    double GAIN = 0;
    Reset();

    SetRegister(REG_MUXSG0,0);
    SetRegister(REG_MUXSG1,0);
    SetRegister(REG_SYSRED,0x10);//SYSRED 寄存器设置为 00010000

    Gain = ReadChannelData();

    GAIN = (double)Gain /7864320;

    printf("GAIN: %f \n\n",GAIN);

    return  GAIN;
}


int32 Pcie::ReadChannelData()
{
    uint8 *Data = new uint8[4];

    int32 AD_DEC;

    m_instantDoCtrl->WriteBit(CS.port,CS.bit,0);  //CS  0，片选信号初始化置高

    m_instantDoCtrl->WriteBit(START.port,START.bit,1); //START - 1

    /////////
    QThread::msleep(3); //START 置高后等待一段时间，等待数据转换完成
    /////////


    WriteByte(0x30);  //0011 0000

    for(int i=0;i<4;i++)
    {
        Data[i] = ReadByte();
    }

    m_instantDoCtrl->WriteBit(START.port,START.bit,0); //START - 0

    m_instantDoCtrl->WriteBit(CS.port,CS.bit,1);  //CS  1

    AD_DEC = (uint32)(Data[1]<<16)|(Data[2]<<8)|Data[3];

    if(Data[1]&0x80)
        AD_DEC |= 0xFF000000;

    printf("STATUS: 0x%X ,MSB: 0x%X ,MSB-1: 0x%X ,LSB: 0x%X  \n",Data[0],Data[1],Data[2],Data[3]);

    return AD_DEC;
}

///*********新增加的部分
void Pcie::SetRegister(uint8 addr,uint8 cmd)
{
    m_instantDoCtrl->WriteBit(CS.port,CS.bit,0);  //CS 0

    WriteByte(addr | 0x60); //0x60 是01100000,写入单个寄存器数据

    WriteByte(cmd);

   //WriteByte(addr | 0x70); //0x70 是01110000,写入多个寄存器数据

    m_instantDoCtrl->WriteBit(CS.port,CS.bit,1);  //CS 1
}

uint8 Pcie::ReadRegister(uint8 addr)
{
    return ReadByte(addr | 0x40); //0x40 是01000000
}

uint8 Pcie::ReadByte(uint8 data)
{
    uint8_t temp;

    m_instantDoCtrl->WriteBit(CS.port,CS.bit,0);  //CS 0

    WriteByte(data);

    temp = ReadByte();

    m_instantDoCtrl->WriteBit(CS.port,CS.bit,1);  //CS 1

    return temp;

}

void Pcie::WriteByte(uint8 data)
{
    int i=0;

    uint8 *WriteData = new uint8[8];

    ByteConverToBin(data,WriteData);

    for(i=0;i<8;i++)
    {
        m_instantDoCtrl->WriteBit(DIN.port,DIN.bit,WriteData[i]); //DIN - 1

        m_instantDoCtrl->WriteBit(SCLK.port,SCLK.bit,1); //SCKL 1

        m_instantDoCtrl->WriteBit(DIN.port,DIN.bit,0); //DIN - 0

        m_instantDoCtrl->WriteBit(SCLK.port,SCLK.bit,0); //SCKL 0
    }
}

uint8 Pcie::ReadByte()
{
    int i=0;

    uint8 ReadData[8]= {0,0,0,0,0,0,0,0};

    for(i=0;i<8;i++)
    {
        m_instantDoCtrl->WriteBit(SCLK.port,SCLK.bit,1); //SCKL 1

        m_instantDoCtrl->ReadBit(DOUT.port,DOUT.bit,&ReadData[i]); //DOUT 读取数据

        m_instantDoCtrl->WriteBit(DIN.port,DIN.bit,0); //DIN 0

        m_instantDoCtrl->WriteBit(SCLK.port,SCLK.bit,0); //SCKL 0
    }

    return BinConverToByte(ReadData);
}



void Pcie::ByteConverToBin(uint8 byte,uint8 *bin)
{
    int i,size;

    uint8 temp;

    size = 8;

    for(i=0;i<8;i++)
    {
         bin[i] = ((byte >> i) & 1);
    }

    //反转算法
    for(i=0;i<size/2;i++)
    {
        temp = bin[i];
        bin[i] = bin[size-1-i];
        bin[size-1-i] = temp;
    }
}

uint8 Pcie::BinConverToByte(uint8 data[])
{
    uint8 byte = 0x0;

    int i,size;

    uint8 temp;

    size = 8;

    //反转算法
    for(i=0;i<size/2;i++)
    {
        temp = data[i];
        data[i] = data[size-1-i];
        data[size-1-i] = temp;
    }

    for(i=0;i<size;i++)
    {
        if(data[i] == 1)
        {
            byte |=(1<<i);
        }
        else
        {
            byte &=~(1<<i);
        }
    }

    return byte;
}

///*********新增加的部分


bool Pcie::SetDUT1()
{
    if(!isOpen())
        return false;

    uint8 uHIGH = 1;
    uint8 uLOW = 0;

    WriteBit(2,4,uHIGH);
    WriteBit(2,5,uLOW);
    WriteBit(2,6,uLOW);
    WriteBit(2,7,uLOW);

    WriteBit(2,0,uLOW);
    WriteBit(2,1,uLOW);
    WriteBit(2,2,uLOW);
    WriteBit(2,3,uLOW);

    return true;
}

bool Pcie::SetDUT2()
{
    if(!isOpen())
        return false;

    uint8 uHIGH = 1;
    uint8 uLOW = 0;

    WriteBit(2,4,uLOW);
    WriteBit(2,5,uHIGH);
    WriteBit(2,6,uLOW);
    WriteBit(2,7,uLOW);

    WriteBit(2,0,uLOW);
    WriteBit(2,1,uLOW);
    WriteBit(2,2,uHIGH);
    WriteBit(2,3,uLOW);

    return true;
}

bool Pcie::SetDUT3()
{
    if(!isOpen())
        return false;

    uint8 uHIGH = 1;
    uint8 uLOW = 0;

    WriteBit(2,4,uLOW);
    WriteBit(2,5,uLOW);
    WriteBit(2,6,uHIGH);
    WriteBit(2,7,uLOW);

    WriteBit(2,0,uLOW);
    WriteBit(2,1,uHIGH);
    WriteBit(2,2,uLOW);
    WriteBit(2,3,uLOW);

    return true;
}

bool Pcie::SetDUT4()
{
    if(!isOpen())
        return false;

    uint8 uHIGH = 1;
    uint8 uLOW = 0;

    WriteBit(2,4,uLOW);
    WriteBit(2,5,uLOW);
    WriteBit(2,6,uLOW);
    WriteBit(2,7,uHIGH);

    WriteBit(2,0,uLOW);
    WriteBit(2,1,uHIGH);
    WriteBit(2,2,uHIGH);
    WriteBit(2,3,uLOW);

    return true;
}

bool Pcie::SetCURR1()
{
    if(!isOpen())
        return false;

    uint8 uHIGH = 1;
    uint8 uLOW = 0;

    WriteBit(1,5,uLOW);
    WriteBit(1,6,uLOW);
    WriteBit(1,7,uLOW);

    return true;
}

bool Pcie::SetCURR2()
{
    if(!isOpen())
        return false;

    uint8 uHIGH = 1;
    uint8 uLOW = 0;

    WriteBit(1,5,uHIGH);
    WriteBit(1,6,uLOW);
    WriteBit(1,7,uLOW);

    return true;
}

bool Pcie::SetCURR3()
{
    if(!isOpen())
        return false;

    uint8 uHIGH = 1;
    uint8 uLOW = 0;

    WriteBit(1,5,uLOW);
    WriteBit(1,6,uHIGH);
    WriteBit(1,7,uLOW);

    return true;
}

bool Pcie::SetCURR4()
{
    if(!isOpen())
        return false;

    uint8 uHIGH = 1;
    uint8 uLOW = 0;

    WriteBit(1,5,uHIGH);
    WriteBit(1,6,uHIGH);
    WriteBit(1,7,uLOW);

    return true;
}

                                //C B A G2A
static uint8 DUT_BD_SEL[10][4]= {{0,0,0,0},  //DUT-1
                                 {0,0,1,0},  //DUT-2
                                 {0,1,0,0},  //DUT-3
                                 {0,1,1,0},  //DUT-4
                                 {1,0,0,0},  //DUT-5
                                 {1,0,1,0},  //DUT-6
                                 {1,1,0,0},  //DUT-7
                                 {1,1,1,0},  //DUT-8
                                 {0,0,0,1},  //DUT-9
                                 {0,0,1,1}}; //DUT-10


                        //RF_BD_SEL 1,2,3,4,5
static uint8 RF_BD_SEL[10][5]  =  {{1,1,1,1,0},  //DUT-1
                                   {1,1,0,1,0},  //DUT-2
                                   {1,0,1,1,0},  //DUT-3
                                   {1,0,0,1,0},  //DUT-4
                                   {0,1,1,1,0},  //DUT-5
                                   {0,1,0,1,0},  //DUT-6
                                   {0,0,1,1,0},  //DUT-7
                                   {0,0,0,1,0},  //DUT-8
                                   {0,0,0,0,1},  //DUT-9
                                   {0,0,0,1,1}}; //DUT-10
/***************************************************************
 * 0-DUT1-U3-RF8-SEL1:SEL2:SEL3-V1:V2:V3-111-SLE5-0  11110 DUT-1
 * 1-DUT2-U3-RF7-SEL1:SEL2:SEL3-V1:V2:V3-110-SLE5-0  11010 DUT-2
 * 2-DUT3-U3-RF6-SEL1:SEL2:SEL3-V1:V2:V3-101-SLE5-0  10110 DUT-3
 * 3-DUT4-U3-RF5-SEL1:SEL2:SEL3-V1:V2:V3-100-SLE5-0  10010 DUT-4
 * 4-DUT5-U3-RF4-SEL1:SEL2:SEL3-V1:V2:V3-011-SLE5-0  01110 DUT-5
 * 5-DUT6-U3-RF3-SEL1:SEL2:SEL3-V1:V2:V3-010-SLE5-0  01010 DUT-6
 * 6-DUT7-U3-RF2-SEL1:SEL2:SEL3-V1:V2:V3-001-SLE5-0  00110 DUT-7
 * 7-DUT8-U3-RF1-SEL1:SEL2:SEL3-V1:V2:V3-000-SLE5-0  00010 DUT-8
 * 8-DUT9-SW2-SEL4-0-SEL5-1  00001 DUT-9
 * 9-DUT10-SW2-SEL4-1-SEL5-1 00011 DUT-10
 * *************************************************************/
bool Pcie::SetDUT(int nDut)
{
    if(nDut<0 || nDut>9)
    {
        return false;
    }

    WriteBit(4,7,1);    //OUTPUT_EN,使能位置高

    WriteBit(5,0,DUT_BD_SEL[nDut][2]);    //DUT_BD_SEL1 53 P5_0 A
    WriteBit(5,1,DUT_BD_SEL[nDut][1]);    //DUT_BD_SEL2 54 P5_1 B
    WriteBit(5,2,DUT_BD_SEL[nDut][0]);    //DUT_BD_SEL3 55 P5_2 C
    WriteBit(5,3,DUT_BD_SEL[nDut][3]);    //DUT_BD_SEL4 56 P5_3 G2A

    WriteBit(4,0,RF_BD_SEL[nDut][0]);  //RF_BD_SEL1 44 P4_0
    WriteBit(4,1,RF_BD_SEL[nDut][1]);  //RF_BD_SEL2 45 P4_1
    WriteBit(4,2,RF_BD_SEL[nDut][2]);  //RF_BD_SEL3 46 P4_2
    WriteBit(4,3,RF_BD_SEL[nDut][3]);  //RF_BD_SEL4 47 P4_3
    WriteBit(4,4,RF_BD_SEL[nDut][4]);  //RF_BD_SEL5 48 P4_4 RFC to RF2-LOW

    return true;
}



                                //C B A
static uint8 RF_COL_SEL[8][3]=  {{0,0,0},  //COL-1
                                 {0,0,1},  //COL-2
                                 {0,1,0},  //COL-3
                                 {0,1,1},  //COL-4
                                 {1,0,0},  //COL-5
                                 {1,0,1},  //COL-6
                                 {1,1,0},  //COL-7
                                 {1,1,1}}; //COL-8

                                //C B A
static uint8 RF_ROW_SEL[8][3]=  {{0,0,0},  //ROW-1
                                 {0,0,1},  //ROW-2
                                 {0,1,0},  //ROW-3
                                 {0,1,1},  //ROW-4
                                 {1,0,0},  //ROW-5
                                 {1,0,1},  //ROW-6
                                 {1,1,0},  //ROW-7
                                 {1,1,1}}; //ROW-8

bool Pcie::SetDUTStation(int nDut, int nCol, int nRow)
{
    if(nDut<0 || nDut>9)
    {
        return false;
    }

    if(!SetDUT(nDut))
        return false;

    if(!SetStation(nCol,nRow))
        return false;

    return true;
}

bool Pcie::SetStation(int nCol, int nRow)
{
    if(!SetFRStation(nCol,nRow))
        return false;

    if(!SetCURRStation(nCol,nRow))
        return false;

    return true;
}

bool Pcie::SetFRStation(int nCol, int nRow)
{
    if(nCol < 0 || nCol > 7)
    {
        return false;
    }

    if(nRow < 0 || nRow > 7)
    {
        return false;
    }

    WriteBit(3,0,RF_COL_SEL[nCol][2]);    //RF_COL_SEL1 35 P3_0 A
    WriteBit(3,1,RF_COL_SEL[nCol][1]);    //RF_COL_SEL2 36 P3_1 B
    WriteBit(3,2,RF_COL_SEL[nCol][0]);    //RF_COL_SEL3 37 P3_2 C


    WriteBit(3,4,RF_ROW_SEL[nRow][2]);    //RF_ROW_SEL1 39 P3_4 A
    WriteBit(3,5,RF_ROW_SEL[nRow][1]);    //RF_ROW_SEL2 40 P3_5 B
    WriteBit(3,6,RF_ROW_SEL[nRow][0]);    //RF_ROW_SEL3 41 P3_6 C

    return true;
}

                               //A2 A1 A0
static uint8 CURR_COL_SEL[8][3]={{0,0,0},  //COL-1
                                 {0,0,1},  //COL-2
                                 {0,1,0},  //COL-3
                                 {0,1,1},  //COL-4
                                 {1,0,0},  //COL-5
                                 {1,0,1},  //COL-6
                                 {1,1,0},  //COL-7
                                 {1,1,1}}; //COL-8

                                //A2 A1 A0
static uint8 CURR_ROW_SEL[8][3]= {{0,0,0},  //ROW-1
                                  {0,0,1},  //ROW-2
                                  {0,1,0},  //ROW-3
                                  {0,1,1},  //ROW-4
                                  {1,0,0},  //ROW-5
                                  {1,0,1},  //ROW-6
                                  {1,1,0},  //ROW-7
                                  {1,1,1}}; //ROW-8

bool Pcie::SetCURRStation(int nCol, int nRow)
{
    if(nCol < 0 || nCol > 7)
    {
        return false;
    }

    if(nRow < 0 || nRow > 7)
    {
        return false;
    }

    WriteBit(2,3,CURR_COL_SEL[nCol][2]);    //BackBoard:CURR_A3 22 P2_3 A0 DUTBoard:CURR_B0
    WriteBit(2,4,CURR_COL_SEL[nCol][1]);    //BackBoard:CURR_A4 23 P2_4 A1 DUTBoard:CURR_B1
    WriteBit(2,5,CURR_COL_SEL[nCol][0]);    //BackBoard:CURR_A5 24 P2_5 A2 DUTBoard:CURR_B2

    WriteBit(2,0,CURR_ROW_SEL[nCol][2]);    //BackBoard:CURR_A0 19 P2_0 A0 DUTBoard:CURR_A0
    WriteBit(2,1,CURR_ROW_SEL[nCol][1]);    //BackBoard:CURR_A1 20 P2_1 A1 DUTBoard:CURR_A1
    WriteBit(2,2,CURR_ROW_SEL[nCol][0]);    //BackBoard:CURR_A2 21 P2_2 A2 DUTBoard:CURR_A2
}

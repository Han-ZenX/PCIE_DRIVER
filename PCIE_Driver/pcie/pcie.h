#ifndef PCIE_H
#define PCIE_H

#include <QtCore/qglobal.h>

#if defined(PCIE_LIBRARY)
#  define PCIE_EXPORT Q_DECL_EXPORT
#else
#  define PCIE_EXPORT Q_DECL_IMPORT
#endif

#include "pcie_global.h"
#include "C:/Advantech/DAQNavi/Inc/bdaqctrl.h"
#include <QObject>
#include <iostream>
#include <windows.h>
#include <QtCore>
#include <QtGui>

using namespace Automation::BDaq;

#define DEVICE "PCIE-1751,BID#1"

#define V_REF 4.096

enum enRegisterType{
    REG_CONFIG0 = 0x00,
    REG_CONFIG1 = 0x01,
    REG_MUXSCH = 0x02,
    REG_MUXDIF = 0x03,
    REG_MUXSG0 = 0x04,
    REG_MUXSG1 = 0x05,
    REG_SYSRED = 0x06,
    REG_GPIOC = 0x07,
    REG_GPIOD = 0x08,
    REG_ID = 0x09
};

enum enRegisterDefaultValue{
    REG_CONFIG0_DEFAULT_VALUE = 0x0A,
    REG_CONFIG1_DEFAULT_VALUE = 0x83,
    REG_MUXSCH_DEFAULT_VALUE = 0x0,
    REG_MUXDIF_DEFAULT_VALUE = 0x0,
    REG_MUXSG0_DEFAULT_VALUE = 0xFF,
    REG_MUXSG1_DEFAULT_VALUE = 0xFF,
    REG_SYSRED_DEFAULT_VALUE = 0x0,
    REG_GPIOC_DEFAULT_VALUE = 0xFF,
    REG_GPIOD_DEFAULT_VALUE = 0x0,
    REG_ID_DEFAULT_VALUE = 0x8B
};

/*
enum enMUXMODE{
    MODE_AUTO_SCAN,
    MODE_FIXED_CHANNEL
};
*/

enum enAutoScanDRATE{
    DRATE_AUTOSCAN_23739 = 0x3, //DRATE[1:0]-11
    DRATE_AUTOSCAN_15123 = 0x2, //DRATE[1:0]-10
    DRATE_AUTOSCAN_6168 = 0x1,  //DRATE[1:0]-01
    DRATE_AUTOSCAN_1831 = 0x0   //DRATE[1:0]-00
};

enum enFixedChannelDRATE{
    DRATE_FIXEDCHANNEL_125000 = 0x3,  //DRATE[1:0]-11
    DRATE_FIXEDCHANNEL_31250 = 0x2,   //DRATE[1:0]-10
    DRATE_FIXEDCHANNEL_7813 = 0x1,    //DRATE[1:0]-01
    DRATE_FIXEDCHANNEL_1953 = 0x0     //DRATE[1:0]-00
};

enum enVoltUnit{
    UNIT_V = 0,
    UNIT_mV,
    UNIT_uV
};

struct stPinInfo
{
    int32 port;
    int32 bit;
};

struct stCommBus
{
    stPinInfo stSCKL;
    stPinInfo stCS;
    stPinInfo stDIN;
    stPinInfo stDOUT;

    stPinInfo stPWDN;
    stPinInfo stSTART;
    stPinInfo stRST;
};


class PCIE_EXPORT Pcie
{
public:
    Pcie();

    bool Init();

    bool isOpen(){return m_bOpen;}

    void CheckError(ErrorCode errorCode);

    bool WriteBit(int32 port, int32 bit, uint8 data);

    bool ReadBit(int32 port, int32 bit, uint8 &data);

    void Reset(); //复位AD芯片功能

    double VoltUnitConvert(double value,int unit);

    double ADCTemp();

    double VREF();

    double VCC();

    double OFFSET();

    double AIN0(int Unit=UNIT_mV);

    double AIN1(int Unit=UNIT_mV);

    double AIN2(int Unit=UNIT_mV);

    double AIN3(int Unit=UNIT_mV);

    double AIN4(int Unit=UNIT_mV);

    double AIN5(int Unit=UNIT_mV);

    double AIN6(int Unit=UNIT_mV);

    double AIN7(int Unit=UNIT_mV);

    double AIN8(int Unit=UNIT_mV);

    double AIN9(int Unit=UNIT_mV);

    double AIN10(int Unit=UNIT_mV);

    double AIN11(int Unit=UNIT_mV);

    double AIN12(int Unit=UNIT_mV);

    double AIN13(int Unit=UNIT_mV);

    double AIN14(int Unit=UNIT_mV);

    double AIN15(int Unit=UNIT_mV);

    double GAIN();

    ///*********新增加的部分
    int32 ReadChannelData();

    void SetRegister(uint8 addr,uint8 cmd);

    void SetMultRegister(uint8 addr,uint8 cmd);

    void WriteByte(uint8 data);

    uint8 ReadByte();

    uint8 ReadByte(uint8 data);

    uint8 ReadRegister(uint8 addr);

    void  ByteConverToBin(uint8 byte,uint8 *bin);

    uint8 BinConverToByte(uint8 data[]);
    ///*********新增加的部分

public:
    bool SetDUT1();

    bool SetDUT2();

    bool SetDUT3();

    bool SetDUT4();

    bool SetCURR1();

    bool SetCURR2();

    bool SetCURR3();

    bool SetCURR4();
public:
    bool SetDUT(int nDut);

    bool SetDUTStation(int nDut,int nCol,int nRow);

    bool SetStation(int nCol,int nRow);

    bool SetFRStation(int nCol,int nRow);

    bool SetCURRStation(int nCol,int nRow);

private:
    bool InitPCIE();

    bool InitADS1258();

    bool InitTTL();

public:

    InstantDoCtrl *m_instantDoCtrl;   //PCIE-1751设备

    stPinInfo DRDY;
    stPinInfo DOUT;

    stPinInfo PWDN;

    stPinInfo START;
    stPinInfo DIN;
    stPinInfo SCLK;
    stPinInfo CS;
    stPinInfo RST;

private:
    QString m_description;

    bool m_bOpen;

    ICollection<PortDirection> * m_portDirection;


};

#endif // PCIE_H

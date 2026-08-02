# PCIE_Driver

本项目使用 **研华 PCIE-1751** 数字量 I/O 板卡模拟 SPI 通讯时序，实现与 **ADS1258**（24 位、16 通道模数转换器）的通讯，读取 ADS1258 各通道的电压值，并提供图形化测试工具。

**软件版本号：v1.0.0**

## 功能特性

- 通过 PCIE-1751 的 GPIO 软件模拟 SPI 时序（SCLK / CS / DIN / DOUT），无需专用 SPI 控制器
- 支持 ADS1258 寄存器读写、通道数据读取、芯片复位
- 支持读取 16 路模拟输入通道（AIN0 ~ AIN15）电压值，单位可选 V / mV / uV
- 支持读取芯片温度（Temp）、基准电压（VREF）、电源电压（VCC）、失调（OFFSET）、增益（GAIN）等内部测量量
- 支持自动扫描（Auto-Scan）与固定通道（Fixed-Channel）两种采样模式及数据速率设置
- 提供基于 Qt 的图形界面测试工具 PCIE_TOOL

## 硬件连接

PCIE-1751 数字量端口与 ADS1258 引脚对应关系：

| PCIE-1751 (GPIO) | ADS1258 | 方向 |
|------------------|---------|------|
| DO (SCLK)        | SCLK    | 输出 |
| DO (CS)          | CS      | 输出 |
| DO (DIN)         | DIN     | 输出 |
| DI (DOUT)        | DOUT    | 输入 |
| DI (DRDY)        | DRDY    | 输入 |
| DO (PWDN)        | PWDN    | 输出 |
| DO (START)       | START   | 输出 |
| DO (RST)         | RST     | 输出 |

板卡设备描述：`PCIE-1751,BID#1`，参考电压 V_REF = 4.096 V。

## 项目结构

```
PCIE_Driver-master/
├── PCIE.pro                # Qt 子项目工程（subdirs 模板）
├── PCIE_Driver/pcie/       # pcie 动态库：封装 PCIE-1751 与 ADS1258 通讯逻辑
├── PCIE_TOOL/PCIE_TOOL/    # PCIE_TOOL 图形界面测试工具
└── bin/                    # 编译输出（pcie.dll、PCIE_TOOL.exe）
```

- **pcie.dll**：核心驱动库，基于研华 DAQNavi SDK 操作 PCIE-1751，实现模拟 SPI 时序及 ADS1258 寄存器/数据读写接口
- **PCIE_TOOL**：调用 pcie.dll 的 Qt Widgets 上位机，提供初始化、寄存器读写、通道电压读取、复位、温度/基准电压读取等操作界面

## 开发环境依赖

- Windows
- Qt（Qt Creator / qmake 构建）
- 研华 DAQNavi SDK（默认安装路径 `C:/Advantech/DAQNavi`）
- 研华 PCIE-1751 板卡及驱动

## 构建说明

1. 安装研华 DAQNavi SDK 及 PCIE-1751 驱动
2. 使用 Qt Creator 打开根目录 `PCIE.pro`
3. 执行 qmake 后构建，先编译 `PCIE_Driver` 生成 pcie.dll，再编译 `PCIE_TOOL`
4. 输出文件位于 `bin/` 目录

## 版本

- **v1.0.0**：初始版本，实现 PCIE-1751 模拟 SPI 与 ADS1258 通讯，读取各通道电压值

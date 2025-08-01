<!--
Copyright (C) 2025 Gunar Schorcht

This file is subject to the terms and conditions of the GNU Lesser
General Public License v2.1. See the file LICENSE in the top level
directory for more details.
-->

@defgroup   cpu_esp32_esp32s3 ESP32-S3 family
@ingroup    cpu_esp32
@brief      Specific properties of ESP32-S3 variant (family)
@author     Gunar Schorcht <gunar@schorcht.net>

\section esp32_riot_esp32s3  Specific properties of ESP32-S3 variant (family)

## Embedded Flash and SPI RAM {#esp32_embedded_flash_ram_esp32s3}

There are many different versions of the ESP32-S3 chip and ESP32-S3 modules
used on ESP32-S3 boards. They differ in the size of embedded Flash and SPI RAM
as well as used SPI mode for Flash and SPI RAM.
These differences allow dozens of different versions of a board. For example,
there are 8 versions of the ESP32-S3 DevKitC-1 board with different flash
and SPI RAM sizes.

<center>
| Chip          | Flash (Mode)    | SPI RAM (Mode)   | SPI Voltage
|:--------------|:---------------:|:----------------:|:-----------
| ESP32-S3      | -               | -                | 3.3 V/1.8 V
| ESP32-S3FN8   | 8 MB (Quad SPI) | -                | 3.3 V
| ESP32-S3R2    | -               | 2 MB (Quad SPI)  | 3.3 V
| ESP32-S3R8    | -               | 8 MB (Octal SPI) | 3.3 V
| ESP32-S3R8V   | -               | 8 MB (Octal SPI) | 1.8 V
| ESP32-S3FH4R2 | 4 MB (Quad SPI) | 2 MB (Quad SPI)  | 3.3 V
</center>
<br>

<center>
| Module                   | Chip          | Flash (Mode)      | SPI RAM (Mode)
|:-------------------------|:--------------|:-----------------:|:--------------
| ESP32-S3-WROOM-1x-N4     | ESP32-S3      | 4 MB (Quad SPI)   | -
| ESP32-S3-WROOM-1x-N8     | ESP32-S3      | 8 MB (Quad SPI)   | -
| ESP32-S3-WROOM-1x-N16    | ESP32-S3      | 16 MB (Quad SPI)  | -
| ESP32-S3-WROOM-1x-H4     | ESP32-S3      | 4 MB (Quad SPI)   | -
| ESP32-S3-WROOM-1x-N4R2   | ESP32-S3R2    | 4 MB (Quad SPI)   | 2 MB (Quad SPI)
| ESP32-S3-WROOM-1x-N8R2   | ESP32-S3R2    | 8 MB (Quad SPI)   | 2 MB (Quad SPI)
| ESP32-S3-WROOM-1x-N16R2  | ESP32-S3R2    | 16 MB (Quad SPI)  | 2 MB (Quad SPI)
| ESP32-S3-WROOM-1x-N4R8   | ESP32-S3R8    | 4 MB (Quad SPI)   | 8 MB (Octal SPI)
| ESP32-S3-WROOM-1x-N8R8   | ESP32-S3R8    | 8 MB (Quad SPI)   | 8 MB (Octal SPI)
| ESP32-S3-WROOM-1x-N16R8  | ESP32-S3R8    | 16 MB (Quad SPI)  | 8 MB (Octal SPI)
| ESP32-S3-WROOM-2-N16R8V  | ESP32-S3R8V   | 16 MB (Octal SPI) | 8 MB (Octal SPI)
| ESP32-S3-WROOM-2-N32R8V  | ESP32-S3R8V   | 32 MB (Octal SPI) | 8 MB (Octal SPI)
| ESP32-S3-MINI-1x-N8      | ESP32-S3FN8   | 8 MB (Quad SPI)   | -
| ESP32-S3-MINI-1x-N4R2    | ESP32-S3FH4R2 | 4 MB (Quad SPI)   | 2 MB (Quad SPI)
| ESP32-S3-MINI-1x-H4R2    | ESP32-S3FH4R2 | 4 MB (Quad SPI)   | 2 MB (Quad SPI)

</center>
<b>x</b> Stands for the module versions with and without U (external antenna connector).
<br>

Depending on the chip or module used, it has to be specified as a feature in
the board definition whether SPI RAM is available (feature \ref esp32_spi_ram
"esp_spi_ram") and whether Octal SPI Mode is used for the SPI RAM (feature
\ref esp32_spi_ram "esp_spi_oct").

If the feature `esp_spi_ram` is given, the SPI RAM can be used as heap by
using the pseudo module `esp_spi_ram`.

If **Quad SPI mode** is used, **GPIO26 ... GPIO32** are occupied and cannot be
used for other purposes. In case of **Octal SPI mode**, the pseudomodule
`esp_spi_oct` is additionally enabled and **GPIO33 ... GPIO37** are occupied
if the SPI RAM is enabled by using the pseudomodule `esp_spi_ram`.
GPIO33 ... GPIO37 are then not available for other purposes.
Conflicts may occur when using these GPIOs.

## GPIO pins {#esp32_gpio_pins_esp32s3}

ESP32-S3 has 45 GPIO pins, where a subset can be used as ADC channel and as
low-power digital input/output in deep-sleep mode, the so-called RTC GPIOs.
Some of them are used by special SoC components and are not broken out on
all ESP32-S3 modules. The following table gives a short overview.

<center>

Pin    | Type   | ADC | RTC  | PU / PD | Special function | Remarks
-------|:-------|:---:|:----:|:-------:|------------------|--------
GPIO0  | In/Out | -   | X    | X       | -                | Bootstrapping
GPIO1  | In/Out | X   | X    | X       | -                | -
GPIO2  | In/Out | X   | X    | X       | -                | -
GPIO3  | In/Out | X   | X    | X       | -                | Bootstrapping
GPIO4  | In/Out | X   | X    | X       | -                | -
GPIO5  | In/Out | X   | X    | X       | -                | -
GPIO6  | In/Out | X   | X    | X       | -                | -
GPIO7  | In/Out | X   | X    | X       | -                | -
GPIO8  | In/Out | X   | X    | X       | -                | -
GPIO9  | In/Out | X   | X    | X       | -                | -
GPIO10 | In/Out | X   | X    | X       | -                | -
GPIO11 | In/Out | X   | X    | X       | -                | -
GPIO12 | In/Out | X   | X    | X       | -                | -
GPIO13 | In/Out | X   | X    | X       | -                | -
GPIO14 | In/Out | X   | X    | X       | -                | -
GPIO15 | In/Out | X   | X    | X       | XTAL_32K_P       | External 32k crystal
GPIO16 | In/Out | X   | X    | X       | XTAL_32K_N       | External 32k crystal
GPIO17 | In/Out | X   | X    | X       | -                | -
GPIO18 | In/Out | X   | X    | X       | -                | -
GPIO19 | In/Out | X   | X    | X       | USB D-           | USB 2.0 OTG / USB-JTAG bridge
GPIO20 | In/Out | X   | X    | X       | USB D+           | USB 2.0 OTG / USB-JTAG bridge
GPIO21 | In/Out | -   | X    | X       | -                | -
GPIO26 | In/Out | -   | -    | X       | Flash/PSRAM SPICS1 | not available if SPI RAM is used
GPIO27 | In/Out | -   | -    | X       | Flash/PSRAM SPIHD  | not available
GPIO28 | In/Out | -   | -    | X       | Flash/PSRAM SPIWP  | not available
GPIO29 | In/Out | -   | -    | X       | Flash/PSRAM SPICS0 | not available
GPIO30 | In/Out | -   | -    | X       | Flash/PSRAM SPICLK | not available
GPIO31 | In/Out | -   | -    | X       | Flash/PSRAM SPIQ   | not available
GPIO32 | In/Out | -   | -    | X       | Flash/PSRAM SPID   | not available
GPIO33 | In/Out | -   | -    | X       | Flash/PSRAM SPIQ4  | not available if octal Flash or SPI RAM is used
GPIO34 | In/Out | -   | -    | X       | Flash/PSRAM SPIQ5  | not available if octal Flash or SPI RAM is used
GPIO35 | In/Out | -   | -    | X       | Flash/PSRAM SPIQ6  | not available if octal Flash or SPI RAM is used
GPIO36 | In/Out | -   | -    | X       | Flash/PSRAM SPIQ7  | not available if octal Flash or SPI RAM is used
GPIO37 | In/Out | -   | -    | X       | Flash/PSRAM SPIQ8  | not available if octal Flash or SPI RAM is used
GPIO38 | In/Out | -   | -    | X       | Flash/PSRAM SPIDQS | not available if octal Flash or SPI RAM is used
GPIO39 | In/Out | -   | -    | X       | MTCK               | JTAG interface
GPIO40 | In/Out | -   | -    | X       | MTDO               | JTAG interface
GPIO41 | In/Out | -   | -    | X       | MTDI               | JTAG interface
GPIO42 | In/Out | -   | -    | X       | MTMS               | JTAG interface
GPIO43 | In/Out | -   | -    | X       | UART0 TX           | Console
GPIO44 | In/Out | -   | -    | X       | UART0 RX           | Console
GPIO45 | In/Out | -   | -    | X       | -                  | Bootstrapping (0 - 3.3V, 1 - 1.8V)
GPIO46 | In/Out | -   | -    | X       | -                  | Bootstrapping
GPIO47 | In/Out | -   | -    | X       | SPICLK_P           | -
GPIO48 | In/Out | -   | -    | X       | SPICLK_N           | -

</center>
<b>PSRAM</b> - Stands for pseudo-static RAM and refers to the SPI RAM.
<br>

<b>ADC:</b> Pins that can be used as ADC channels.<br>
<b>RTC:</b> Pins that are RTC GPIOs and can be used in deep-sleep mode.<br>
<b>PU/PD:</b> Pins that have software configurable pull-up/pull-down functionality.<br>

### Strapping pins {#esp32_gpio_pins_esp32s3_strapping}

GPIO0, GPIO3, GPIO45 and GPIO46 are bootstrapping. GPIO0 and GPIO46 pins are
used to boot ESP32-S3 in different modes:

<center>

GPIO0 | GPIO46 | Mode
:----:|:------:|----------
1     | X      | SPI Boot mode to boot the firmware from flash (default mode)
0     | 1      | Download Boot mode for flashing the firmware

</center><br>

If `EFUSE_STRAP_JTAG_SEL` is set, GPIO3 is used to select the interface that
is used as JTAG interface.

<center>

GPIO3 | Mode
:----:|------------------------
1     | USB-JTAG bridge at GPIO19 and GPIO20 is used as JTAG interface
0     | GPIO39 to GPIO42 are used as JTAG interface

</center><br>

@note `If EFUSE_DIS_USB_JTAG` or `EFUSE_DIS_PAD_JTAG` are set, the interface
selection is fixed and GPIO3 is not used as bootstrapping pin.

GPIO45 is used to select the voltage `VDD_SPI` for the Flash/PSRAM interfaces
SPI0 and SPI1.

## ADC Channels {#esp32_adc_channels_esp32s3}

ESP32-S3 integrates two 12-bit ADCs (ADC1 and ADC2) with 20 channels in
total:

- **ADC1** supports 10 channels: GPIO1 ... GPIO10
- **ADC2** supports 10 channels: GPIO11 ... GPIO20

@note
- ADC2 is also used by the WiFi module. The GPIOs connected to ADC2 are
  therefore not available as ADC channels if the modules `esp_wifi` or
  `esp_now` are used.
- GPIO3 is a strapping pin und shouldn't be used as ADC channel

## I2C Interfaces {#esp32_i2c_interfaces_esp32s3}

ESP32-S3 has two built-in I2C interfaces.

The following table shows the default configuration of I2C interfaces
used for ESP32-S3 boards. It can be overridden by
[application-specific configurations](#esp32_application_specific_configurations).

<center>

Device     | Signal | Pin    | Symbol        | Remarks
:----------|:-------|:-------|:--------------|:----------------
I2C_DEV(0) |        |        | `#I2C0_SPEED` | default is `I2C_SPEED_FAST`
I2C_DEV(0) | SCL    | GPIO9  | `#I2C0_SCL`   | -
I2C_DEV(0) | SDA    | GPIO8  | `#I2C0_SDA`   | -

</center><br>

## PWM Channels {#esp32_pwm_channels_esp32s3}

The ESP32-S3 LEDC module has 1 channel group with 8 channels. Each of
these channels can be clocked by one of the 4 timers.

## SDMMC Interfaces {#esp32_sdmmc_interfaces_esp32s3}

The ESP32-S3 variant uses the GPIO matrix (i.e. `SOC_SDMMC_USE_GPIO_MATRIX`
is defined in the SoC Capabilities file) to route the SDMMC signals to
arbitrary pins. The GPIOs used for the SDMMC signals are therefore
configurable and have to be defined in the board-specific configuration in
array @ref sdmmc_config in addition to the used slot.

The width of the data bus used is determined by the GPIOs defined for the
DAT lines. To use a 1-bit data bus, only DAT0 (@ref sdmmc_conf_t::dat0)
must be defined. All other GPIOs for the DAT lines must be set undefined
(@ref GPIO_UNDEF). For a 4-bit data bus, the GPIOs for pins DAT1 to DAT3
(@ref sdmmc_conf_t::dat1 ... @ref sdmmc_conf_t::dat3) must also be defined.
An 8-bit data bus width requires the definition of DAT4 to DAT7
(@ref sdmmc_conf_t::dat4 ... @ref sdmmc_conf_t::dat7) and the enabling
of the `periph_sdmmc_8bit` module.

The following example shows a configuration with 4-bit or 8-bit data
bus width dependent on whether the `periph_sdmmc_8bit` module is enabled.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~{.c}
static const sdmmc_conf_t sdmmc_config[] = {
    {
        .slot = SDMMC_SLOT_0,
        .cd = GPIO16,
        .wp = GPIO_UNDEF,
        .clk = GPIO14,
        .cmd = GPIO15,
        .dat0 = GPIO2,
        .dat1 = GPIO4,
        .dat2 = GPIO12,
        .dat3 = GPIO13,
#if IS_USED(MODULE_PERIPH_SMMC_8BIT)
        .dat4 = GPIO33,
        .dat5 = GPIO33,
        .dat6 = GPIO33,
        .dat7 = GPIO33,
#endif
    },
};

#define SDMMC_NUMOF 1
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

If the board supports a Card Detect pin or a Write Protect pin, the
corresponding GPIOs have to be defined in @ref sdmmc_conf_t::cd and
@ref sdmmc_conf_t::wp. Otherwise they have to be set to undefined
(@ref GPIO_UNDEF).

## SPI Interfaces {#esp32_spi_interfaces_esp32s3}

ESP32-S3 has four SPI controllers where SPI0 and SPI1 share the same bus
and can only operate in memory mode while SPI2 and SPI3 can be used as general
purpose SPI:

- controller SPI0 is reserved for external memories like Flash and PSRAM
- controller SPI1 is reserved for external memories like Flash and PSRAM
- controller SPI2 can be used for peripherals (also called FSPI)
- controller SPI3 can be used for peripherals

Thus, SPI2 (`FSPI`) and SPI3 can be used as general purpose SPI in
RIOT as SPI_DEV(0) and SPI_DEV(1) by defining the symbols `SPI0_*`
and `SPI1_*`.

The following table shows the pin configuration used by default, even
though it **can vary** from board to board.

<center>

Device                  | Signal | Pin    | Symbol      | Remarks
:-----------------------|:------:|:-------|:-----------:|:---------------------------
`SPI0_HOST`/`SPI1_HOST` | SPICS0 | GPIO29 | - | reserved for flash and PSRAM
`SPI0_HOST`/`SPI1_HOST` | SPICS1 | GPIO26 | - | reserved for flash and PSRAM
`SPI0_HOST`/`SPI1_HOST` | SPICLK | GPIO30 | - | reserved for flash and PSRAM
`SPI0_HOST`/`SPI1_HOST` | SPID   | GPIO32 | - | reserved for flash and PSRAM
`SPI0_HOST`/`SPI1_HOST` | SPIQ   | GPIO31 | - | reserved for flash and PSRAM
`SPI0_HOST`/`SPI1_HOST` | SPIHD  | GPIO27 | - | reserved for flash and PSRAM (only in `qio` or `qout` mode)
`SPI0_HOST`/`SPI1_HOST` | SPIWP  | GPIO28 | - | reserved for flash and PSRAM (only in `qio` or `qout` mode)
`SPI0_HOST`/`SPI1_HOST` | SPIIO4 | GPIO33 | - | reserved for Flash and PSRAM (only in octal mode)
`SPI0_HOST`/`SPI1_HOST` | SPIIO5 | GPIO34 | - | reserved for Flash and PSRAM (only in octal mode)
`SPI0_HOST`/`SPI1_HOST` | SPIIO6 | GPIO35 | - | reserved for Flash and PSRAM (only in octal mode)
`SPI0_HOST`/`SPI1_HOST` | SPIIO7 | GPIO36 | - | reserved for Flash and PSRAM (only in octal mode)
`SPI0_HOST`/`SPI1_HOST` | SPIDQA | GPIO37 | - | reserved for Flash and PSRAM (only in octal mode)
`SPI2_HOST` (`FSPI`)    | SCK    | GPIO12 |`#SPI0_SCK`  | can be used
`SPI2_HOST` (`FSPI`)    | MOSI   | GPIO11 |`#SPI0_MOSI` | can be used
`SPI2_HOST` (`FSPI`)    | MISO   | GPIO13 |`#SPI0_MISO` | can be used
`SPI2_HOST` (`FSPI`)    | CS0    | GPIO10 |`#SPI0_CS0`  | can be used

</center><br>

## Timers {#esp32_timers_esp32s3}

ESP32-S3 has two timer groups with two timers each, resulting in a total of
four timers. Since one timer is used as system timer, up to three timers
with one channel each can be used in RIOT as timer devices
TIMER_DEV(0) ... TIMER_DEV(2).

Additionally ESP32-S3 has three CCOMPARE registers which can be used
alternatively as timer devices TIMER_DEV(0) ... TIMER_DEV(2) can be used
in RIOT if the module `esp_hw_counter` is enabled.

## UART Interfaces {#esp32_uart_interfaces_esp32s3}

ESP32 integrates three UART interfaces. The following default pin
configuration of UART interfaces as used by a most boards can be overridden
by the application, see section [Application-Specific Configurations]
(#esp32_application_specific_configurations).

<center>

Device      |Signal|Pin     |Symbol      |Remarks
:-----------|:-----|:-------|:-----------|:----------------
UART_DEV(0) | TxD  | GPIO43 |`#UART0_TXD`| cannot be changed
UART_DEV(0) | RxD  | GPIO44 |`#UART0_RXD`| cannot be changed
UART_DEV(1) | TxD  | GPIO17 |`#UART1_TXD`| optional, can be overridden
UART_DEV(1) | RxD  | GPIO18 |`#UART1_RXD`| optional, can be overridden
UART_DEV(2) | TxD  | -      |`UART2_TXD` | optional, can be overridden
UART_DEV(2) | RxD  | -      |`UART2_RXD` | optional, can be overridden

</center><br>

## JTAG Interface {#esp32_jtag_interface_esp32s3}

There are two options on how to use the JTAG interface on ESP32-S3:

1.  Using the built-in USB-to-JTAG bridge connected to an USB cable as follows:
    USB Signal     | ESP32-S3 Pin
    :--------------|:-----------
    D- (white)     | GPIO19
    D+ (green)     | GPIO20
    V_Bus (red)    | 5V
    Ground (black) | GND
    <br>
    @note This option requires that the USB D- and USB D+ signals are connected
          to the ESP32-S3 USB interface at GPIO19 and GPIO20.

2.  Using an external JTAG adapter connected to the JTAG interface exposed
    to GPIOs as follows:
    JTAG Signal | ESP32S3 Pin
    :-----------|:-----------
    TRST_N      | CHIP_PU
    TDO         | GPIO40 (MTDO)
    TDI         | GPIO41 (MTDI)
    TCK         | GPIO39 (MTCK)
    TMS         | GPIO42 (MTMS)
    GND         | GND


Using the built-in USB-to-JTAG is the default option, i.e. the JTAG interface
of the ESP32-S3 is connected to the built-in USB-to-JTAG bridge. To use an
external JTAG adapter, the JTAG interface of the ESP32-S3 has to be connected
to the GPIOs as shown above. For this purpose eFuses have to be burned with
the following command:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
espefuse.py burn_efuse JTAG_SEL_ENABLE --port /dev/ttyUSB0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Once the eFuses are burned with this command and option `JTAG_SEL_ENABLE`,
GPIO3 is used as a bootstrapping pin to choose between the two options.
If GPIO3 is HIGH when ESP32-S3 is reset, the JTAG interface is connected
to the built-in USB to JTAG bridge and the USB cable can be used for on-chip
debugging. Otherwise, the JTAG interface is exposed to GPIO39 ... GPIO42
and an external JTAG adapter has to be used.

Alternatively, the integrated USB-to-JTAG bridge can be permanently disabled
with the following command:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
espefuse.py burn_efuse DIS_USB_JTAG --port /dev/ttyUSB0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Once the eFuses are burned with this command and option `DIS_USB_JTAG`,
the JTAG interface is always exposed to GPIO4 ... GPIO7 and an external
JTAG adapter has to be used.

@note Burning eFuses is an irreversible operation.

For more information about JTAG configuration for ESP32-S3, refer to the
section [Configure Other JTAG Interface]
(https://docs.espressif.com/projects/esp-idf/en/latest/esp32s3/api-guides/jtag-debugging/configure-other-jtag.html)
in the ESP-IDF documentation.

@defgroup    boards_nrf5340dk-app nRF5340DK
@ingroup     boards
@brief       Support for the nRF5340DK-app board

### General information

The nRF5340DK is a devboard based on nRF5340 MCU which offers a dual core
Cortex-M33 with one application core and one network core.
The network core is able to handle Bluetooth 5.3, BLE, mesh, NFC (only tag emulation, no reader support), Thread and
Zigbee connectivity.
Currently only the application core can be used with RIOT-OS.

The board features four LEDs, four user buttons/switches and a reset button.

### Links

- [nRF5340DK web page](https://infocenter.nordicsemi.com/topic/ug_nrf5340_dk/UG/dk/intro.html)
- [documentation and hardware description](https://infocenter.nordicsemi.com/index.jsp?topic=%2Fstruct_nrf53%2Fstruct%2Fnrf5340.html)

### Flash the board

The board is flashed using JLink or nrfjprog software. Programs needs to
be installed.

The process is automated in the usual `make flash` target.

### Accessing STDIO via UART

The STDIO is directly accessible via the USB port. On a Linux host, it's
generally mapped to `/dev/ttyACM0`.

Use the `term` target to connect to the board serial port<br/>
```
    make BOARD=nrf5340dk-app -C examples/basic/hello-world term
```

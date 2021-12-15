# Tutorial 3

This tutorial shows other ways to interact with the operating system,
through function bindings. Function bindings provide the virtual machine with an interface through which to interact with the host operating system during the execution of the virtual machine.

*Note*: This tutorial is under construction: for now it just shows how to use a femto-container to read sensor data and to advertize it as a Bluetooth Low-Energy (BLE) service.

## Goals

- Compile and run the heart-rate and temperature sensor femto-container example
- Show interaction through bindings
- Store read-only data in the application
- *(under construction)*

## Steps

### Make/flash/run the BLE sensor femto-container example

This example can run on any supported nrf52840 board, such as the Arduino Nano 33 BLE (Sense) or the nrf52840dk for instance.

This example demonstrates how to implement asynchronous data transfer using GATT notifications by implementing a mock-up BLE heart rate sensor. the heart rate sensor is simulated by simply providing an up- and down counter for its BPM value. On top of the heart rate service, this example implements the device information as well as the battery service and and temperature

- clone the code base `git clone https://github.com/bergzand/RIOT.git`
- step into the RIOT directory `cd RIOT`
- switch to the right branch `git checkout wip/ble_bpf_example`
- step into the example `cd examples/nimble_bpf`

From there, you can now go into the usual femto-container workflow:

- make sure your board is plugged in via USB
- compile the rBPF code hosted in the femtocontainer, which is located in the bpf/ directory `make -C bpf`
- compile flash and run RIOT embarking the femto-container `BOARD=arduino-nano-33-ble make flash term`

Your board is now flashed and should be operational. You can connect to your board via Bluetooth on your smartphone. For that we suggest using an app such as [nrfToolbox](https://play.google.com/store/apps/details?id=no.nordicsemi.android.nrftoolbox) and/or [nrfConnect](https://play.google.com/store/apps/details?id=no.nordicsemi.android.mcp)). 

To discover your board via the nrftoolbox app for instance, click on the heart rate icon and scan for your board which should appear at the end of the list.

*Note*: there might be small glitches, whereupon disconnecting/reconnecting the device from the smartphone app will help (and/or rebooting the board).

#### Borwsing femto-container code

To browse through the code hosted in the femto-containers for this example, check the files `bpf/hrs_sens.c` and `bpf/temp_sens.c` which contain logic for the heart rate data and for the temperature data respectively.



### Next Steps

Work-in-progress, stay tuned...

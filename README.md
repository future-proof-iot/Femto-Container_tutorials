# Femto-Containers

Femto-Containers are small containers hosting a virtual machine based on the Linux eBPF architecture, running on microcontroller-type devices. This makes it a suitable tool for DevOps workflows with small applications deployed on low-power IoT devices.
This [paper](https://dl.acm.org/doi/pdf/10.1145/3528535.3565242) describes Femto-Containers in details. If you want to cite this work, please cite it as such: 

*K. Zandberg, E. Baccelli, S. Yuan, F. Besson, JP Talpin. Femto-Containers: Lightweight Virtualization and Fault Isolation For Small Software Functions on Low-Power IoT Microcontrollers. In Proc. of 23rd ACM/IFIP MIDDLEWARE, Nov. 2022.*

## Open Source Implementation 

This repository is an open source implementation which hosts femto-containers on the operating system [RIOT](https://github.com/RIOT-OS/RIOT/). 
To start browsing through femto-containers source code, a good entry point is [here](https://github.com/bergzand/RIOT/tree/90c82c0cdf241b8c238f5d2946d5dfb519d8904b/examples/rbpf_sched).


### Preliminary Setup & Downloads

Before you try the femto-container tutorials, you need to set up your system. For this, please complete the steps listed in the [setup guide](https://github.com/future-proof-iot/Femto-Container_tutorials/tree/main/setup).


## Hands-on Tutorials

A number of tutorials are available below to get familiar with the
Femto-Container implementation in RIOT.


- [Tutorial 1] -- get started hosting Femto-Container applications on RIOT.

- [Tutorial 2] -- engage into more complex behaviour, learn how to pass context/return variables to/from the container.

- [Tutorial 3] -- use a femto-container to read sensor data and advertize it as a Bluetooth Low-Energy (BLE) service.

- [Tutorial 4] -- secure low-power DevOps-style interaction using Femto-container updates over the network, with SUIT-compliant security. (Tutorial currently based on an a separate artefact published at ACM Middleware 2022).

[Tutorial 1]: https://github.com/future-proof-iot/Femto-Container_tutorials/tree/main/tutorial_1
[Tutorial 2]: https://github.com/future-proof-iot/Femto-Container_tutorials/tree/main/tutorial_2
[Tutorial 3]: https://github.com/future-proof-iot/Femto-Container_tutorials/tree/main/tutorial_3
[Tutorial 4]: https://github.com/future-proof-iot/Femto-Container_tutorials/tree/main/tutorial_4

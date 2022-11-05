# Femto-Containers

Femto-Containers are small containers hosting a virtual machine based on the Linux eBPF architecture, running on microcontroller-type devices. This makes it a suitable tool for DevOps workflows with small applications deployed on low-power IoT devices.

## Open Source Implementation 

This repository is an open source implementation which hosts femto-containers on the operating system [RIOT](https://github.com/RIOT-OS/RIOT/). 
To start browsing through femto-containers source code, a good entry point is [here](https://github.com/bergzand/RIOT/tree/90c82c0cdf241b8c238f5d2946d5dfb519d8904b/examples/rbpf_sched).


### Preliminary Setup & Downloads

Before you try the femto-container tutorials, you need to set up your system. For this, please complete the steps listed in the [setup guide](https://github.com/future-proof-iot/Femto-Container_tutorials/tree/main/setup).


## Hands-on Tutorials

A number of tutorials are available below to get familiar with the
Femto-Container implementation in RIOT.


- [Tutorial 1]

  This tutorial shows how to get started hosting
  Femto-Container applications on RIOT.

- [Tutorial 2]

  This tutorial shows somewhat more complex behaviour with a focus on how to 
pass context variables to the container and return values from the container

- [Tutorial 3]

  This tutorial shows how to use a femto-container to read sensor data and advertize
it as a Bluetooth Low-Energy (BLE) service.

- [Tutorial 4] (work-in-progress)

  Tutorial 4 shows secure low-power DevOps-style interaction over the network using Femto-Containers.

## Further Reading & References

This [paper](https://arxiv.org/pdf/2210.03432.pdf) describes Femto-Containers in details. If you want to cite this work, please cite it as such: 

K. Zandberg, E. Baccelli, S. Yuan, F. Besson, JP Talpin. Femto-Containers: Lightweight Virtualization and Fault Isolation For Small Software Functions on Low-Power IoT Microcontrollers. In Proc. of 23rd ACM/IFIP MIDDLEWARE, Nov. 2022.

[Tutorial 1]: https://github.com/future-proof-iot/Femto-Container_tutorials/tree/main/tutorial_1
[Tutorial 2]: https://github.com/future-proof-iot/Femto-Container_tutorials/tree/main/tutorial_2
[Tutorial 3]: https://github.com/future-proof-iot/Femto-Container_tutorials/tree/main/tutorial_3
[Tutorial 4]: https://github.com/future-proof-iot/Femto-Container_tutorials/tree/main/tutorial_4

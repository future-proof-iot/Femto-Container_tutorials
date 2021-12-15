# Femto-Containers

Femto-Containers are small containers hosting a virtual machine based on the Linux eBPF architecture, running on microcontroller-type devices. This makes it a suitable tool for DevOps workflows with small applications deployed on low-power IoT devices.

## Open Source Implementation 

This repository is an open source implementation which hosts femto-containers on the operating system [RIOT](https://github.com/RIOT-OS/RIOT/). 
To start browsing through femto-containers source code, a good entry point is [here](https://github.com/bergzand/RIOT/tree/90c82c0cdf241b8c238f5d2946d5dfb519d8904b/examples/rbpf_sched).

To download the source code and this tutorial, just open a terminal and enter the following commands:

`git clone https://github.com/future-proof-iot/Femto-Container_tutorials.git`

`git submodule init`

`git submodule update`


### Toolchain setup

These preliminary steps are required to setup your system for the tutorials.

#### Setup for eBPF/rBPF
To compile the BPF code for the Femto-Containers the following applications and
libraries are required:

- LLVM
- Clang
- Python 3.6 or higher
- [pyelftools](https://github.com/eliben/pyelftools)

Please ensure that these are installed and verify that llvm supports generating
eBPF code by executing:

```Console
$ llc --version
```

Check that "bpf" is in the resulting list of registered targets.

#### Setup for RIOT
Please follow the steps from the [RIOT
documentation](https://doc.riot-os.org/getting-started.html) to get started with
this. The toolchain setup can be verified by compiling a simple RIOT example
such as the
[Hello World](https://github.com/RIOT-OS/RIOT/tree/master/examples/hello-world)
example.



## Hands-on Tutorials

A number of tutorials are available below to get familiar with the
Femto-Container implementation in RIOT.


- [Tutorial 1]

  This tutorial shows how to get started hosting
  Femto-Container applications on RIOT.

- [Tutorial 2]

  This Tutorial shows somewhat more complex behaviour with a focus on how to
  pass context variables to the container and return values from the container

- [Tutorial 3] (work-in-progress)

  Tutorial 3 shows how to use a femto-container to read sensor data and advertize it as a Bluetooth Low-Energy (BLE) service.

- [Tutorial 4] (work-in-progress)

  Tutorial 4 shows secure low-power DevOps-style interaction over the network using Femto-Containers.

## Further Reading & References

This [preprint](https://arxiv.org/pdf/2106.12553.pdf) describes Femto-Containers in details.
This [paper](https://arxiv.org/pdf/2011.12047.pdf) describes the rBPF interpreter and the porting of the eBPF instruction set to various microcontrollers.

[Tutorial 1]: https://github.com/future-proof-iot/Femto-Container_tutorials/tree/main/tutorial_1
[Tutorial 2]: https://github.com/future-proof-iot/Femto-Container_tutorials/tree/main/tutorial_2
[Tutorial 3]: https://github.com/future-proof-iot/Femto-Container_tutorials/tree/main/tutorial_3
[Tutorial 4]: https://github.com/future-proof-iot/Femto-Container_tutorials/tree/main/tutorial_4

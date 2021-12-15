


## Download \& Toolchain Setup

To download the source code and this tutorial, just open a terminal and enter the following commands:

`git clone https://github.com/future-proof-iot/Femto-Container_tutorials.git`

`git submodule init`

`git submodule update`

These preliminary steps are required to setup your system for the tutorials.

### Setup for eBPF/rBPF
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

### Setup for RIOT
Please follow the steps from the [RIOT
documentation](https://doc.riot-os.org/getting-started.html) to get started with
this. The toolchain setup can be verified by compiling a simple RIOT example
such as the
[Hello World](https://github.com/RIOT-OS/RIOT/tree/master/examples/hello-world)
example.


Now that you're all setup, you can return to the [femto-container tutorials](https://github.com/future-proof-iot/Femto-Container_tutorials) hands-on.

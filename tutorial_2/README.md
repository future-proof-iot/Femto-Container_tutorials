# Tutorial 2

In tutorial 1 the first steps to start with Femto-Containers were shown. In this
second tutorial a more complex example is used to show more interaction between
the Femto-Containers virtual machine and the RIOT operating system.

## Goals

- Understanding of shared structures and data type
- Modification of the Femto-Container application

## Steps

### Femto-Container application

The Femto-Container application code for this tutorial is in the
`fc/multiply_add.c` file. It contains a simple function to multiply two
user-supplied values and add a constant to the result. The context structure
used to pass arguments to the function is declared at the top of the file.
The calling operating system is supposed to pass this struct as a pointer to the
virtual machine and the application operates on the struct members.
The include for the `stdint.h` header is required for the `uint64_t` members.

Use make to compile the example code:

```Console
$ make -C fc
```

The content of the resulting binary can be viewed with:

```Console
$ ../RIOT/dist/tools/rbpf/gen_rbf.py dump fc/multiply_add.bin
Magic:          0x46504272
Version:        0
flags:  0x0
Data length:    0 B
RoData length:  16 B
Text length:    40 B
No. functions:  1

functions:
        "multiply_add": 0x0

data:

rodata:
    0: 0x6d 0x75 0x6c 0x74 0x69 0x70 0x6c 0x79
    8: 0x5f 0x61 0x64 0x64 0x00 0x00 0x00 0x00

text:
<multiply_add>
    0x0:        79 12 00 00 00 00 00 00 r2 = *(uint64_t*)(r1 + 0)
    0x8:        79 10 08 00 00 00 00 00 r0 = *(uint64_t*)(r1 + 8)
   0x10:        2f 20 00 00 00 00 00 00 r0 *= r2
   0x18:        07 00 00 00 05 00 00 00 r0 += 5
   0x20:        95 00 00 00 00 00 00 00 Return r0
```

Visible here is the application content.
The two numbers are loaded in instruction `0x0` and `0x8`. They are multiplied
and the constant value is added. Finally the return instruction returns the
resulting value to the caller of the VM.

### Compiling the RIOT code

The included RIOT application is very similar to the one in the first tutorial.
It is modified with the same context structure as the Femto-Containers
application code. It is copied here for clarity, but could also be contained in
a header shared between the two files.

The main function sets up the context struct with some pre-compiled values and
passes it to the virtual machine.

Compile the example with:

```Console
$ make
```

and execute it with `make term`. It should show output similar to:

```Console
$ make term
RIOT native interrupts/signals initialized.
LED_RED_OFF
LED_GREEN_ON
RIOT native board initialized.
RIOT native hardware initialization complete.

main(): This is RIOT! (Version: 2017.01-devel-23600-g90c82-wip/bpf)
All up, running the Femto-Container application now
Input to the VM: 5, 8
Return code (expected 0): 0
Result of the VM: 45
```

### Modifying the example

In this step you're going to modify the Femto-Container application code and the
RIOT code to extend the context arguments to a third variable. This third
variable will replace the constant in the addition step of the Femto-Container
application.

First extend the context struct in both the Femto-Container application and the
RIOT `main.c` with a third value.

#### Sharing types between Femto-Container and the host

The Femto-Container virtual machine architecture is designed as a 64 bit
machine. This means in practice that an `unsigned int` is 64 bit. The platforms
supported by RIOT often use either 32 bit or 16 bit as word size.
When sharing values and structures between the host and the virtual machine,
care must be taking to ensure that both use the same sizes for the variables.
By always being explicit about this and use the fixed width integer types,
confusion and hard to catch errors can be avoided.

1. Modify the context struct *in both the femto-containers application and the
   `main.c`* to something like:

```C
typedef struct {
    uint64_t first;     /* First number */
    uint64_t second;    /* Second number */
    uint32_t addition   /* value to add to the multiplication result */
} context_t;
```

2. Then modify the code in the Femto-Container application to use the new member in
   the struct for the addition operation.

3. Modify the instantiation of the context struct to also include the new
   member, or leave it empty to initialize it to `0`.

4. Recompile the Femto-Containers application:

```Console
$ make -C fc
```

5. And recompile and execute the RIOT application

```Console
$ make
```

```Console
$ make term
RIOT native interrupts/signals initialized.
LED_RED_OFF
LED_GREEN_ON
RIOT native board initialized.
RIOT native hardware initialization complete.

main(): This is RIOT! (Version: 2017.01-devel-23600-g90c82-wip/bpf)
All up, running the Femto-Container application now
Input to the VM: 5, 8, 3
Return code (expected 0): 0
Result of the VM: 43
```


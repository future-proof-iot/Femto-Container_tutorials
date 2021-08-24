/*
 * Copyright (c) 2021 Koen Zandberg
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     examples
 * @{
 *
 * @file
 * @brief       BPF tutorial 1 example
 *
 * @author      Koen Zandberg <koen.zandberg@inria.fr>
 *
 * @}
 */
#include <stdio.h>

#include "bpf.h"
#include "blob/fc/multiply_add.bin.h"

/* Declare the context struct */
typedef struct {
    uint64_t first;     /* First number */
    uint64_t second;    /* Second number */
} context_t;

/* Pre-allocated stack for the virtual machine */
static uint8_t _stack[512] = { 0 };

int main(void)
{
    /* Initialize the bpf subsystem */
    bpf_init();

    puts("All up, running the Femto-Container application now");

    /* Define the application */
    bpf_t bpf = {
        .application = multiply_add_bin,             /* The container content */
        .application_len = sizeof(multiply_add_bin), /* Length of the application */
        .stack = _stack,                          /* Preallocated stack */
        .stack_size = sizeof(_stack),             /* And the length */
    };

    /* Context value to pass to the VM */
    context_t ctx = { 5, 8};
    int64_t result = 0;

    bpf_setup(&bpf);
    int res = bpf_execute_ctx(&bpf, &ctx, sizeof(ctx), &result);

    printf("Input to the VM: %ld, %ld\n", (unsigned long)ctx.first,
                                               (unsigned long)ctx.second);
    printf("Return code (expected 0): %d\n", res);
    printf("Result of the VM: %ld\n", (unsigned long)result);

    return 0;
}

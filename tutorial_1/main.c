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
#include "blob/fc/increment.bin.h"

/* Pre-allocated stack for the virtual machine */
static uint8_t _stack[512] = { 0 };

int main(void)
{
    /* Initialize the bpf subsystem */
    bpf_init();

    puts("All up, running the Femto-Container application now");

    /* Define the application */
    bpf_t bpf = {
        .application = increment_bin,             /* The increment.bin content */
        .application_len = sizeof(increment_bin), /* Length of the application */
        .stack = _stack,                          /* Preallocated stack */
        .stack_size = sizeof(_stack),             /* And the length */
    };

    /* Context value to pass to the VM */
    uint64_t ctx = 0;
    int64_t result = 0;

    bpf_setup(&bpf);
    int res = bpf_execute_ctx(&bpf, &ctx, sizeof(ctx), &result);

    printf("Input to the VM: %ld\n", (unsigned long)ctx);
    printf("Return code (expected 0): %d\n", res);
    printf("Result of the VM: %ld\n", (unsigned long)result);

    return 0;
}

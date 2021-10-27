#include <stdint.h>
#include "bpf/bpfapi/helpers.h"

#define THREAD_START_KEY    0x0

typedef struct {
    uint64_t previous; /* previous thread */
    uint64_t next;     /* next thread */
} pid_ctx_t;

int pid_log(pid_ctx_t *ctx)
{
 /* Zero pid means no next thread */
    if (ctx->next != 0) {
        uint32_t counter;
	uint32_t thread_key = THREAD_START_KEY +
                ctx->next;
        bpf_fetch_global(thread_key,
                         &counter);
        counter++;
        bpf_store_global(thread_key,
                         counter);
    }
    return  0;
}

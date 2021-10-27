#include <stdint.h>
#include "bpf/bpfapi/helpers.h"

#define SHARED_KEY 0x50
#define COAP_OPT_FINISH_PAYLOAD  (0x0001)

typedef struct {
    uint32_t hdr_p;       /* ptr to raw packet */
    uint32_t token_p;     /* ptr to token      */
    uint32_t payload_p;   /* ptr to payload    */
    uint16_t payload_len; /* length of payload */
    uint16_t options_len; /* length of options */
} bpf_coap_pkt_t;

int coap_resp(bpf_coap_ctx_t *gcoap)
{
    bpf_coap_pkt_t *pkt = gcoap->pkt;
    /* Track executions */
    uint32_t counter;
    bpf_fetch_global(SHARED_KEY, &counter);

    char stringified[20];
    size_t str_len = bpf_fmt_u32_dec(stringified,
                                     counter);

    /* Format the packet with a 205 code */
    bpf_gcoap_resp_init(gcoap, (2 << 5) | 5);
    /* Add Text type response header */
    bpf_coap_add_format(gcoap, 0);
    ssize_t pdu_len = bpf_coap_opt_finish(gcoap,
                 COAP_OPT_FINISH_PAYLOAD);

    uint8_t *payload = 
        (uint8_t*)(intptr_t)(pkt->payload_p);

    if (pkt->payload_len >= str_len) {
        bpf_memcpy(payload, stringified,
                   str_len);
        return pdu_len + str_len;
    }

    return  -1;
}

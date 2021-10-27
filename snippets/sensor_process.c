#include <stdint.h>
#include <stdbool.h>
#include "bpf/bpfapi/helpers.h"

#define SHARED_KEY 0x50
#define AVERAGING_LEN 10
#define PERIOD_US (1000 * 1000)

static uint32_t _average(uint32_t *values)
{
    uint64_t sum = 0;
    for (size_t i = 0;
        i < AVERAGING_LEN;
        i++) {
        sum += values[i];
    }
    return sum / AVERAGING_LEN;
}

int measurement(void *conf)
{
    uint32_t last_wakeup = bpf_ztimer_now();
    uint32_t counter = 0;
    size_t pos = 0;
    bool initial = true;

    uint32_t values[AVERAGING_LEN];

    while (1) {
        /* Read sensor value from sensor */
        bpf_saul_reg_t *sensor;
        phydat_t measurement;

        /* Periodic blocking sleep */
        bpf_ztimer_periodic_wakeup(&last_wakeup,
                 PERIOD_US);

        /* Find first sensor */
        sensor = bpf_saul_reg_find_nth(1);

        /* Abort if the sensor is
           not available */
        if (!sensor ||
            (bpf_saul_reg_read(sensor,
                               &measurement) < 0)
            ) {
            continue;
        }

        uint32_t value = measurement.val[0];

        if (initial) {
            /* Fill array with the
               initial measurement */
            for (size_t i = 0;
                 i < AVERAGING_LEN;
                 i++) {
                values[i] = value;
            }
            initial = false;
        }
        else {
            values[pos] = value;
            pos++;
            if (pos >= AVERAGING_LEN) {
                pos = 0;
            }
        }

        uint32_t average =
                 _average(values);

        bpf_store_global(SHARED_KEY,
                 average);
    }

    /* Unreacheable */
    return 0;
}


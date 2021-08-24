#include <stdint.h>

/* Declare the context struct */
typedef struct {
    uint64_t first;     /* First number */
    uint64_t second;    /* Second number */
} context_t;

/* Constant to add to the result */
static const uint64_t addition = 5;

uint64_t multiply_add(context_t *context)
{
    return context->first * context->second + 5;
}


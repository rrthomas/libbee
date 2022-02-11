// Test the memory operators. Also uses previously tested instructions.
// See errors.c for address error handling tests.
//
// (c) Reuben Thomas 1994-2022
//
// The package is distributed under the MIT/X11 License.
//
// THIS PROGRAM IS PROVIDED AS IS, WITH NO WARRANTY. USE IS AT THE USER’S
// RISK.

#include "tests.h"


int main(void)
{
    uintptr_t msize = 256;
    intptr_t *memory = calloc(msize, sizeof(intptr_t));
    assert(memory != NULL);
    intptr_t *MEND = memory + msize;
    intptr_t *LAST_WORD = MEND - 1;
    intptr_t MAGIC_NUMBER = 0xf201;
    int endism =
#ifdef WORDS_BIGENDIAN
        1
#else
        0
#endif
        ;

    bee_store(LAST_WORD, MAGIC_NUMBER);
    test(bee_load(LAST_WORD), MAGIC_NUMBER);
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcast-align"
    test(bee_load2((uint16_t *)((uint8_t *)LAST_WORD + (sizeof(intptr_t) - 2) * endism)), MAGIC_NUMBER);
#pragma GCC diagnostic pop
    test(bee_load1((uint8_t *)LAST_WORD + (sizeof(intptr_t) - 2) * endism + 1 * (1 - endism)), MAGIC_NUMBER >> BYTE_BIT);
    bee_store1((uint8_t *)LAST_WORD + (sizeof(intptr_t) - 1) * (1 - endism), MAGIC_NUMBER >> BYTE_BIT);
    test(bee_load(LAST_WORD), ((MAGIC_NUMBER >> BYTE_BIT) << (INTPTR_BIT - BYTE_BIT)) | MAGIC_NUMBER);

    printf("Memory tests ran OK\n");
    return 0;
}

// Test the logic operators. We only test the basic correctness of the
// operators here, assuming that if the logic works in one case, it will
// work in all (if the C compiler doesn't implement it correctly, we're in
// trouble anyway!).
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
    intptr_t BOTTOM_BYTE_SET = 0xffUL;
    intptr_t SECOND_BYTE_SET = LSHIFT(0xffUL, BYTE_BIT);
    intptr_t PENULTIMATE_BYTE_SET = LSHIFT(0xffUL, INTPTR_BIT - 2 * BYTE_BIT);
    intptr_t TOP_BYTE_SET = LSHIFT(-1, INTPTR_BIT - BYTE_BIT);

    test(bee_lshift(BOTTOM_BYTE_SET, BYTE_BIT), SECOND_BYTE_SET);
    test(bee_rshift(TOP_BYTE_SET, BYTE_BIT), PENULTIMATE_BYTE_SET);
    test(bee_or(SECOND_BYTE_SET, PENULTIMATE_BYTE_SET), SECOND_BYTE_SET | PENULTIMATE_BYTE_SET);
    test(bee_not(SECOND_BYTE_SET | PENULTIMATE_BYTE_SET), ~(SECOND_BYTE_SET | PENULTIMATE_BYTE_SET));
    test(bee_xor(1024, -1), -1025);
    test(bee_and(~(SECOND_BYTE_SET | PENULTIMATE_BYTE_SET), -1025), ~(SECOND_BYTE_SET | PENULTIMATE_BYTE_SET) & -1025);

    printf("Logic tests ran OK\n");
    return 0;
}

// Test the arithmetic functions. Since unsigned arithmetic overflow
// behaviour is guaranteed by the ISO C standard, we only test the basic
// correctness of the operators here, assuming that if the arithmetic works
// in one case, it will work in all.
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
    test(bee_negate(1), -1);
    test(bee_word_bytes(), sizeof(intptr_t));
    test(bee_add(-sizeof(intptr_t), -1), -sizeof(intptr_t) - 1);
    test(bee_add(sizeof(intptr_t), -sizeof(intptr_t) - 1), -1);
    test(bee_multiply(-1, sizeof(intptr_t)), -sizeof(intptr_t));
    test(bee_divide(-sizeof(intptr_t), sizeof(intptr_t) - 1), -1);
    test(bee_mod(-sizeof(intptr_t), sizeof(intptr_t) - 1), -1);
    test(bee_udivide(-1, -2), 1);
    test(bee_umod(-1, -2), 1);

    printf("Arithmetic tests ran OK\n");
    return 0;
}

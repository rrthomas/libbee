// Test the comparison operators. We only test simple cases here, assuming
// that the C compiler's comparison routines will work for other cases.
//
// (c) Reuben Thomas 1994-2022
//
// The package is distributed under the MIT/X11 License.
//
// THIS PROGRAM IS PROVIDED AS IS, WITH NO WARRANTY. USE IS AT THE USER’S
// RISK.

#include "tests.h"


intptr_t pairs1_left[] = { -4, 2, 1, 3 };
intptr_t pairs1_right[] = { 3, 2, 3, 1 };

intptr_t pairs2_left[] = { 1, 237 };
intptr_t pairs2_right[] = { -1, 237 };

intptr_t correct_lt[] = { 1, 0, 1, 0 };
intptr_t correct_eq[] = { 0, 1 };
intptr_t correct_ult[] = { 0, 0, 1, 0 };

static void comp_test(size_t pairs, intptr_t (*fn)(intptr_t, intptr_t),
                 intptr_t pairs_left[], intptr_t pairs_right[],
                 intptr_t correct[])
{
    for (size_t i = 0; i < pairs; i++) {
        intptr_t res = fn(pairs_left[i], pairs_right[i]);
        printf("Operands: %zd, %zd; Result: %zd; correct result: %zd\n",
               pairs_left[i], pairs_right[i],
               res, correct[i]);
        if (correct[i] != res) {
            printf("Error in comparison test %zu\n", i);
            exit(1);
        }
    }
}

int main(void)
{
    printf("bee_lt tests\n");
    comp_test(sizeof(pairs1_left) / sizeof(pairs1_left[0]),
              bee_lt,
              pairs1_left, pairs1_right, correct_lt);
    printf("bee_eq tests\n");
    comp_test(sizeof(pairs2_left) / sizeof(pairs2_left[0]),
              bee_eq,
              pairs2_left, pairs2_right, correct_eq);
    printf("bee_ult tests\n");
    comp_test(sizeof(pairs1_left) / sizeof(pairs1_left[0]),
              (intptr_t (*)(intptr_t, intptr_t))bee_ult,
              pairs1_left, pairs1_right, correct_ult);

    printf("Comparison tests ran OK\n");
    return 0;
}

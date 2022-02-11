// Header for library tests.
//
// (c) Reuben Thomas 1995-2022
//
// The package is distributed under the MIT/X11 License.
//
// THIS PROGRAM IS PROVIDED AS IS, WITH NO WARRANTY. USE IS AT THE USER’S
// RISK.

#include "config.h"

#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "libbee.h"
#include "private.h"


#define BYTE_BIT 8

void test(intptr_t res, intptr_t correct);
void test(intptr_t res, intptr_t correct)
{
    printf("Result: %zd; correct result: %zd\n", res, correct);
    if (res != correct) {
        printf("Error in arithmetic tests\n");
        exit(1);
    }
}

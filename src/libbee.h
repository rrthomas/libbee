// libbee API header file.
//
// (c) Reuben Thomas 1994-2022
//
// The package is distributed under the MIT/X11 License.
//
// THIS PROGRAM IS PROVIDED AS IS, WITH NO WARRANTY. USE IS AT THE USER’S
// RISK.

#ifndef LIBBEE_LIBBEE
#define LIBBEE_LIBBEE


#include <stdint.h>


intptr_t bee_not(intptr_t a);
intptr_t bee_and(intptr_t a, intptr_t b);
intptr_t bee_or(intptr_t a, intptr_t b);
intptr_t bee_xor(intptr_t a, intptr_t b);
intptr_t bee_lshift(intptr_t shift, intptr_t value);
intptr_t bee_rshift(intptr_t shift, intptr_t value);
intptr_t bee_arshift(intptr_t shift, intptr_t value);
intptr_t bee_load(intptr_t *addr);
void bee_store(intptr_t *addr, intptr_t value);
intptr_t bee_load1(uint8_t *addr);
void bee_store1(uint8_t *addr, uint8_t value);
intptr_t bee_load2(uint16_t *addr);
void bee_store2(uint16_t *addr, uint16_t value);
intptr_t bee_load4(uint32_t *addr);
void bee_store4(uint32_t *addr, uint32_t value);
intptr_t bee_negate(intptr_t a);
intptr_t bee_add(intptr_t a, intptr_t b);
intptr_t bee_multiply(intptr_t a, intptr_t b);
intptr_t bee_divide(intptr_t dividend, intptr_t divisor);
intptr_t bee_mod(intptr_t dividend, intptr_t divisor);
uintptr_t bee_udivide(uintptr_t dividend, uintptr_t divisor);
uintptr_t bee_umod(uintptr_t dividend, uintptr_t divisor);
intptr_t bee_eq(intptr_t a, intptr_t b);
intptr_t bee_lt(intptr_t a, intptr_t b);
intptr_t bee_ult(uintptr_t a, uintptr_t b);
intptr_t bee_word_bytes(void);

#endif

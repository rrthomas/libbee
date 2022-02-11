// Library of basic arithmetic and logic routines that are normally provided
// only in the language.
//
// (c) Reuben Thomas 1994-2022
//
// The package is distributed under the MIT/X11 License.
//
// THIS PROGRAM IS PROVIDED AS IS, WITH NO WARRANTY. USE IS AT THE USER’S
// RISK.

#include "config.h"

#include "libbee.h"
#include "private.h"


// Library functions
_GL_ATTRIBUTE_CONST intptr_t bee_not(intptr_t a)
{
    return ~a;
}

_GL_ATTRIBUTE_CONST intptr_t bee_and(intptr_t a, intptr_t b)
{
    return a & b;
}

_GL_ATTRIBUTE_CONST intptr_t bee_or(intptr_t a, intptr_t b)
{
    return a | b;
}

_GL_ATTRIBUTE_CONST intptr_t bee_xor(intptr_t a, intptr_t b)
{
    return a ^ b;
}

_GL_ATTRIBUTE_CONST intptr_t bee_lshift(intptr_t value, intptr_t shift)
{
    return shift < (intptr_t)INTPTR_BIT ? LSHIFT(value, shift) : 0;
}

_GL_ATTRIBUTE_CONST intptr_t bee_rshift(intptr_t value, intptr_t shift)
{
    return shift < (intptr_t)INTPTR_BIT ? (intptr_t)((uintptr_t)value >> shift) : 0;
}

_GL_ATTRIBUTE_CONST intptr_t bee_arshift(intptr_t value, intptr_t shift)
{
    return ARSHIFT(value, shift);
}

_GL_ATTRIBUTE_PURE intptr_t bee_load(intptr_t *addr)
{
    return *addr;
}

void bee_store(intptr_t *addr, intptr_t value)
{
    *addr = value;
}

_GL_ATTRIBUTE_PURE intptr_t bee_load1(uint8_t *addr)
{
    return (intptr_t)*addr;
}

void bee_store1(uint8_t *addr, uint8_t value)
{
    *addr = (uint8_t)value;
}

_GL_ATTRIBUTE_PURE intptr_t bee_load2(uint16_t *addr)
{
    return (intptr_t)*addr;
}

void bee_store2(uint16_t *addr, uint16_t value)
{
    *addr = (uint16_t)value;
}

_GL_ATTRIBUTE_PURE intptr_t bee_load4(uint32_t *addr)
{
    return (intptr_t)*addr;
}

void bee_store4(uint32_t *addr, uint32_t value)
{
    *addr = (uint32_t)value;
}

_GL_ATTRIBUTE_CONST intptr_t bee_negate(intptr_t a)
{
    return (intptr_t)(uintptr_t)-a;
}

_GL_ATTRIBUTE_CONST intptr_t bee_add(intptr_t a, intptr_t b)
{
    return (intptr_t)((uintptr_t)a + (uintptr_t)b);
}

_GL_ATTRIBUTE_CONST intptr_t bee_multiply(intptr_t a, intptr_t b)
{
    return (intptr_t)((uintptr_t)a * (uintptr_t)b);
}

// Division macros
#define DIV_CATCH_ZERO(a, b) ((b) == 0 ? 0 : (a) / (b))
#define MOD_CATCH_ZERO(a, b) ((b) == 0 ? (a) : (a) % (b))

_GL_ATTRIBUTE_CONST intptr_t bee_divide(intptr_t dividend, intptr_t divisor)
{
    if (dividend == INTPTR_MIN && divisor == -1)
        return INTPTR_MIN;
    else
        return DIV_CATCH_ZERO(dividend, divisor);
}

_GL_ATTRIBUTE_CONST intptr_t bee_mod(intptr_t dividend, intptr_t divisor)
{
    if (dividend == INTPTR_MIN && divisor == -1)
        return 0;
    else
        return MOD_CATCH_ZERO(dividend, divisor);
}

_GL_ATTRIBUTE_CONST uintptr_t bee_udivide(uintptr_t dividend, uintptr_t divisor)
{
    return DIV_CATCH_ZERO(dividend, divisor);
}

_GL_ATTRIBUTE_CONST uintptr_t bee_umod(uintptr_t dividend, uintptr_t divisor)
{
    return MOD_CATCH_ZERO(dividend, divisor);
}

_GL_ATTRIBUTE_CONST intptr_t bee_eq(intptr_t a, intptr_t b)
{
    return a == b;
}

_GL_ATTRIBUTE_CONST intptr_t bee_lt(intptr_t a, intptr_t b)
{
    return a < b;
}

_GL_ATTRIBUTE_CONST intptr_t bee_ult(uintptr_t a, uintptr_t b)
{
    return a < b;
}

_GL_ATTRIBUTE_CONST intptr_t bee_word_bytes(void) {
    return sizeof(intptr_t);
}

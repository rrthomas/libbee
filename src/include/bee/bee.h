// Public data structures and interface calls specified in the VM definition.
// This is the header file to include in programs using an embedded VM.
//
// (c) Reuben Thomas 1994-2020
//
// The package is distributed under the GNU Public License version 3, or,
// at your option, any later version.
//
// THIS PROGRAM IS PROVIDED AS IS, WITH NO WARRANTY. USE IS AT THE USER’S
// RISK.

#ifndef BEE_BEE
#define BEE_BEE


#include <stdio.h>      // for the FILE type
#include <stdint.h>
#include <limits.h>


// Basic types
typedef int32_t bee_WORD;
typedef uint32_t bee_UWORD;
#define bee_WORD_BYTES 4    // the number of bytes in a word
#define bee_WORD_BIT (sizeof(bee_WORD_BYTES) * CHAR_BIT)
#define bee_WORD_MIN ((bee_WORD)(1UL << (bee_WORD_BIT - 1)))
#define bee_WORD_MAX (UINT32_MAX)
#define bee_WORD_MASK bee_WORD_MAX

// VM registers
extern bee_WORD *bee_PC, *bee_M0, *bee_S0, *bee_D0;
extern bee_UWORD bee_MSIZE, bee_SSIZE, bee_DSIZE;
extern bee_UWORD bee_DP, bee_SP, bee_HANDLER_SP;

// Error codes
enum {
    BEE_ERROR_OK = 0,
    BEE_ERROR_INVALID_OPCODE = -1,
    BEE_ERROR_STACK_UNDERFLOW = -2,
    BEE_ERROR_STACK_OVERFLOW = -3,
    BEE_ERROR_INVALID_LOAD = -4,
    BEE_ERROR_INVALID_STORE = -5,
    BEE_ERROR_UNALIGNED_ADDRESS = -6,
    BEE_ERROR_INVALID_LIBRARY = -16,
    BEE_ERROR_INVALID_FUNCTION = -17,
    BEE_ERROR_BREAK = -256,
};

// Stack access
int bee_pop_stack(bee_WORD *s0, bee_UWORD ssize, bee_UWORD *sp, bee_WORD *val_ptr);
int bee_push_stack(bee_WORD *s0, bee_UWORD ssize, bee_UWORD *sp, bee_WORD val);

// Default stacks size in words
#define bee_DEFAULT_STACK_SIZE   4096

// Miscellaneous routines
bee_WORD bee_run(void);
int bee_load_object(FILE *file, bee_WORD *ptr);
int bee_init(bee_WORD *c_array, bee_WORD memory_size, bee_WORD stack_size, bee_WORD return_stack_size);
int bee_init_defaults(bee_WORD *c_array, bee_WORD memory_size);
void bee_register_args(int argc, const char *argv[]);


#endif

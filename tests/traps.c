// Test traps. Also uses previously-tested instructions.
// FIXME: test file routines.
//
// (c) Reuben Thomas 1994-2020
//
// The package is distributed under the GNU Public License version 3, or,
// at your option, any later version.
//
// THIS PROGRAM IS PROVIDED AS IS, WITH NO WARRANTY. USE IS AT THE USER’S
// RISK.

#include "traps.h"

#include "tests.h"


int main(void)
{
    // Data for ARGC/ARGV tests
    int argc = 3;
    const char *argv[] = {"foo", "bard", "basilisk"};

    init_defaults((WORD *)malloc(4096), 1024);
    register_args(argc, argv);

    ass_goto(M0);

    // ARGC test
    pushi(TRAP_LIBC_ARGC); ass_trap(TRAP_LIBC);

    // ARGV test
    pushi(TRAP_LIBC_ARGV); ass_trap(TRAP_LIBC);
    ass(BEE_INSN_WORD_BYTES); ass(BEE_INSN_ADD); ass(BEE_INSN_LOAD);
    pushi(TRAP_LIBC_STRLEN); ass_trap(TRAP_LIBC);
    WORD *end = label();

    assert(single_step() == ERROR_BREAK);
    assert(single_step() == ERROR_BREAK);
    printf("argc is %"PRId32", and should be %d\n", *stack_position(S0, SP, 0), argc);
    assert(SP > 0);
    if (S0[--SP] != argc) {
        printf("Error in traps tests: PC = %p\n", PC);
        exit(1);
    }

    while (PC < end)
        assert(single_step() == ERROR_BREAK);
    printf("arg 1's length is %"PRId32", and should be %zu\n", *stack_position(S0, SP, 0), strlen(argv[1]));
    assert(SP > 0);
    if ((UWORD)S0[--SP] != strlen(argv[1])) {
        printf("Error in traps tests: PC = %p\n", PC);
        exit(1);
    }

    printf("Traps tests ran OK\n");
    return 0;
}

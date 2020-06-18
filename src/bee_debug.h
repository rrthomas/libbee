// VM debugging functions
// These are undocumented and subject to change.
//
// (c) Reuben Thomas 1994-2018
//
// The package is distributed under the GNU Public License version 3, or,
// at your option, any later version.
//
// THIS PROGRAM IS PROVIDED AS IS, WITH NO WARRANTY. USE IS AT THE USER’S
// RISK.

#ifndef bee_BEE_DEBUG
#define bee_BEE_DEBUG


int bee_byte_size(bee_CELL v); // return number of significant bytes in a bee_CELL quantity

void bee_ass(bee_BYTE instr);	// assemble an instruction
void bee_lit(bee_CELL literal);	// assemble a cell literal
bool bee_ilit(bee_CELL literal);    // assemble an immediate literal, returning false if it doesn't fit
void bee_plit(void (*literal)(void));  // assemble a machine-dependent function pointer literal,
                                   // including the relevant LITERAL instructions
void bee_start_ass(bee_UCELL addr);	// start assembly, initialising variables
bee_UCELL bee_ass_current(void);	// return address of bee_CELL currently being assembled to
const char *bee_disass(bee_BYTE opcode);  // disassemble an instruction
bee_BYTE bee_toass(const char *token);    // convert a instruction to its opcode

char *bee_val_data_stack(void); // return the current data stack as a string
void bee_show_data_stack(void); // show the current contents of the data stack
void bee_show_return_stack(void);	// show the current contents of the return stack


#endif

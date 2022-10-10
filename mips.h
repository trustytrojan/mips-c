#ifndef MIPS
#define MIPS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "source-file.h"
#include "instruction.h"
#include "utils.h"


/* opcodes.c */

int get_opcode(const char* s);


/* registers.c */

int get_register_number(const char* s);

#endif
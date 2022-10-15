#ifndef MIPS_INSTRUCTION
#define MIPS_INSTRUCTION

#include <stdbool.h>
#include <stdio.h>

#define OP_LENGTH 8
#define ARG_LENGTH 32

typedef struct {
  char op[OP_LENGTH];
  char arg1[ARG_LENGTH];
  char arg2[ARG_LENGTH];
  char arg3[ARG_LENGTH];
  int _op;
  int _arg1;
  int _arg2;
  int _arg3;
} MIPS_Instruction;

bool validate_instruction(MIPS_Instruction* instr);

MIPS_Instruction* read_instruction_from(FILE* stream);

void print_instruction(MIPS_Instruction* instr);

MIPS_Instruction* new_MIPS_Instruction();

void free_MIPS_Instruction(MIPS_Instruction* instr);

#endif

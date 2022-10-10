#ifndef MIPS_INSTRUCTION
#define MIPS_INSTRUCTION

#include <stdio.h>
#include <stdbool.h>

#define OP_LENGTH 8
#define ARG_LENGTH 32

typedef struct {
  char* op;
  int _op;
  char* arg1;
  int _arg1;
  char* arg2;
  int _arg2;
  char* arg3;
  int _arg3;
} MIPS_Instruction;

bool validate_instruction(MIPS_Instruction* instr);

MIPS_Instruction* read_instruction_from(FILE* stream);

void print_instruction(MIPS_Instruction* instr);

MIPS_Instruction* new_MIPS_Instruction();

void free_MIPS_Instruction(MIPS_Instruction* instr);

#endif

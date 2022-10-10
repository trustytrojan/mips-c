#ifndef MIPS_C
#define MIPS_C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

const int OP_LENGTH = 8;
const int ARG_LENGTH = 32;

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

typedef union {
  char* ascii_z;
  int word;
  float _float;
  double _double;
} MIPS_Static_Data_Value;

typedef struct {
  char* name;
  char* type;
  MIPS_Static_Data_Value value;
} MIPS_Static_Data;

typedef struct {
  char* name;
  int index;
} MIPS_Label;

typedef struct {
  MIPS_Static_Data* data_labels;
  MIPS_Label* labels;
  MIPS_Instruction* instructions;
} MIPS_Program;


MIPS_Program* parse_mips_file(const char* filename);

MIPS_Static_Data* parse_static_data(FILE* file, char* line);


// utils.c //

void remove_unnecessary_chars(char* s);


// instruction.c //

void run_instruction(int R[32], MIPS_Instruction* instr);

bool validate_instruction(MIPS_Instruction* instr);

MIPS_Instruction* read_instruction_from(FILE* stream);

void print_instruction(MIPS_Instruction* instr);

MIPS_Instruction* new_MIPS_Instruction();

void free_MIPS_Instruction(MIPS_Instruction* instr);

#endif
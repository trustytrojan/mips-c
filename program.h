#ifndef MIPS_PROGRAM
#define MIPS_PROGRAM

#include "label.h"
#include "instruction.h"

typedef union {
  char* ascii_z;
  int word;
  float _float;
  double _double;
} MIPS_Static_Data_Value;

typedef enum { ascii_z, word, _float, _double } MIPS_Static_Data_Value_Type;

typedef struct MIPS_Static_Data {
  char* name;
  MIPS_Static_Data_Value_Type type;
  MIPS_Static_Data_Value value;
} MIPS_Static_Data;

typedef struct {
  MIPS_Static_Data* data_labels;
  int data_label_count;
  MIPS_Label* labels;
  int label_count;
  MIPS_Instruction* instructions;
  int instruction_count;
} MIPS_Program;

MIPS_Program* new_MIPS_Program(const char* filename);

void free_MIPS_Program(MIPS_Program* program);

#endif

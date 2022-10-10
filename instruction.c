#include "mips-c.h"

bool validate_instruction(MIPS_Instruction* instr) {
  bool is_valid = true;
  if(strlen(instr->op) > OP_LENGTH) {
    fprintf(stderr, "validate_instruction: operation is too long!\n");
    is_valid = false;
  }
  if(strlen(instr->arg1) > ARG_LENGTH) {
    fprintf(stderr, "validate_instruction: first argument is too long!\n");
    is_valid = false;
  }
  if(strlen(instr->arg2) > ARG_LENGTH) {
    fprintf(stderr, "validate_instruction: second argument is too long!\n");
    is_valid = false;
  }
  if(strlen(instr->arg3) > ARG_LENGTH) {
    fprintf(stderr, "validate_instruction: third argument is too long!\n");
    is_valid = false;
  }
  return is_valid;
}

MIPS_Instruction* read_instruction_from(FILE* stream) {
  MIPS_Instruction* instr = new_MIPS_Instruction();
  fscanf(stream, "%s %s %s %s", instr->op, instr->arg1, instr->arg2, instr->arg3);
  remove_unnecessary_chars(instr->arg1);
  remove_unnecessary_chars(instr->arg2);
  remove_unnecessary_chars(instr->arg3);
  if(!validate_instruction(instr)) {
    fprintf(stderr, "Syntax error with the following instruction:\n");
    print_instruction(instr);
    fprintf(stderr, "Please see the above errors to fix your syntax.\n");
  }
  instr->_op = get_operation_number(instr->op);
  instr->_arg1 = get_register_number(instr->arg1);
  instr->_arg2 = get_register_number(instr->arg2);
  instr->_arg3 = get_register_number(instr->arg3);
  return instr;
}

void print_instruction(MIPS_Instruction* instr) {
  printf("\top: \"%s\" (%d)\n\targ1: \"%s\" (%d)\n\targ2: \"%s\" (%d)\n\targ3: \"%s\" (%d)\n",
    instr->op, instr->_op,
    instr->arg1, instr->_arg1,
    instr->arg2, instr->_arg2,
    instr->arg3, instr->_arg3
  );
}

MIPS_Instruction* new_MIPS_Instruction() {
  MIPS_Instruction* instr = calloc(1, sizeof(MIPS_Instruction));
  instr->op = malloc(OP_LENGTH);
  instr->arg1 = malloc(ARG_LENGTH);
  instr->arg2 = malloc(ARG_LENGTH);
  instr->arg3 = malloc(ARG_LENGTH);
  instr->op[OP_LENGTH-1] = '\0';
  instr->arg1[ARG_LENGTH-1] = '\0';
  instr->arg2[ARG_LENGTH-1] = '\0';
  instr->arg3[ARG_LENGTH-1] = '\0';
  return instr;
}

void free_MIPS_Instruction(MIPS_Instruction* instr) {
  
}

#include "mips.h"

void run_instruction(int R[32], MIPS_Instruction* instr) {
  switch(instr->_op) {
    case 0: // add
    case 1: // addi
    case 2: // addiu
    case 3: // addu
      R[instr->_arg1] = R[instr->_arg2] + R[instr->_arg3];
      break;
    case 4: // addiu
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
  }
}

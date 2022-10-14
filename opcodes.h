#ifndef MIPS_OPCODES
#define MIPS_OPCODES

#include "mips.h"

const char* opcodes[] = {
  "add", "addi", "addiu", "addu",
  "mult", "multu",
  "mflo", "mfhi"
  "li", "move",
  "syscall"
};

const int num_opcodes = sizeof(opcodes) / sizeof(char*);

int get_opcode(const char* s) {
  for(int i = 0; i < num_opcodes; ++i) {
    if(strcmp(s, opcodes[i]) == 0)
      return i;
  }
  return -1;
}

#endif
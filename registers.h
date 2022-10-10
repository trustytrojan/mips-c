#ifndef MIPS_REGISTERS
#define MIPS_REGISTERS

const char* registers[] = {
  "zero",
  "at",
  "v0", "v1",
  "a0", "a1", "a2", "a3",
  "t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7",
  "s0", "s1", "s2", "s3", "s4", "s5", "s6", "s7",
  "t8", "t9",
  "k0", "k1",
  "gp",
  "sp",
  "fp",
  "ra"
};

int get_register_number(const char* s) {
  for(int i = 0; i < 32; ++i)
    if(strcmp(s, registers[i]) == 0)
      return i;
  return -1;
}

#endif

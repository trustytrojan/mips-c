typedef struct {
  int
  zero,
  at,
  v0, v1,
  a0, a1, a2, a3,
  t0, t1, t2, t3, t4, t5, t6, t7,
  s0, s1, s2, s3, s4, s5, s6, s7,
  t8, t9,
  k0, k1,
  gp,
  sp,
  fp,
  ra
} MIPS_User_Registers;

typedef struct {
  int pc, hi, lo;
} MIPS_Internal_Registers;

typedef struct {
  void* M;
  MIPS_Internal_Registers _;
  MIPS_User_Registers R;
} MIPS_Processor;

MIPS_Processor* new_MIPS_Processor() {
  MIPS_Processor* p = calloc(1, sizeof(MIPS_Processor));
  p->M = malloc(0x1000);
  return p;
}
#include "mips-c.h"

int main(int argc, char* argv[]) {
  if(argc < 2) {
    fprintf(stderr, "Usage: %s <file>\n");
    return 1;
  }

  MIPS_Program* program = parse_mips_file(argv[2]);
  MIPS_Program_print(program);

}

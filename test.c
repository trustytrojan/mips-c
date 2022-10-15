#include "mips.h"

int main() {
  MIPS_Source_File* src_file = new_MIPS_Source_File("test.s");
  print_MIPS_Source_File(src_file);
  free_MIPS_Source_File(src_file);
}

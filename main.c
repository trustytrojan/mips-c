#include "mips.h"

int main(int argc, char* argv[]) {
  if(argc < 2) {
    fprintf(stderr, "Usage: %s <file>\n", argv[0]);
    return 1;
  }

  char* filename = argv[1];

  MIPS_Source_File* src_file = new_MIPS_Source_File(filename);

  for(int i = 0; i < src_file->line_count; ++i)
    printf("%d: \"%s\"\n", i+1, src_file->lines[i]);
  
  MIPS_Program* program = new_MIPS_Program(src_file);

  

  free_MIPS_Source_File(src_file);

  return 0;

  // MIPS_Program* program = parse_mips_file(filename);
  // MIPS_Program_print(program);
}

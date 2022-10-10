#include "program.h"

void run_mips_program_from_file(const char* filename) {
  
}

MIPS_Program* new_MIPS_Program(MIPS_Source_File* src_file) {
  const int line_count = src_file->line_count;
  char** lines = src_file->lines;

  bool in_data_section = false;
  int data_label_count = 0;
  int label_count = 0;

  // label mapping loop
  for(int i = 0; i < line_count; ++i) {
    if(strcmp(lines[i], ".data") == 0) {
      int j;
      for(j = i; strcmp(lines[j], ".text") == 0 && j < line_count; ++j);
      if(j == line_count-1) {
        fprintf(stderr, "No .text section found after .data section! Aborting.\n");

      }
      in_data_section = true;
    }
    // else if(strcmp(lines[i], ".text") == 0)
    //   in_data_section = false;
    
    if(in_data_section)
      ++data_label_count;
    else
      ++label_count;
  }

  free_MIPS_Source_File(src_file);
}

void free_MIPS_Program(MIPS_Program* program) {

}

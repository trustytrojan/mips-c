#include "program.h"

MIPS_Program* new_MIPS_Program(MIPS_Source_File* src_file) {
  const int line_count = src_file->line_count;
  char** lines = src_file->lines;

  bool in_data_section = false;
  int data_label_count = 0;
  int label_count = 0;

  // label counting loop
  for(int i = 0; i < line_count; ++i) {
    char* line = lines[i];
    const int len = strlen(line);

    if(strcmp(line, ".data") == 0) {
      int j;
      for(j = i; strcmp(strtok(lines[j], " "), ".text") != 0 && j < line_count; ++j);
      if(j == line_count-1) {
        fprintf(stderr, "new_MIPS_Program: no .text section found after .data section! returning NULL.\n");
        return NULL;
      }
      in_data_section = true;
      continue;
    } else if(strcmp(line, ".text") == 0) {
      in_data_section = false;
      continue;
    }
    
    if(line[len-1] == ':') {
      if(in_data_section)
        ++data_label_count;
      else
        ++label_count;
    }
  }

  MIPS_Label* labels = malloc(label_count*sizeof(MIPS_Label));
  MIPS_Static_Data* data_labels = malloc(data_label_count*sizeof(MIPS_Static_Data));
  /* label mapping loop */ {
    int li = 0;
    int dli = 0;
    for(int i = 0; i < line_count; ++i) {
      char* line = lines[i];
      const int len = strlen(line);

      if(strcmp(line, ".data") == 0) {
        in_data_section = true;
        continue;
      } else if(strcmp(line, ".text") == 0) {
        in_data_section = false;
        continue;
      }

      if(line[len-1] == ':') {
        if(in_data_section) {
          
        } else {

        }
      }
    }
  }

  free_MIPS_Source_File(src_file);
}

void free_MIPS_Program(MIPS_Program* program) {

}

#include "program.h"

// this will free src_file
MIPS_Program* new_MIPS_Program(const char* filename) {
  MIPS_Source_File* src_file = new_MIPS_Source_File(filename);
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
    
    char* _l = strtok(line, " ");
    const int _len = strlen(_l);
    if(_l[_len-1] == ':') {
      if(in_data_section)
        ++data_label_count;
      else
        ++label_count;
    }
  }

  printf("label_count: %d\n", label_count);
  printf("data_label_count: %d\n", data_label_count);

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

      char* _line = strtok(line, " ");
      const int _len = strlen(_line);
      if(_line[_len-1] == ':')
        if(in_data_section) {
          data_labels.
          ++dli;
        } else {
          labels[li].line_no = i;
          printf("label before cleaning: \"%s\"\n", _line);
          remove_unnecessary_chars(_line);
          printf("label after cleaning: \"%s\"\n", _line);
          labels[li].name = malloc(_len);
          strcpy(labels[li].name, _line);
          ++li;
        }
    }
  }

  free_MIPS_Source_File(src_file);
}

void free_MIPS_Program(MIPS_Program* program) {
  free(program->labels);
  free(program->data_labels);
  free(program->instructions);
  free(program);
}

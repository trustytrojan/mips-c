#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "source-file.h"

MIPS_Source_File* new_MIPS_Source_File(const char* filename) {
  int line_count = 1;
  FILE* file = fopen(filename, "r");
  for(char c = fgetc(file); c != EOF; c = fgetc(file))
    if(c == '\n') ++line_count;
  char** const lines = malloc(line_count*sizeof(char*));
  freopen(filename, "r", file);
  int label_count = 0;
  int data_label_count = 0;
  char line[30];
  for(int i = 0; i < line_count; ++i) {
    fgets(line, 30, file);
    trim_whitespace(line);
    int len = strlen(line);
    if(len == 0) continue;
    lines[i] = malloc(len);
    strcpy(lines[i], line);
  }
  fclose(file);
  MIPS_Source_File* src_file = malloc(sizeof(MIPS_Source_File));
  src_file->line_count = line_count;
  src_file->lines = lines;
  return src_file;
}

void print_MIPS_Source_File(MIPS_Source_File* src_file) {
  for(int i = 0; i < src_file->line_count; ++i)
    printf("%d:\t\"%s\"\n", i+1, src_file->lines[i]);
}

void free_MIPS_Source_File(MIPS_Source_File* src_file) {
  for(int i = 0; i < src_file->line_count; ++i) {
    free(src_file->lines[i]);
  }
  free(src_file->lines);
  free(src_file);
}

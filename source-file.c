#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../c-vector/vector.h"
#include "utils.h"
#include "source-file.h"

#define LINE_LENGTH 30

MIPS_Source_File* new_MIPS_Source_File(const char* filename) {
  vector* labels = vector_new();
  FILE* file = fopen(filename, "r");
  char line[LINE_LENGTH];
  for(int i = 1; !feof(file); ++i) {
    fgets(line, LINE_LENGTH, file);
    trim_whitespace(line);
    const int len = strlen(line);
    if(len == 0) continue;
    
  }
  fclose(file);
}

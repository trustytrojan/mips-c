#ifndef MIPS_SOURCE_FILE
#define MIPS_SOURCE_FILE

#include <stdio.h>
#include <string.h>

#include "utils.h"

typedef struct {
  int line_count;
  char** lines;
} MIPS_Source_File;

MIPS_Source_File* new_MIPS_Source_File(const char* filename);

void free_MIPS_Source_File(MIPS_Source_File* src_file);

#endif

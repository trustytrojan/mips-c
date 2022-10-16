#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.c"
#include "processor.c"

#define LINE_LENGTH 30

int lw(void* M, int offset) {
  return *(int*)(M+offset);
}

void sw(void* M, int offset, int element) {
  *(int*)(M+offset) = element;
}

// will segfault if s does not have enough space
void strreplace(char* s, const char* replace_this, const char* with_this) {
  const int rt_len = strlen(replace_this);
  const int wt_len = strlen(with_this);
  const int diff = wt_len - rt_len;
  char* _r;
  while(_r = strstr(s, replace_this)) {
    char* to_be_moved = _r + rt_len;
    strcpy(to_be_moved+diff, to_be_moved);
    strncpy(_r, with_this, wt_len);
  }
}

void replace_escapes_with_correct_char(char* s) {
  strreplace(s, "\\n", "\n");
  strreplace(s, "\\t", "\t");
}

void read_static_data(MIPS_Processor* p, void* M, FILE* file, int* _i, char line[LINE_LENGTH]) {
  int i = *_i;
  for(; strcmp(line, ".text") != 0 && !feof(file); ++i) {
    fgets(line, LINE_LENGTH, file);
    const int len = strlen(trim_whitespace(line));
    if(len == 0) continue;
    char* label = remove_unnecessary_chars(strtok(line, " "));
    char* type = remove_unnecessary_chars(strtok(NULL, " "));
    char* value = remove_unnecessary_chars(strtok(NULL, " "));
    if(!strcmp(type, "ascii")) {
      replace_escapes_with_correct_char(value);
      strcpy(M+p->R.gp, value);
      p->R.gp += strlen(value);
      ((char*)M)[p->R.gp] = '\0';
    } else if(!strcmp(type, "asciiz")) {
      replace_escapes_with_correct_char(value);
      strcpy(M+p->R.gp)
    } else if(!strcmp(type, "word")) {

    } else {
      fprintf(stderr, "Syntax error: not a static data entry. Aborting.\n\tLine %d: \"%s\"\n", i+1, line);
      free(M);
      exit(1);
    }
  }
  *_i = i;
}

int main() {
  MIPS_Processor* p = new_MIPS_Processor();
  void* M = calloc(0x10000, 1);
  FILE* file = fopen("test.s", "r");
  char line[LINE_LENGTH];
  for(int i = 1; !feof(file); ++i) {
    fgets(line, LINE_LENGTH, file);
    trim_whitespace(line);
    const int len = strlen(line);
    if(len == 0) continue;
    if(strcmp(line, ".data") == 0) {
      read_static_data(p, M, file, &i, line);
    }
    if(strcmp(line, ".text") == 0) {

    }
  }
  fclose(file);
  free(M);
}

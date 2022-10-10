#include "mips-c.h"

void remove_unnecessary_chars(char* s) {
  const int len = strlen(s);
  char _s[len];
  int _i = 0;
  for(int i = 0; i < len; ++i)
    if(s[i] != ',' && s[i] != '$')
      _s[_i++] = s[i];
  _s[_i+1] = '\0';
  strcpy(s, _s);
}

MIPS_Program* parse_mips_file(const char* filename) {
  MIPS_Program* program = malloc(sizeof(MIPS_Program));
  FILE* file = fopen(filename, "r");
  int code_labels = 0;
  int data_labels = 0;
  // bool in_data_section = false;
  char line[512];

  // line parsing
  for(int line_no = 1; !feof(file); ++line_no) {
    fgets(line, 512, file);
    char* ptr = line;

    /* ignore leading whitespace */ {
      while(*ptr++ == ' ');
    }

    /* ignore comments */ {
      char* comment = strchr(line, '#');
      if(comment) *comment = '\0';
    }

    /* check if line ends with a colon */ {
      const int len = strlen(line);
      if(line[len-1] == ':') {
        
      }
    }

    // if(strcmp(line, ".data") == 0)
    //   in_data_section = true;
    // 

    // if(strchr(line, ':')) {
    //   if(in_data_section)
    //     ++data_labels;
    //   else
    //     ++code_labels;
    // }
  }

  fclose(file);
}

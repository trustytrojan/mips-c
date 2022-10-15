#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "utils.h"

void remove_unnecessary_chars(char* s) {
  const int len = strlen(s);
  char _s[len];
  int _i = 0;
  for(int i = 0; i < len; ++i)
    switch(s[i]) {
      case ',':
      case '$':
      case ':':
        break;
      default:
        _s[_i++] = s[i];
    }
  _s[_i+1] = '\0';
  strcpy(s, _s);
}

void trim_whitespace(char* s) {
  int len = strlen(s);
  bool leading_whitespace = isspace(s[0]);
  bool trailing_whitespace = isspace(s[len-1]);
  if(leading_whitespace) {
    int i;
    for(i = 0; isspace(s[i]) && i < len; ++i);
    const int new_len = len-i;
    strcpy(s, s+i);
    s[new_len] = '\0';
  }
  len = strlen(s);
  if(trailing_whitespace) {
    int i;
    for(i = len-1; isspace(s[i]) && i >= 0; --i);
    s[i+1] = '\0';
  }
}

int num_tokens(const char* s, const char* delim) {
  int n_tokens = 0;
  char _s[strlen(s)];
  strcpy(_s, s);
  trim_whitespace(_s);
  if(strtok(_s, delim)) ++n_tokens;
  else return 0;
  for(; strtok(NULL, delim); ++n_tokens);
  return n_tokens;
}

// returns NULL only if strtok returns NULL on first call
void strsplit(char* s, const char* delim, char** tokens) {
  int n_tokens = num_tokens(s, delim);
  if(n_tokens == 0) return;
  tokens[0] = strtok(s, delim);
  for(int i = 1; i < n_tokens; ++i)
    tokens[i] = strtok(NULL, delim);
}

#include "utils.h"

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

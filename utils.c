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

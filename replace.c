#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void strreplace(char* s, const char* replace_this, const char* with_this) {
  const int len = strlen(s);
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

int main() {
  char s[] = "hellothere";
  strreplace(s, "oth", "ab");
  printf("%s", s);
}

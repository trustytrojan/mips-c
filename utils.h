#ifndef MIPS_UTILS
#define MIPS_UTILS

char* remove_unnecessary_chars(char* s);

char* trim_whitespace(char* s);

int num_tokens(const char* s, const char* delim);

void strsplit(char* s, const char* delim, char** tokens);

#endif

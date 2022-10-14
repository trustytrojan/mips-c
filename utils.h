#ifndef MIPS_UTILS
#define MIPS_UTILS

#include "mips.h"

void remove_unnecessary_chars(char* s);

void trim_whitespace(char* s);

int num_tokens(const char* s, const char* delim);

void strsplit(char* s, const char* delim, char** tokens);

#endif

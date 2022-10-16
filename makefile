CC = gcc
CFLAGS = -Wall -Wextra # -Werror
INCLUDE = -I../c-vector
LINK = -L../c-vector -lvector

CC_AND_FLAGS = $(CC) $(CFLAGS) $(LINK)

default:
	$(CC) $(CFLAGS) $(INCLUDE) $(LINK) *.c

no_warn:
	$(CC) $(INCLUDE $(LINK)

run:
	default
	./a.out

debug:
	$(CC) $(CFLAGS) $(LINK) -g *.c
	valgrind ./a.out

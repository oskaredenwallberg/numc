CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -g -O0 -MMD -MP
CPPFLAGS = -Iinclude

.DEFAULT_GOAL := all

SRC = $(wildcard src/*.c src/tensor_ops/*.c)
OBJ = $(SRC:.c=.o)
DEP = $(OBJ:.o=.d)
EXEC = numc

$(EXEC): $(OBJ)  # target: prerequisites
	$(CC) $^ -o $@

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

-include $(DEP)  # header dependencies

all: $(EXEC)

run: $(EXEC)
	./$(EXEC)

clean:
	rm -f $(OBJ) $(DEP) $(EXEC)

.PHONY: all run clean



# Notes to self:
# `%` 			in pattern rules matches any set of characters
# `*` 			matches all files in a given directory
# `**` 			in wildcard function matches files/directories recursively
# `-Wall` 		(Warnings All) enables most compiler warnings
# `-Wextra` 	(Warnings Extra) enables additional compiler warnings for other common oversights 
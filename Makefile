CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -g -O0 -MMD -MP
CPPFLAGS = -Iinclude

.DEFAULT_GOAL := all

SRC = $(wildcard src/*.c src/tensor_ops/*.c)
OBJ = $(SRC:.c=.o)
DEP = $(OBJ:.o=.d)
EXEC = numc

TEST_SRC = test/test_scalar_math.c
TEST_OBJ = $(TEST_SRC:.c=.o)
TEST_DEP = $(TEST_OBJ:.o=.d)
LIBR_OBJ = $(filter-out src/main.o, $(OBJ))
TEST_EXEC = test_numc

$(EXEC): $(OBJ)  # target: prerequisites
	$(CC) $^ -o $@

$(TEST_EXEC): $(LIBR_OBJ) $(TEST_OBJ)
	$(CC) $^ -o $@

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

-include $(DEP) $(TEST_DEP) # header dependencies

all: $(EXEC)

run: $(EXEC)
	./$(EXEC)

test: $(TEST_EXEC)
	./$(TEST_EXEC)

clean:
	rm -f $(OBJ) $(DEP) $(EXEC) $(TEST_OBJ) $(TEST_DEP) $(TEST_EXEC)

.PHONY: all run test clean


# Notes to self:
# `%` 			in pattern rules matches any set of characters
# `*` 			matches all files in a given directory
# `**` 			in wildcard function matches files/directories recursively
# `-Wall` 		(Warnings All) enables most compiler warnings
# `-Wextra` 	(Warnings Extra) enables additional compiler warnings for other common oversights 
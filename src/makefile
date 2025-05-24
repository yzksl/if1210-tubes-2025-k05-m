# This is a makefile for compiling your whole project.
# It is used to compile all the source files in the src directory and link them together.
# It is also used to clean up the build directory and remove all the object files and the executable.
# The makefile is used to compile the project using the gcc compiler.

# Things to explore:
# - Linux, MacOS, WSL for Windows
# - Makefile variables
# - Makefile rules
# - Makefile targets
# - Makefile dependencies
# - Makefile commands

# ---------------------- Example makefile for a C project ----------------------

TARGET_DIR = build
SRC_DIR = c

# This is variable that specifies the compiler to use.
CC = gcc
# This is variable that specifies the compiler flags to use.
CFLAGS = -g -Wall -Iheader
# This is variable that specifies the source files to compile.
SRCS = $(wildcard $(SRC_DIR)/*.c) main.c test.c
# This is variable that specifies the object files to create.
OBJS = $(patsubst $(SRC_DIR)/%.c,$(TARGET_DIR)/%.o,$(filter $(SRC_DIR)/%.c,$(SRCS))) \
       $(TARGET_DIR)/main.o \
       $(TARGET_DIR)/test.o

# Default target - builds both programs
all: main test

# This target builds the main program
main: $(filter-out $(TARGET_DIR)/test.o,$(OBJS))
	@echo "Linking main program..."
	$(CC) $(LDFLAGS) $^ -o $@
	@echo "Main program built. Executable: $@"

# This target builds the test program
test: $(filter-out $(TARGET_DIR)/main.o,$(OBJS))
	@echo "Linking test program..."
	$(CC) $(LDFLAGS) $^ -o $@
	@echo "Test program built. Executable: $@"

# Rule for utility .c files in c/ directory
$(TARGET_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -c $< -o $@

# Special rule for main.c in root directory
$(TARGET_DIR)/main.o: main.c
	@mkdir -p $(TARGET_DIR)
	@echo "Compiling main.c..."
	$(CC) $(CFLAGS) -c $< -o $@

# Special rule for test.c in root directory
$(TARGET_DIR)/test.o: test.c
	@mkdir -p $(TARGET_DIR)
	@echo "Compiling test.c..."
	$(CC) $(CFLAGS) -c $< -o $@

# This target is used to clean up the build directory and remove all the object files and executables
clean:
	rm -rf build
	rm -f main test
	rm -f *.o *.out *.exe *.a *.so *.dll *.dSYM *.pdb *.ilk *.idb *.lib *.exp

.PHONY: all clean main test
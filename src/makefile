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
SRCS = $(wildcard $(SRC_DIR)/*.c) main.c
# This is variable that specifies the object files to create.
OBJS = $(patsubst $(SRC_DIR)/%.c,$(TARGET_DIR)/%.o,$(filter $(SRC_DIR)/%.c,$(SRCS))) \
       $(TARGET_DIR)/main.o
# This is variable that specifies the name of the executable file.
TARGET = main
# This is variable that specifies target compile directory.


# TODO: Explore best practices for makefiles
# HINT: Do step by step compilation and linking (e.g. compile all .c files to .o files, then link them together to create the executable)
# HINT: Specify output directory for object files and executable (e.g. build/) and ignore the build directory in the git repository


# Default target
all: $(TARGET_DIR)/$(TARGET)

$(TARGET_DIR)/$(TARGET): $(OBJS)
	@echo "Linking object files..."
	$(CC) $(LDFLAGS) $^ -o $@
	@echo "Build complete. Executable: $@"

# Rule for utility .c files in c/ directory
$(TARGET_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -c $< -o $@

# Special rule for main.c in root directory
$(TARGET_DIR)/main.o: main.c
	@mkdir -p $(TARGET_DIR)
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -c $< -o $@

# This target is used to compile all the source files in the src directory and link them together.
clean:
	rm -rf build
	rm -f $(TARGET)
	rm -f *.o
	rm -f *.out
	rm -f *.exe
	rm -f *.a
	rm -f *.so
	rm -f *.dll
	rm -f *.dSYM
	rm -f *.pdb
	rm -f *.ilk
	rm -f *.idb
	rm -f *.lib
	rm -f *.exp
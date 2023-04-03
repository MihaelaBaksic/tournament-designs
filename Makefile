
CC=g++

SRC = src
BUILD = build
OBJ = $(BUILD)/objects
MKDIR_P = mkdir -p

# define build directories
.PHONY: DIRECTORIES
all: DIRECTORIES $(BUILD)/prog
DIRECTORIES: $(BUILD) $(OBJ)

# make directories for object and executable files
$(BUILD):
	$(MKDIR_P) $(BUILD)

$(OBJ):
	$(MKDIR_P) $(OBJ)



# link object files
$(BUILD)/prog: $(OBJ)/tournament_design.o $(OBJ)/io.o $(OBJ)/utils.o 
	$(CC) -o $(BUILD)/prog $(OBJ)/tournament_design.o $(OBJ)/io.o $(OBJ)/utils.o 


# compile source files
$(OBJ)/tournament_design.o: $(SRC)/tournament_design.h $(SRC)/tournament_design.cpp
	$(CC) -c $(SRC)/tournament_design.cpp -o $(OBJ)/tournament_design.o

$(OBJ)/io.o: $(SRC)/io/io.h $(SRC)/io/io.cpp
	$(CC) -c $(SRC)/io/io.cpp -o $(OBJ)/io.o


$(OBJ)/utils.o: $(SRC)/utils/utils.h
	$(CC) -c $(SRC)/utils/utils.cpp -o $(OBJ)/utils.o


# clear build directory
clear:
	rm -r $(BUILD)



CC=g++

SRC = src
BUILD = build
OBJ = $(BUILD)/objects
MKDIR_P = mkdir -p

ALL_OBJECTS = $(OBJ)/main.o $(OBJ)/io.o $(OBJ)/utils.o $(OBJ)/TD.o $(OBJ)/BTD.o $(OBJ)/latin_square.o 

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
$(BUILD)/prog: $(ALL_OBJECTS) 
	$(CC) -o $(BUILD)/prog $(ALL_OBJECTS)  



# compile source files

$(OBJ)/main.o: $(SRC)/main.cpp
	$(CC) -c $(SRC)/main.cpp -o $(OBJ)/main.o

$(OBJ)/io.o: $(SRC)/io/io.h $(SRC)/io/io.cpp
	$(CC) -c $(SRC)/io/io.cpp -o $(OBJ)/io.o


$(OBJ)/utils.o: $(SRC)/utils/utils.h  $(SRC)/utils/utils.cpp
	$(CC) -c $(SRC)/utils/utils.cpp -o $(OBJ)/utils.o


$(OBJ)/TD.o: $(SRC)/designs/TD.h $(SRC)/designs/TD.cpp
	$(CC) -c $(SRC)/designs/TD.cpp -o $(OBJ)/TD.o


$(OBJ)/BTD.o: $(SRC)/designs/BTD.h $(SRC)/designs/BTD.cpp
	$(CC) -c $(SRC)/designs/BTD.cpp -o $(OBJ)/BTD.o


$(OBJ)/latin_square.o: $(SRC)/designs/latin_square.h $(SRC)/designs/latin_square.cpp
	$(CC) -c $(SRC)/designs/latin_square.cpp -o $(OBJ)/latin_square.o



# clear build directory
clear:
	rm -r $(BUILD)


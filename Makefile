
CC=g++
CC_FLAGS= -std=c++17 -g -O3
CC_FLAGS_TEST = -lcppunit -Wall

SRC = src
BUILD = bin
TEST = test
BUILD_TEST = $(BUILD)/$(TEST)
OBJ_TEST = $(BUILD_TEST)/objects
OBJ = $(BUILD)/objects
MKDIR_P = mkdir -p

ALL_OBJECTS = $(OBJ)/io.o $(OBJ)/utils.o $(OBJ)/TD.o $(OBJ)/BTD.o $(OBJ)/latin_square.o  $(OBJ)/BipartiteTD.o $(OBJ)/CarryOverBipartiteTD.o $(OBJ)/MOLS.o
TEST_OBJECTS = $(OBJ_TEST)/BTD_test.o

# define build directories
.PHONY: DIRECTORIES
all: DIRECTORIES $(BUILD)/prog $(BUILD_TEST)/test 
DIRECTORIES: $(BUILD) $(OBJ) $(BUILD_TEST) $(OBJ_TEST)

# make directories for object and executable files
$(BUILD):
	$(MKDIR_P) $(BUILD)

$(OBJ):
	$(MKDIR_P) $(OBJ)

$(BUILD_TEST):
	$(MKDIR_P) $(BUILD_TEST)

$(OBJ_TEST): 
	$(MKDIR_P) $(OBJ_TEST)


# link program object files
$(BUILD)/prog: $(ALL_OBJECTS) $(OBJ)/main.o
	$(CC) -o $(BUILD)/prog $(ALL_OBJECTS) $(OBJ)/main.o $(CC_FLAGS)  


# link test object files
$(BUILD_TEST)/test: $(OBJ_TEST)/test.o $(TEST_OBJECTS) $(ALL_OBJECTS) 
	$(CC) -o $(BUILD_TEST)/test  $(OBJ_TEST)/test.o $(ALL_OBJECTS) $(TEST_OBJECTS) $(CC_FLAGS)  $(CC_FLAGS_TEST)



# compile source files

$(OBJ)/main.o: $(SRC)/main.cpp
	$(CC) -c $(SRC)/main.cpp -o $(OBJ)/main.o $(CC_FLAGS)

$(OBJ)/io.o: $(SRC)/io/io.h $(SRC)/io/io.cpp
	$(CC) -c $(SRC)/io/io.cpp -o $(OBJ)/io.o $(CC_FLAGS)


$(OBJ)/utils.o: $(SRC)/utils/utils.h  $(SRC)/utils/utils.cpp
	$(CC) -c $(SRC)/utils/utils.cpp -o $(OBJ)/utils.o $(CC_FLAGS)


$(OBJ)/TD.o: $(SRC)/designs/TD.h $(SRC)/designs/TD.cpp
	$(CC) -c $(SRC)/designs/TD.cpp -o $(OBJ)/TD.o $(CC_FLAGS)


$(OBJ)/BTD.o: $(SRC)/designs/BTD.h $(SRC)/designs/BTD.cpp
	$(CC) -c $(SRC)/designs/BTD.cpp -o $(OBJ)/BTD.o $(CC_FLAGS)


$(OBJ)/latin_square.o: $(SRC)/designs/latin_square.h $(SRC)/designs/latin_square.cpp
	$(CC) -c $(SRC)/designs/latin_square.cpp -o $(OBJ)/latin_square.o $(CC_FLAGS)

$(OBJ)/MOLS.o: $(SRC)/designs/MOLS.h $(SRC)/designs/MOLS.cpp
	$(CC) -c $(SRC)/designs/MOLS.cpp -o $(OBJ)/MOLS.o $(CC_FLAGS)


$(OBJ)/BipartiteTD.o: $(SRC)/designs/BipartiteTD.h $(SRC)/designs/BipartiteTD.cpp
	$(CC) -c $(SRC)/designs/BipartiteTD.cpp -o $(OBJ)/BipartiteTD.o $(CC_FLAGS)

$(OBJ)/CarryOverBipartiteTD.o: $(SRC)/designs/CarryOverBipartiteTD.h $(SRC)/designs/CarryOverBipartiteTD.cpp
	$(CC) -c $(SRC)/designs/CarryOverBipartiteTD.cpp -o $(OBJ)/CarryOverBipartiteTD.o $(CC_FLAGS)



# compile test source files

$(OBJ_TEST)/BTD_test.o : $(TEST)/BTD_test.cpp
	$(CC) -c $(TEST)/BTD_test.cpp -o $(OBJ_TEST)/BTD_test.o $(CC_FLAGS) $(CC_FLAGS_TEST)

$(OBJ_TEST)/test.o : $(TEST_OBJECTS)
	$(CC) -c $(TEST)/test.cpp -o $(OBJ_TEST)/test.o $(CC_FLAGS) $(CC_FLAGS_TEST)



# clear build directory
clear:
	rm -r $(BUILD)

clear_t :
	rm -r $(BUILD_TEST)


t: DIRECTORIES $(BUILD_TEST)/test










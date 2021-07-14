# Name of the project
PROJ_NAME = libraryManagement
TEST_PROJ_NAME = Test_$(PROJ_NAME)
FILE_NAME = LTTSLibrary.bin
# Output directory
BUILD_DIR = build

# All source code files
SRC = src/addBook.c\
src/deleteBook.c\
src/init.c\
src/login.c\
src/menu.c\
src/message.c\
src/searchBook.c\
src/updateBook.c\
src/valid_file.c\
src/valid_name.c\
src/valid_date.c\
src/addDate.c\
src/valid_year.c\
src/viewBook.c

TEST_SRC = test/library_test.c\
unity/unity.c

# All include folders with header files
INC = -Iinc\
-Iunity

ifdef OS
   RM = rm -rf
   FixPath = $(subst /,\,$1)
   EXEC = exe
else
   ifeq ($(shell uname), Linux)
      RM = rm -rf
      FixPath = $1
	  EXEC = out
   endif
endif

.PHONY: all test clean

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

all: $(BUILD_DIR)
	gcc main.c $(INC) $(SRC) -o $(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).$(EXEC))

run: all
	$(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).$(EXEC))

test: $(BUILD_DIR)
	gcc $(SRC) $(TEST_SRC) $(INC) -o $(call FixPath,$(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC))
	./$(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC) < test/input_test.txt

coverage:${PROJECT_NAME} $(BUILD_DIR)
	gcc -fprofile-arcs -ftest-coverage $(SRC) $(TEST_SRC) $(INC) -o $(call FixPath,$(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC))
	$(call FixPath,$(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC)) < test/input_test.txt
	gcov -a $(SRC) -o .
memcheck:
	valgrind $(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC) < test/input_test.txt
clean:
	$(RM) $(call FixPath,$(BUILD_DIR)/*) $(FILE_NAME) 
	$(RM) *.gcda 
	$(RM) *.gcno
	$(RM) *.gcov
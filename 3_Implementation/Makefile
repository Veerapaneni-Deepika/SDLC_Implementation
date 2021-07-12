# Name of the project
PROJECT_NAME = libraryManagement
FILE_NAME = DeepikaLTTS.bin
# Output directory
BUILD = build

# All source code files
SRC = main.c\
src/addbook.c\
src/deletebook.c\
src/init.c\
src/login.c\
src/menu.c\
src/message.c\
src/searchbook.c\
src/updatebook.c\
src/valid_name.c\
src/valid_year.c\
src/viewbook.c

# All include folders with header files
INC = inc

ifdef OS
   RM = del 
   FixPath = $(subst /,\,$1)
   EXEC = exe
else
   ifeq ($(shell uname), Linux)
      RM = rm -rf
      FixPath = $1
	   EXEC = out
   endif
endif


#Library Inlcudes
#INCLUDE_LIBS = 
INCLUDE_LIBS = -lcunit

# Project Output name
PROJECT_OUTPUT = $(BUILD)/$(PROJECT_NAME)


# Default target built
$(PROJECT_NAME):all

# Run the target even if the matching name exists
.PHONY: run clean test doc all

all: $(SRC) $(BUILD)
	gcc $(SRC) -I$(INC) -o $(PROJECT_OUTPUT).$(EXEC)

# Call `make run` to run the application
run:$(PROJECT_NAME)
	./$(PROJECT_OUTPUT).$(EXEC)

# Remove all the built files, invoke by `make clean`
clean:
	rm -rf $(BUILD) $(FILE_NAME)

# Create new build folder if not present
$(BUILD):
	mkdir build
# Name of the project
PROJ_NAME = libraryManagement
FILE_NAME = DeepikaLTTS.bin
# Output directory
BUILD_DIR = build

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

all: $(SRC) $(BUILD_DIR)
	gcc -I $(INC) $(SRC) -o $(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).$(EXEC))

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

run: all
	$(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).$(EXEC))

clean:
	$(RM) $(BUILD_DIR) $(FILE_NAME)
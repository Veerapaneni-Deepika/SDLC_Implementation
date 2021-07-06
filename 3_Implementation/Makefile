TEST_PROJ_NAME = library_management_sys
BUILD_DIR = Build

INC = inc/library.h

SRC = project_main.c\
src/addBook.c\
src/deleteBook.c\
src/init.c\
src/login.c\
src/searchBook.c\
src/updateBook.c\
src/viewBook.c


ifdef OS
   RM = del /q
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
	gcc -I $(INC) $(SRC) -o $(call FixPath,$(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC))

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

run: all
	$(call FixPath,$(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC))

clean:
	$(RM) $(call FixPath,$(BUILD_DIR)/*)
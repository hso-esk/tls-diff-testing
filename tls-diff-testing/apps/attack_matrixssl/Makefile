SRC_SUFFIX = .cpp

EXECUTABLE = $(shell basename $(shell pwd))

SRC_DIR    = src
INC_DIRS   = inc ../../bitman/inc ../../cryptoman/inc ../../middleman/inc
LIB_DIRS   = ../../bitman/build ../../cryptoman/build ../../middleman/build

BUILD_DIR  = build
OBJ_DIR    = $(BUILD_DIR)/obj
PREP_DIR   = $(BUILD_DIR)/prep
LIBOBJ_DIR =

LIBS       = middleman cryptoman bitman cryptopp


# define compiler
CC = g++

# define macros
MACROS = _LINUX

# define architecture
ARCH   =

CFLAGS  = -c -Wall $(foreach d, $(INC_DIRS), -I$d) $(foreach d, $(MACROS), -D$d) $(ARCH) -O0 -g $(PROF)
LDFLAGS = $(ARCH) $(foreach d, $(LIB_DIRS), -L$d) $(foreach d, $(LIBS), -l$d) $(PROF)


MAIN_SRC  = $(SRC_DIR)/$(EXECUTABLE)$(SRC_SUFFIX)
SOURCES_  = $(shell ls $(SRC_DIR)/*$(SRC_SUFFIX))
SOURCES   = $(filter-out $(MAIN_SRC),$(SOURCES_))

OBJECTS_  = $(SOURCES:$(SRC_SUFFIX)=.o)
OBJECTS   = $(OBJECTS_:$(SRC_DIR)/%=$(OBJ_DIR)/%)
PREPS     = $(SOURCES_:$(SRC_DIR)/%=$(PREP_DIR)/%)
MAIN_OBJ_ = $(MAIN_SRC:$(SRC_SUFFIX)=.o)
MAIN_OBJ  = $(MAIN_OBJ_:$(SRC_DIR)/%=$(OBJ_DIR)/%)

LIB_OBJS  = $(shell ls $(LIBOBJ_DIR)/*.o 2>/dev/null)


all: executable

exec: executable

prep: preprocessed

executable: $(OBJECTS) $(MAIN_OBJ)
	@echo "\033[01;33m==> Creating executable '$(BUILD_DIR)/$(EXECUTABLE)':\033[00;00m"
	@mkdir -p $(BUILD_DIR)
	$(CC) $(OBJECTS) $(MAIN_OBJ) -o $(BUILD_DIR)/$(EXECUTABLE) $(LDFLAGS)
	@echo ""
	@echo "\033[01;33m==> Creating link '$(EXECUTABLE)' to executable '$(BUILD_DIR)/$(EXECUTABLE)':\033[00;00m"
	@rm -rf $(EXECUTABLE)
	ln -s $(BUILD_DIR)/$(EXECUTABLE) $(EXECUTABLE)
	@echo ""

preprocessed: $(PREPS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%$(SRC_SUFFIX)
	@echo "\033[01;32m==> Compiling '$<':\033[00;00m"
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $< -o $@
	@echo ""

$(PREP_DIR)/%: $(SRC_DIR)/%
	@echo "\033[01;32m==> Preprocessing '$<':\033[00;00m"
	@mkdir -p $(PREP_DIR)
	$(CC) $(CFLAGS) $< -E > $@
	@echo ""

clean:
	@echo "\033[01;31m==> Cleaning directories:\033[00;00m"
	rm -rf $(BUILD_DIR)/
	rm -rf $(EXECUTABLE)
	@echo ""

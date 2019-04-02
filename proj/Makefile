path       := $(abspath $(lastword $(MAKEFILE_LIST)))
BASE       := $(patsubst %/,%,$(dir $(abspath $(lastword $(path)))))
SRC_DIR     = $(BASE)/../src
INC_DIR     = $(BASE)/../inc
TARGET_DIR  = $(BASE)/../bin
OBJ_DIR     = $(TARGET_DIR)/obj
TARGET      = sorter2

LIBS_PATH   =
STD_LIBS    =

CC          = g++
CFLAGS      = -Wall -std=c++11 -pedantic -D_POSIX_C_SOURCE=200809L -I$(INC_DIR)
LIB_FLAGS   =
LIBS        = -lcpplogging -lutils

# only add library paths if libraries are used
ifeq ($(strip $(LIBS)),)
else
LIBS_PATH   := $(BASE)/../../libraries
LIB_FLAGS   := -L$(LIBS_PATH)/bin
STD_LIBS    := $(LIBS_PATH)/bin/libcpplogging.a $(LIBS_PATH)/bin/libutils.a
CFLAGS      += -I$(LIBS_PATH)
endif

SRCS       := $(wildcard $(SRC_DIR)/*.cpp)
OBJ         = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))
DEPS        = $(patsubst %,$(INC_DIR)/%.h, *)
DEPS       += $(patsubst %,$(LIBS_PATH)/%.h, *)

.PHONY: all clean

# make object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(DEPS) | $(OBJ_DIR)
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(OBJ) $(STD_LIBS)
	$(CC) -o $(TARGET_DIR)/$(TARGET) $^ $(CFLAGS) $(LIB_FLAGS) $(LIBS)

clean:
	rm -frd $(OBJ_DIR) $(TARGET_DIR)/*

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

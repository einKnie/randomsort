path       := $(abspath $(lastword $(MAKEFILE_LIST)))
BASE       := $(patsubst %/,%,$(dir $(abspath $(lastword $(path)))))
SRC_DIR     = $(BASE)/../src
INC_DIR     = $(BASE)/../inc
TARGET_DIR  = $(BASE)/../bin
OBJ_DIR     = $(TARGET_DIR)/obj
TARGET      = sorter

CC          = g++
CFLAGS      = -Wall -pedantic -I$(INC_DIR)

SRCS       := $(wildcard $(SRC_DIR)/*.cpp)
OBJ         = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))
DEPS       += $(patsubst %,$(INC_DIR)/%.h, *)

.PHONY: all clean

# make object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(DEPS) | $(OBJ_DIR)
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(OBJ) $(STD_LIBS)
	$(CC) -o $(TARGET_DIR)/$(TARGET) $^ $(CFLAGS)

clean:
	rm -frd $(OBJ_DIR) $(TARGET_DIR)/*

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

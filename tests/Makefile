BUILD_PATH ?= ../BUILD
CU_PATH := $(BUILD_PATH)/CUnit-build

CC := gcc
CFLAGS := -O3 -Wall -Wextra -pedantic -std=c11 -m32 -I../include -I$(CU_PATH)/include
LDFLAGS := -m32 -no-pie -z noexecstack -L$(CU_PATH)/lib
LDFLAGS_END := $(CU_PATH)/lib/libcunit.a -lm

SRC_TEST := $(shell find . -name '*.c')
OBJ_TEST := $(patsubst %.c, $(BUILD_PATH)/tests/%.o, $(SRC_TEST))

OBJ_IMPL := $(shell find $(BUILD_PATH)/src -name '*.o' -not -name 'main.o')

TARGET ?= $(BUILD_PATH)/tests/integrate_test

all: $(TARGET)
	cp $(TARGET) ../$(notdir $(TARGET))

$(TARGET): $(OBJ_TEST) $(OBJ_IMPL)
	@mkdir -p $(dir $@)
	$(CC) $(LDFLAGS) $^ -o $@ $(LDFLAGS_END)

$(BUILD_PATH)/tests/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_PATH)/tests ../$(notdir $(TARGET))

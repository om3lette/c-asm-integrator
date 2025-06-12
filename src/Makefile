BUILD_PATH  ?= ../BUILD

CC          := gcc
CFLAGS      := -O3 -m32 -Werror -Wall -Wextra -pedantic -Wfloat-equal -std=c11 -I../include -DROOT_METHOD=$(ROOT_METHOD)
LDFLAGS     := -m32 -no-pie -z noexecstack
LDFLAGS_END := -lm

AS			 := nasm
AFLAGS	 := -f elf32

SRC_PATH := $(BUILD_PATH)/src
TARGET   := $(SRC_PATH)/integral

SRC_C    := $(shell find . -name '*.c')
SRC_ASM  := $(shell find ./functions/asm -name '*.asm')

OBJ_C    := $(patsubst ./%.c,   $(SRC_PATH)/%.o, $(SRC_C))
OBJ_A 	 := $(patsubst ./%.asm, $(SRC_PATH)/%.o, $(SRC_ASM))
OBJ   	 := $(OBJ_C) $(OBJ_A)

all: $(TARGET)

$(TARGET): $(OBJ)
	@mkdir -p $(dir $@)
	$(CC) $(LDFLAGS) $(OBJ) -o $@ $(LDFLAGS_END)
	cp $(TARGET) ../$(notdir $(TARGET))

$(SRC_PATH)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(SRC_PATH)/%.o: %.asm
	@mkdir -p $(dir $@)
	$(AS) $(AFLAGS) $< -o $@

clean:
	rm -rf $(BUILD_PATH)/*.o $(TARGET)

CC      := gcc
CFLAGS  := -O3 -m32 -Wall -Wextra -pedantic -Wfloat-equal -std=c11 -Iintegrator/include
LDFLAGS := -m32 -no-pie -z noexecstack
LDFLAGS_END := -lm

AS      := nasm
AFLAGS  := -f elf32

BUILD_PATH := BUILD
TARGET     := $(BUILD_PATH)/integrate

SRC_C     := $(shell find src -name '*.c')
SRC_ASM := $(shell find src/functions/asm -name '*.asm')

SRC_C_BASENAMES   := $(notdir $(SRC_C))
SRC_ASM_BASENAMES := $(notdir $(SRC_ASM))

SRC_DIRS := $(sort $(dir $(SRC_C) $(SRC_ASM)))

vpath %.c $(SRC_DIRS)
vpath %.asm src/functions/asm

OBJ_C   := $(patsubst %.c,   $(BUILD_PATH)/%.o, $(notdir $(SRC_C)))
OBJ_A   := $(patsubst %.asm, $(BUILD_PATH)/%.o, $(notdir $(SRC_ASM)))
OBJ     := $(OBJ_C) $(OBJ_A)

.PHONY: all run clean

all: $(TARGET)
	cp $(TARGET) $(basename $(notdir $(TARGET)))

run: $(TARGET)
	./$(TARGET)

$(BUILD_PATH):
	mkdir -p $(BUILD_PATH)

$(BUILD_PATH)/%.o: %.c | $(BUILD_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_PATH)/%.o: %.asm | $(BUILD_PATH)
	$(AS) $(AFLAGS) $< -o $@


$(TARGET): $(OBJ) | $(BUILD_PATH)
	$(CC) $(LDFLAGS) $(OBJ) -o $@ $(LDFLAGS_END)


clean:
	rm -rf $(BUILD_PATH) $(basename $(notdir $(TARGET)))

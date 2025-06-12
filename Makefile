.PHONY: all clean deps test

all: deps build build_tests

BUILD_PATH      := $(shell pwd)/BUILD
INCLUDE_PATH    := $(shell pwd)/include
TEST_EXECUTABLE := $(BUILD_PATH)/tests/integral_tests

ROOT_METHOD 	  ?= 3

$(BUILD_PATH):
	mkdir -p $(BUILD_PATH)

deps: $(BUILD_PATH)
	git submodule update --init --recursive
	INCLUDE_PATH=$(INCLUDE_PATH) BUILD_PATH=$(BUILD_PATH) $(MAKE) -C vendor

build: $(BUILD_PATH)
	ROOT_METHOD=$(ROOT_METHOD) BUILD_PATH=$(BUILD_PATH) $(MAKE) -C src

test: build_tests
	$(TEST_EXECUTABLE)

build_tests: $(BUILD_PATH)
	TARGET=$(TEST_EXECUTABLE) BUILD_PATH=$(BUILD_PATH) $(MAKE) -C tests

clean:
	$(MAKE) -C vendor clean
	rm -rf $(BUILD_PATH)

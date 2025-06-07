.PHONY: all clean

all:
	cd CUnit && \
		autoreconf -i && \
		CFLAGS=-m32 LDFLAGS=-m32 ./configure --prefix=$(BUILD_PATH)/CUnit-build && \
		$(MAKE) && \
		$(MAKE) install
	cp -r $(BUILD_PATH)/CUnit-build/include/CUnit $(INCLUDE_PATH)

clean:
	$(MAKE) -C CUnit/CUnit/Sources clean
	rm -rf $(INCLUDE_PATH)/CUnit

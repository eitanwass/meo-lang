CC = gcc
BUILD_DIR = build
TARGET = $(BUILD_DIR)/out/meo

CFLAGS = -Wall -Wextra -std=c99
CFLAGS += -Iinclude
CFLAGS += $(shell find include -type d | sed 's/^/-I/')

DEPFLAGS = -MMD -MP

# Debug mode
DEBUG ?= n
ifneq ($(DEBUG), n)
	CFLAGS += -g
	CFLAGS += -DDEBUG_TRACE_EXECUTION
else
	CFLAGS += -O2
endif

# Find all source files recursively
SOURCES = $(shell find src -name '*.c' -type f)
OBJECTS = $(patsubst src/%.c,$(BUILD_DIR)/%.o,$(SOURCES))
DEPS = $(OBJECTS:.o=.d)

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

-include $(DEPS)

clean:
	rm -rf $(BUILD_DIR)

run: $(TARGET)
	./$(TARGET)

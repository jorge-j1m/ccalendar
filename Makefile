CC := clang
CFLAGS := -Wall -Wextra -Werror -std=c11 -pedantic -I./include
SRCDIR := src
TESTDIR := tests
BUILDDIR := build
TARGET := myprogram
TEST_TARGET := run_tests

SRCS := $(wildcard $(SRCDIR)/*.c)
OBJS := $(patsubst $(SRCDIR)/%.c,$(BUILDDIR)/%.o,$(SRCS))
TEST_SRCS := $(wildcard $(TESTDIR)/*.c)
TEST_OBJS := $(patsubst $(TESTDIR)/%.c,$(BUILDDIR)/%.o,$(TEST_SRCS))

UNITY_SRC := $(TESTDIR)/unity/unity.c
UNITY_OBJ := $(BUILDDIR)/unity.o

LOG_LEVEL ?= NONE
.PHONY: all clean test

all: $(TARGET)

test: $(TEST_TARGET)
	LOG_LEVEL=$(LOG_LEVEL) ./$(TEST_TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(TEST_TARGET): $(filter-out $(BUILDDIR)/main.o,$(OBJS)) $(TEST_OBJS) $(UNITY_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILDDIR)/%.o: $(SRCDIR)/%.c | $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILDDIR)/%.o: $(TESTDIR)/%.c | $(BUILDDIR)
	$(CC) $(CFLAGS) -I$(SRCDIR) -I$(TESTDIR)/unity -c $< -o $@

$(UNITY_OBJ): $(UNITY_SRC) | $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILDDIR):
	mkdir -p $@

clean:
	rm -rf $(BUILDDIR) $(TARGET) $(TEST_TARGET)

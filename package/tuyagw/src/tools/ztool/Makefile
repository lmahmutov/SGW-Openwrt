COMPILE_PREX   ?= # Cross compile prefix

AR   = $(COMPILE_PREX)ar
CC   = $(COMPILE_PREX)gcc
NM   = $(COMPILE_PREX)nm
CPP  = $(COMPILE_PREX)g++

CFLAGS   +=
LDFLAGS  +=

PROC = ztool
OBJS = $(patsubst %.c,%.o,$(wildcard *.c))

all: $(PROC)
	@echo "compile done"

$(PROC): $(OBJS)
	$(CC) $^ -o $@ $(LDFLAGS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm $(PROC) $(OBJS)

.PHONY: all clean

CC = gcc
CFLAGS = -Wall -Wextra -g

OUT = opk

SRCS = $(wildcard src/*.c) # Find all src files.
OBJS = $(SRCS:.c=.o) # Create corresponding list of obj files.

all: $(OUT)

$(OUT): $(OBJS)
	mkdir -p bin
	$(CC) $(CFLAGS) -o $(OUT) $(OBJS)
	rm $(OBJS)

# Generic rule to compile .c to .o.
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(OUT) $(OBJS)

CC = gcc
CFLAGS = -std=c89 -Wall -c
LDFLAGS = -Wall
OBJECTS = stack.o main.o
EXECUTABLE = stack

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^

.PHONY: clean
clean:
	$(RM) $(EXECUTABLE) $(OBJECTS)

%.o: %.c stack.h
	$(CC) $(CFLAGS) $<

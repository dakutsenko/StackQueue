TARGET = stack
OBJECTS = stack.o main.o

$(TARGET): $(OBJECTS)
	gcc -Wall -o $@ $^

.PHONY: clean
clean:
	-rm $(TARGET) $(OBJECTS)

stack.o: stack.c stack.h
	gcc -std=c89 -Wall -c $<

main.o: main.c stack.h
	gcc -std=c89 -Wall -c $<

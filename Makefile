TARGET = stack
$(TARGET): main.c
	gcc -std=c89 -Wall -o $@ $^
.PHONY: clean
clean:
	-rm $(TARGET)

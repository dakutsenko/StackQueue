# Компилятор
CC = gcc
# Флаги для компиляции объектных файлов
CFLAGS = -std=c89 -Wall -c
# Флаги для компоновки исполняемого файла
LDFLAGS = -Wall
# Объектные файлы
OBJECTS = stack.o main.o
# Исполняемый файл
EXECUTABLE = stack

# ПРАВИЛА ДЛЯ СБОРКИ ПРОЕКТА

# Сборка исполняемого файла
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^

# Удаление всех бинарных файлов
.PHONY: clean
clean:
	$(RM) $(EXECUTABLE) $(OBJECTS)

# Сборка объектных файлов
%.o: %.c stack.h
	$(CC) $(CFLAGS) $<

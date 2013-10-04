# Описание сборки проекта с раздельной компиляцией модулей

# Сборка проекта (перекомпилируются только изменённые модули): $ make
# Полная пересборка проекта: $ make -B
# Запуск исполняемого файла: $ ./sdprobe
# Очистка проекта от скомплированных бинарных файлов: $ make clean

#1. Главная задача: компоновка исполняемого файла из объектных файлов модулей
sdprobe: stack.o queue.o main.o
	gcc -Wall stack.o queue.o main.o -o sdprobe
#2. Если необходимо, то компиляция модуля стека в объектный файл stack.o
stack.o: stack.c stack.h
	gcc -std=c89 -Wall -c stack.c
#3. Если необходимо, то компиляция модуля очереди в объектный файл queue.o
queue.o: queue.c queue.h
	gcc -std=c89 -Wall -c queue.c
#3. Если необходимо, то компиляция основной программы в объектный файл main.o
main.o: main.c stack.h queue.h
	gcc -std=c89 -Wall -c main.c
#4. Удаление скомпилированных бинарных файлов
clean:
	rm -f stack.o main.o queue.o sdprobe

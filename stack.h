#ifndef STACK_H
#define STACK_H
/* МОДУЛЬ ДЛЯ РАБОТЫ СО СТЕКОМ НА МАССИВЕ */

/* Базовый тип элементов стека */
typedef int ElemT;

/* Стек на массиве */
typedef struct {
	/* Индекс, указывающий на вершину стека */
	int t;
	/* Максимальный размер стека */
	int MAX_SIZE;
	/* Массив элементов */
	ElemT *d;
} Stack;

/* Создать новый стек */
Stack *createStack(int maxSize);

/* Уничтожить стек */
void killStack(Stack *s);

/* Очистить стек */
void clear(Stack *s);

/* Стек пуст */
int isEmpty(Stack *s);

/* Стек заполнен, нет места для нового элемента */
int isFull(Stack *s);

/* Добавить в стек новый элемент a */
/* ПРЕДУСЛОВИЕ: стек не переполнен! */
void push(Stack *s, ElemT a);

/* Элемент из вершины стека */
/* ПРЕДУСЛОВИЕ: стек не пуст! */
ElemT top(Stack *s);

/* Удалить верхний элемент из стека */
/* ПРЕДУСЛОВИЕ: стек не пуст! */
void pop(Stack *s);

/* Количество элементов в стеке */
int size(Stack *s);

#endif /* STACK_H */

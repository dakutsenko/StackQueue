#include <assert.h>
#include <stdlib.h>
#include "stack.h"

/* Реализация стека на массиве, 
 * массив увеличивается при необходимости */

struct Stack {
	/* Индекс, указывающий на вершину стека */
	int t;
	/* Вместимость стека */
	size_t capacity;
	/* Массив элементов */
	StackElemT *d;
};

StackPtr newStack(int startCapacity) {
	assert(startCapacity > 0);
	/* Выделить память под структуру стека */
	StackPtr res = (StackPtr)malloc(sizeof(struct Stack));
	assert(res != NULL);
	/* Выделить память под массив элементов */
	res->d = (StackElemT*)calloc(startCapacity, sizeof(StackElemT));
	assert(res->d != NULL);
	/* Инициализировать вместимость стека */
	res->capacity = startCapacity;
	/* Инициализировать начальную позицию вершины стека */
	res->t = -1;
	/* Вернуть указатель на созданный пустой стек */
	return res;
}

void deleteStack(StackPtr s) {
	/* Удалить массив с элементами */
	free(s->d);
	/* Удалить структуру стека */
	free(s);
}

void clearStack(StackPtr s) {
	/* Просто переустановить вершину в начальную позицию */
	s->t = -1;
}

int isEmptyStack(StackPtr s) {
	return s->t < 0;
}

/* Вспомогательная функция для extendStackIfNecessary() */
/* Стек заполнен, нет места для нового элемента */
int isFullStack(StackPtr s) {
	return s->t >= s->capacity - 1;
}
/* Вспомогательная функция для pushStack() */
/* Увеличить допустимый размер стека в K раз, если стек переполнен */
#define K 2
void extendStackIfNecessary(StackPtr s) {
	/* Если стек переполнен */
	if (isFullStack(s)) {
		/* Увеличить вместимость стека в K раз */
		s->capacity *= K;
		/* Новый размер массива (в байтах) */
		size_t newSize = s->capacity * sizeof(StackElemT);
		/* Перераспределить память под новый размер */
		s->d = (StackElemT*)realloc(s->d, newSize);
		assert(s->d != NULL);
	}
}
void pushStack(StackPtr s, StackElemT e) {
	/* Расширить массив, если это необходимо */
	extendStackIfNecessary(s);
	/* Переставить вершину на следующую позицию */
	++(s->t);
	/* Записать в неё новое значение */
	s->d[s->t] = e;
}

StackElemT topStack(StackPtr s) {
	assert(!isEmptyStack(s));
	return s->d[s->t];
}

void popStack(StackPtr s) {
	assert(!isEmptyStack(s));
	/* Просто переставить вершину на предыдущий элемент */
	--(s->t);
}

int sizeStack(StackPtr s) {
	return s->t + 1;
}

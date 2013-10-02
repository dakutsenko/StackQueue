#include "stack.h"
#include <assert.h>
#include <stdlib.h>

/* Реализация стека на массиве, 
 * массив увеличивается при необходимости */

struct Stack {
	/* Индекс, указывающий на вершину стека */
	int t;
	/* Вместимость стека */
	size_t capacity;
	/* Массив элементов */
	ElemT *d;
};

Stack *newStack(int startCapacity) {
	/* Выделить память под структуру стека */
	Stack *res = (Stack*)malloc(sizeof(Stack));
	assert(res != NULL);
	/* Выделить память под массив элементов */
	res->d = (ElemT*)calloc(startCapacity, sizeof(ElemT));
	assert(res->d != NULL);
	/* Инициализировать вместимость стека */
	res->capacity = startCapacity;
	/* Инициализировать начальную позицию вершины стека */
	res->t = -1;
	/* Вернуть указатель на созданный пустой стек */
	return res;
}

void killStack(Stack *s) {
	/* Удалить массив с элементами */
	free(s->d);
	/* Удалить структуру стека */
	free(s);
}

void clear(Stack *s) {
	/* Просто переустановить вершину в начальную позицию */
	s->t = -1;
}

int isEmpty(Stack *s) {
	return s->t < 0;
}

/* ВСПОМОГАТЕЛЬНАЯ ФУНКЦИЯ ДЛЯ extendIfNecessary() */
/* Стек заполнен, нет места для нового элемента */
int isFull(Stack *s) {
	return s->t >= s->capacity - 1;
}
/* ВСПОМОГАТЕЛЬНАЯ ФУНКЦИЯ ДЛЯ push() */
/* Увеличить допустимый размер стека в K раз, если стек переполнен */
#define K 2
void extendIfNecessary(Stack *s) {
	/* Если стек переполнен */
	if (isFull(s)) {
		/* Увеличить вместимость стека в K раз */
		s->capacity *= K;
		/* Новый размер массива (в байтах) */
		size_t newSize = s->capacity * sizeof(ElemT);
		/* Перераспределить память под новый размер */
		s->d = (ElemT*)realloc(s->d, newSize);
		assert(s->d != NULL);
	}
}
void push(Stack *s, ElemT e) {
	/* Расширить массив, если это необходимо */
	extendIfNecessary(s);
	/* Переставить вершину на следующую позицию */
	++(s->t);
	/* Записать в неё новое значение */
	s->d[s->t] = e;
}

ElemT top(Stack *s) {
	assert(!isEmpty(s));
	return s->d[s->t];
}

void pop(Stack *s) {
	assert(!isEmpty(s));
	/* Просто переставить вершину на предыдущий элемент */
	--(s->t);
}

int size(Stack *s) {
	return s->t + 1;
}

#include "stack.h"
#include <assert.h>
#include <stdlib.h>

Stack *createStack(int maxSize) {
	/* Выделить память под структуру стека */
	Stack *res = (Stack*)malloc(sizeof(Stack));
	assert(res != NULL);
	/* Выделить память под массив элементов */
	res->d = (ElemT*)malloc(maxSize * sizeof(ElemT));
	assert(res->d != NULL);
	/* Инициализировать максимальное количество элементов */
	res->MAX_SIZE = maxSize;
	/* Инициализировать начальную позицию вершины стека */
	res->t = -1;
	return res;
}

void killStack(Stack *s) {
	free(s->d);
	free(s);
}

void clear(Stack *s) {
	s->t = -1;
}

int isEmpty(Stack *s) {
	return s->t < 0;
}

int isFull(Stack *s) {
	return s->t >= s->MAX_SIZE;
}

void push(Stack *s, ElemT a) {
	assert(!isFull(s));
	s->d[++(s->t)] = a;
}

ElemT top(Stack *s) {
	assert(!isEmpty(s));
	return s->d[s->t];
}

void pop(Stack *s) {
	assert(!isEmpty(s));
	--(s->t);
}

int size(Stack *s) {
	return s->t + 1;
}

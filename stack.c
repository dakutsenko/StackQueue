#include "stack.h"
#include <assert.h>
#include <stdlib.h>

void init(Stack *s, int max_size) {
	s->MAX_SIZE = max_size;
	s->t = -1;
	s->d = (ElemT*)malloc(sizeof(ElemT) * max_size);
	assert(s->d != NULL);
}

void kill(Stack *s) {
	free(s->d);
	s->t = -1;
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

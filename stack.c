#include "stack.h"
#include <assert.h>

void init(Stack *s) {
	s->t = -1;
}

int isEmpty(Stack *s) {
	return s->t < 0;
}

int isFull(Stack *s) {
	return s->t >= MAX_SIZE;
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

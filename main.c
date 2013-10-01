#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* Максимальное количество элементов в стеке */
#define MAX_SIZE 100

/* Базовый тип элементов стека */
typedef int ElemT;

/* Стек на массиве */
typedef struct {
	/* Индекс, указывающий на вершину стека */
	int t;
	/* Массив элементов */
	ElemT d[MAX_SIZE];
} Stack;

/* Инициализировать стек перед использованием */
void init(Stack *s) {
	s->t = -1;
}

/* Стек пуст */
int isEmpty(Stack *s) {
	return s->t < 0;
}

/* Стек заполнен, нет места для нового элемента */
int isFull(Stack *s) {
	return s->t >= MAX_SIZE;
}

/* Добавить в стек новый элемент a */
/* ПРЕДУСЛОВИЕ: стек не переполнен! */
void push(Stack *s, ElemT a) {
	assert(!isFull(s));
	s->d[++(s->t)] = a;
}

/* Элемент из вершины стека */
/* ПРЕДУСЛОВИЕ: стек не пуст! */
ElemT top(Stack *s) {
	assert(!isEmpty(s));
	return s->d[s->t];
}

/* Удалить верхний элемент из стека */
/* ПРЕДУСЛОВИЕ: стек не пуст! */
void pop(Stack *s) {
	assert(!isEmpty(s));
	--(s->t);
}

/* Количество элементов в стеке */
int size(Stack *s) {
	return s->t + 1;
}

/* ПРИМЕР ПРОИЗВОДНОЙ ФУНКЦИИ */
/* Продублировать элемент на вершине стека */
void dup(Stack *s) {
	assert(!isFull(s));
	push(s, top(s));
}

/* ОСНОВНАЯ ПРОГРАММА */
int main(void) {
	int i;
	Stack s;
	init(&s);

	for (i = 0; i < 10; ++i) {
		push(&s, i);
		dup(&s);
	}
	while (!isEmpty(&s)) {
		printf("%d\n", top(&s));
		pop(&s);
	}

	return 0;
}

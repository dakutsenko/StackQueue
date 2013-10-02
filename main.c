#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/* Продублировать элемент на вершине стека */
void dup(Stack *s) {
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

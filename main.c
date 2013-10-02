#include <stdio.h>
#include "stack.h"

/* Продублировать элемент на вершине стека */
void dup(Stack *s) {
	push(s, top(s));
}

/* ОСНОВНАЯ ПРОГРАММА */
int main(void) {
	int i;
	Stack *s = newStack(3);

	for (i = 0; i < 10; ++i) {
		push(s, i);
		dup(s);
	}
	while (!isEmpty(s)) {
		printf("%d\n", top(s));
		pop(s);
	}

	killStack(s);
	return 0;
}

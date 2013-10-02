#include <stdio.h>
#include "stack.h"

/* Продублировать элемент на вершине стека */
void dupStack(StackPtr s) {
	pushStack(s, topStack(s));
}

/* ОСНОВНАЯ ПРОГРАММА */
int main(void) {
	int i;
	StackPtr s = newStack(3);

	for (i = 0; i < 10; ++i) {
		pushStack(s, i);
		dupStack(s);
	}
	while (!isEmptyStack(s)) {
		printf("%d\n", topStack(s));
		popStack(s);
	}

	deleteStack(s);
	return 0;
}

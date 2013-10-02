#include <stdio.h>
#include "stack.h"

/* Демонстрация работы со стеком.
 * Поместить в стек числа 1, 2, ..., 10,
 * каждое по два раза,
 * после чего извлечь их, выводя на экран */

/* Вспомогательная функция для main() */
/* Продублировать элемент на вершине стека */
void dupStack(StackPtr s) {
	pushStack(s, topStack(s));
}

/* Основная программа */
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

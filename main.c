#include <stdio.h>
#include "stack.h"
#include "queue.h"

/* Демонстрация работы со стеком и очередью.
 * Поместить в стек числа 1, 2, ..., 10,
 * каждое по два раза,
 * после чего извлечь их, выводя на экран.
 * Далее поместить в очередь числа 1, 2, ..., 10,
 * циклически сдвинуть их на 5 и вывести на экран. */

/* Вспомогательная функция для main() */
/* Продублировать элемент на вершине стека */
void dupStack(StackPtr s) {
	pushStack(s, topStack(s));
}

/* Основная программа */
int main(void) {
	int i;
	QueuePtr q = newQueue(3);
	StackPtr s = newStack(3);

	for (i = 0; i < 10; ++i) {
		pushStack(s, i);
		dupStack(s);
	}
	while (!isEmptyStack(s)) {
		printf("%d\n", topStack(s));
		popStack(s);
	}

	printf("\n");
	for (i = 0; i < 10; ++i) {
		enqueue(q, i);
	}
	for (i = 0; i < 5; ++i) {
		enqueue(q, frontQueue(q));
		dequeue(q);
	}
	while (!isEmptyQueue(q)) {
		printf("%d\n", frontQueue(q));
		dequeue(q);
	}

	deleteStack(s);
	deleteQueue(q);
	return 0;
}

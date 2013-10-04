#include <assert.h>
#include <stdlib.h>
#include "queue.h"

/* Реализация очереди на массиве,
 * массив "зациклен" и увеличивается при необходимости */

struct QueueT {
	/* Индекс, указывающий на позицию за хвостовым элементом */
	int back;
	/* Индекс, указывающий на головной элемент */
	int front;
	/* Количество элементов в очереди */
	int size;
	/* Вместимость очереди */
	int capacity;
	/* Массив элементов */
	QueueElemT *d;
};

QueuePtr newQueue(int startCapacity) {
	assert(startCapacity > 0);
	/* Выделить память под структуру очереди */
	QueuePtr res = (QueuePtr)malloc(sizeof(struct QueueT));
	assert(res != NULL);
	/* Выделить память под массив элементов */
	res->d = (QueueElemT*)calloc(startCapacity, sizeof(QueueElemT));
	assert(res->d != NULL);
	/* Инициализировать вместимость очереди */
	res->capacity = startCapacity;
	/* Инициализировать позицию вставки в очередь */
	res->back = 0;
	/* Инициализировать позицию головы очереди */
	res->front = 0;
	/* Инициализировать количество элементов в очереди */
	res->size = 0;
	/* Вернуть указатель на созданную пустую очередь */
	return res;
}

void deleteQueue(QueuePtr q) {
	/* Удалить массив с элементами */
	free(q->d);
	/* Удалить структуру очереди */
	free(q);
}

void clearQueue(QueuePtr q) {
	/* Привести позиции и размер в начальное состояние */
	q->back = 0;
	q->front = 0;
	q->size = 0;
}

int isEmptyQueue(QueuePtr q) {
	return q->size == 0;
}

/* Вспомогательная функция для enqueue() */
/* Очередь заполнена, нет места для нового элемента */
int isFullQueue(QueuePtr q) {
	return q->size == q->capacity;
}

/* Вспомогательная функция для enqueue() */
/* Увеличить допустимый размер очереди в K раз */
#define K 2
void extendQueue(QueuePtr q) {
	int i, j;
	/* Новый размер массива (в байтах) */
	size_t newSize = q->capacity * K * sizeof(QueueElemT);
	/* Расширить массив */
	if (q->front < q->back) {
		/* Если элементы расположены в массиве непрерывно от головы до хвоста,
		 * то просто перераспределить память под новый размер */
		q->d = (QueueElemT*)realloc(q->d, newSize);
		assert(q->d != NULL);
	} else {
		/* Иначе создать новый более вместительный массив */
		QueueElemT *newData = (QueueElemT*)malloc(newSize);
		assert(newData != NULL);
		/* Сначала скопировать в новый массив первую половину элементов,
		 * расположенную от головы очереди до конца старого массива */
		for (i = 0, j = q->front; j < q->capacity; ++i, ++j) {
			newData[i] = q->d[j];
		}
		/* Затем скопировать вторую половину элементов,
		 * расположенную от начала старого массива до хвоста очереди */
		for (j = 0; j < q->back; ++j, ++i) {
			newData[i] = q->d[j];
		}
		/* Удалить старый массив */
		free(q->d);
		/* Установить ссылку на новый массив */
		q->d = newData;
		/* Установить индексы на голову и хвост очереди */
		q->front = 0;
		q->back = q->size;
	}
	/* Увеличить вместимость очереди в K раз */
	q->capacity *= K;
}

/* Вспомогательная функция для enqueue() */
/* Добавить элемент e в очередь */
/* Предусловие: очередь не переполнена! */
void addElementToQueue(QueuePtr q, QueueElemT e) {
	assert(!isFullQueue(q));
	/* Поместить элемент в хвост очереди */
	if (q->back < q->capacity) {
		/* Если элементы будут расположены непрерывно,
		 * то просто добавить элемент в хвост очереди */
		q->d[q->back] = e;
		q->back++;
	} else {
		/* Иначе записать элемент в начало массива
		 * и установить индекс хвоста после него */
		q->d[0] = e;
		q->back = 1;
	}
	/* Увеличить количество элементов */
	q->size++;
}

void enqueue(QueuePtr q, QueueElemT e) {
	/* Расширить массив, если он заполнен */
	if (isFullQueue(q)) {
		extendQueue(q);
	}
	/* Поставить элемент в очередь */
	addElementToQueue(q, e);
}

void dequeue(QueuePtr q) {
	assert(!isEmptyQueue(q));
	/* Переставить индекс головы очереди на следующий элемент */
	q->front++;
	/* Если индекс головы вышел за пределы массива,
	 * то установить его на нулевой элемент */
	if (q->front >= q->capacity) {
		q->front = 0;
	}
	/* Уменьшить количество элементов */
	(q->size)--;
}

QueueElemT frontQueue(QueuePtr q) {
	assert(!isEmptyQueue(q));
	return q->d[q->front];
}

int sizeQueue(QueuePtr q) {
	return q->size;
}

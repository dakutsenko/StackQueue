#include <assert.h>
#include <stdlib.h>
#include <string.h>
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
	QueueItemT *d;
};

QueuePtr newQueue(int startCapacity) {
	/* Выделить память под структуру очереди */
	QueuePtr res = (QueuePtr)malloc(sizeof(struct QueueT));
	assert(res != NULL);
	/* Выделить память под массив элементов */
	assert(startCapacity > 0);
	res->d = (QueueItemT*)calloc(startCapacity, sizeof(QueueItemT));
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

int isEmptyQueue(QueueReadOnlyPtr q) {
	return q->size == 0;
}

/* Вспомогательная функция для enqueue() */
/* Очередь заполнена, нет места для нового элемента */
int isFullQueue(QueueReadOnlyPtr q) {
	return q->size == q->capacity;
}

/* Вспомогательная функция для extendQueue() */
/* Перенести элементы очереди oldQ из старого массива в новый
 * (более вместительный) newData размера newSize, 
 * восстановив при этом непрерывность последовательности,
 * так как в данном случае исходная последовательность разбита
 * на хвостовую и головную части,
 * причём хвостовая часть расположена в начале старого массива,
 * а головная - в конце. */
void copyQueue(QueueReadOnlyPtr oldQ, QueueItemT newData[], int newSize) {
	QueueItemT *oldHeadAddr, *newHeadAddr, *oldTailAddr, *newTailAddr;
	int headOffset, headSize, tailSize;
	assert(oldQ->front >= oldQ->back);
	assert(newSize >= oldQ->capacity);
	/* Смещение головного элемента очереди
	 * относительно начала старого массива */
	headOffset = oldQ->capacity - oldQ->front;
	/* Адрес головы очереди в старом массиве */
	oldHeadAddr = oldQ->d + oldQ->front;
	/* Адрес головы очереди в новом массиве */
	newHeadAddr = newData;
	/* Размер в байтах головной части очереди:
	 * от головного элемента до конца старого массива */
	headSize = headOffset * sizeof(QueueItemT);
	/* Адрес начала хвостовой части очереди в старом массиве */
	oldTailAddr = oldQ->d;
	/* Адрес начала хвостовой части очереди в новом массиве */
	newTailAddr = newData + headOffset;
	/* Размер в байтах хвостовой части очереди:
	 * от начала старого массива до хвостового элемента */
	tailSize = oldQ->back * sizeof(QueueItemT);
	/* Скопировать в новый массив головную часть элементов */
	memcpy(newHeadAddr, oldHeadAddr, headSize);
	/* Скопировать в новый массив хвостовую часть элементов */
	memcpy(newTailAddr, oldTailAddr, tailSize);
}

/* Вспомогательная функция для enqueue() */
/* Увеличить допустимый размер очереди в K раз */
#define K 2
void extendQueue(QueuePtr q) {
	/* Новый размер массива (в байтах) */
	size_t newSize = q->capacity * K * sizeof(QueueItemT);
	/* Расширить массив */
	if (q->front < q->back) {
		/* Если элементы расположены в массиве непрерывно от головы до хвоста,
		 * то просто перераспределить память массива под новый размер */
		q->d = (QueueItemT*)realloc(q->d, newSize);
		assert(q->d != NULL);
	} else {
		/* Иначе создать более вместительный новый массив */
		QueueItemT *newData = (QueueItemT*)malloc(newSize);
		assert(newData != NULL);
		/* Перенести элементы очереди из старого массива в новый, 
		 * восстановив при этом непрерывность последовательности */
		copyQueue(q, newData, newSize);
		/* Удалить старый массив */
		free(q->d);
		/* Установить ссылку на новый массив очереди */
		q->d = newData;
		/* Установить индексы на головной и хвостовой элементы очереди */
		q->front = 0;
		q->back = q->size;
	}
	/* Увеличить значение вместимости очереди в K раз */
	q->capacity *= K;
}

/* Вспомогательная функция для enqueue() */
/* Добавить элемент e в очередь */
/* Предусловие: очередь не переполнена! */
void addItemToQueue(QueuePtr q, QueueItemT e) {
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

void enqueue(QueuePtr q, QueueItemT e) {
	/* Расширить массив, если он заполнен */
	if (isFullQueue(q)) {
		extendQueue(q);
	}
	/* Поставить элемент в очередь */
	addItemToQueue(q, e);
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
	q->size--;
}

QueueItemT frontQueue(QueueReadOnlyPtr q) {
	assert(!isEmptyQueue(q));
	return q->d[q->front];
}

int sizeQueue(QueueReadOnlyPtr q) {
	return q->size;
}

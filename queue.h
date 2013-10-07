#ifndef QUEUE_H
#define QUEUE_H
/* Модуль для работы с очередью */

/* Базовый тип элементов очереди */
typedef int QueueItemT;

/* Тип данных "Очередь",
 * реализация скрыта, доступ через указатель */
struct QueueT;
typedef struct QueueT *QueuePtr;
typedef const struct QueueT *QueueReadOnlyPtr;

/* Создать новую очередь с начальной вместимостью startCapacity */
/* Предусловие: startCapacity > 0 */
QueuePtr newQueue(int startCapacity);

/* Уничтожить очередь */
void deleteQueue(QueuePtr q);

/* Очистить очередь, сделать её пустой */
void clearQueue(QueuePtr q);

/* Очередь пуста */
int isEmptyQueue(QueueReadOnlyPtr q);

/* Добавить новый элемент e в хвост очереди */
void enqueue(QueuePtr q, QueueItemT e);

/* Удалить элемент из головы очереди */
/* Предусловие: очередь не пуста! */
void dequeue(QueuePtr q);

/* Головной элемент очереди */
/* Предусловие: очередь не пуста! */
QueueItemT frontQueue(QueueReadOnlyPtr q);

/* Количество элементов в очереди */
int sizeQueue(QueueReadOnlyPtr q);

#endif /* QUEUE_H */

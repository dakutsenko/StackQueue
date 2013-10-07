#ifndef STACK_H
#define STACK_H
/* Модуль для работы со стеком */

/* Базовый тип элементов стека */
typedef int StackItemT;

/* Тип данных "Стек магазинного типа", 
 * реализация скрыта, доступ через указатель */
struct StackT;
typedef struct StackT* StackPtr;
typedef const struct StackT* StackReadOnlyPtr;

/* Создать новый стек с начальной вместимостью startCapacity */
/* Предусловие: startCapacity > 0 */
StackPtr newStack(int startCapacity);

/* Уничтожить стек */
void deleteStack(StackPtr s);

/* Очистить стек, сделать его пустым */
void clearStack(StackPtr s);

/* Стек пуст */
int isEmptyStack(StackReadOnlyPtr s);

/* Добавить в стек новый элемент e */
void pushStack(StackPtr s, StackItemT e);

/* Элемент из вершины стека */
/* Предусловие: стек не пуст! */
StackItemT topStack(StackReadOnlyPtr s);

/* Удалить верхний элемент из стека */
/* Предусловие: стек не пуст! */
void popStack(StackPtr s);

/* Количество элементов в стеке */
int sizeStack(StackReadOnlyPtr s);

#endif /* STACK_H */

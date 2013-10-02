#ifndef STACK_H
#define STACK_H
/* Модуль для работы со стеком */

/* Базовый тип элементов стека */
typedef int StackElemT;

/* Тип данных "Стек магазинного типа", 
 * реализация скрыта, доступ через указатель */
struct Stack;
typedef struct Stack *StackPtr;

/* Создать новый стек с начальной вместимостью startCapacity */
/* Предусловие: startCapacity > 0 */
StackPtr newStack(int startCapacity);

/* Уничтожить стек */
void deleteStack(StackPtr s);

/* Очистить стек */
void clearStack(StackPtr s);

/* Стек пуст */
int isEmptyStack(StackPtr s);

/* Добавить в стек новый элемент e */
/* Предусловие: стек не переполнен! */
void pushStack(StackPtr s, StackElemT e);

/* Элемент из вершины стека */
/* Предусловие: стек не пуст! */
StackElemT topStack(StackPtr s);

/* Удалить верхний элемент из стека */
/* Предусловие: стек не пуст! */
void popStack(StackPtr s);

/* Количество элементов в стеке */
int sizeStack(StackPtr s);

#endif /* STACK_H */

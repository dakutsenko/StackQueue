#ifndef STACK_H
#define STACK_H

/* МОДУЛЬ ДЛЯ РАБОТЫ СО СТЕКОМ */

/* Базовый тип элементов стека */
typedef int ElemT;

/* Тип данных "Стек магазинного типа", реализация скрыта */
typedef struct Stack Stack;

/* Создать новый стек с начальной вместимостью startCapacity */
Stack *newStack(int startCapacity);

/* Уничтожить стек */
void killStack(Stack *s);

/* Очистить стек */
void clear(Stack *s);

/* Стек пуст */
int isEmpty(Stack *s);

/* Добавить в стек новый элемент e */
/* ПРЕДУСЛОВИЕ: стек не переполнен! */
void push(Stack *s, ElemT e);

/* Элемент из вершины стека */
/* ПРЕДУСЛОВИЕ: стек не пуст! */
ElemT top(Stack *s);

/* Удалить верхний элемент из стека */
/* ПРЕДУСЛОВИЕ: стек не пуст! */
void pop(Stack *s);

/* Количество элементов в стеке */
int size(Stack *s);

#endif /* STACK_H */

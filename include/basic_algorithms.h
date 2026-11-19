#ifndef BASIC_ALGORITHMS_H
#define BASIC_ALGORITHMS_H

// Структура одной ячейки списка
struct Cell {
    int Value;
    Cell* Next;
};

// Создание пустого списка
void CreateListWithBottom(Cell*& top, Cell*& bottom);

// Добавление элемента в начало
void AddAtBeginning(Cell*& top, Cell*& bottom, int value);

// Добавление элемента в конец
void AddAtEndWithBottom(Cell*& top, Cell*& bottom, int value);

// Перебор и вывод списка
void Iterate(Cell* top);

// Поиск ячейки по значению
Cell* FindCell(Cell* top, int target);

// Поиск ячейки перед заданной
Cell* FindCellBefore(Cell* top, int target);

// Вставка элемента после заданной ячейки
void InsertCell(Cell*& top, Cell*& bottom,
                Cell* after_me, int value);

// Удаление ячейки после заданной
bool DeleteAfter(Cell* after_me, Cell*& bottom);

// Удаление всего списка
void DestroyList(Cell*& top, Cell*& bottom);

#endif

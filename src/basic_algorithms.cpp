#include "basic_algorithms.h"
#include <iostream>
using namespace std;

// Создание пустого списка
void CreateListWithBottom(Cell*& top, Cell*& bottom) {
    top = nullptr;
    bottom = nullptr;
}

// Добавление элемента в начало
void AddAtBeginning(Cell*& top, Cell*& bottom, int value) {
    Cell* new_cell = new Cell;

    new_cell->Value = value;
    new_cell->Next = top;

    top = new_cell;

    // Если список был пустым
    if (bottom == nullptr) {
        bottom = new_cell;
    }
}

// Добавление элемента в конец
void AddAtEndWithBottom(Cell*& top, Cell*& bottom, int value) {
    Cell* new_cell = new Cell;

    new_cell->Value = value;
    new_cell->Next = nullptr;

    // Если список пустой
    if (top == nullptr) {
        top = new_cell;
        bottom = new_cell;
    }
    else {
        bottom->Next = new_cell;
        bottom = new_cell;
    }
}

// Перебор и вывод списка
void Iterate(Cell* top) {
    while (top != nullptr) {
        cout << top->Value << " ";
        top = top->Next;
    }

    cout << '\n';
}

// Поиск ячейки по значению
Cell* FindCell(Cell* top, int target) {
    while (top != nullptr) {
        if (top->Value == target) {
            return top;
        }

        top = top->Next;
    }

    return nullptr;
}

// Поиск ячейки перед заданной
Cell* FindCellBefore(Cell* top, int target) {
    while (top != nullptr && top->Next != nullptr) {
        if (top->Next->Value == target) {
            return top;
        }

        top = top->Next;
    }

    return nullptr;
}

// Вставка элемента после заданной ячейки
void InsertCell(Cell*& top, Cell*& bottom,
                Cell* after_me, int value) {

    Cell* new_cell = new Cell;

    new_cell->Value = value;

    // Если вставляем в начало
    if (after_me == nullptr) {
        new_cell->Next = top;
        top = new_cell;

        if (bottom == nullptr) {
            bottom = new_cell;
        }

        return;
    }

    // Вставляем после заданной ячейки
    new_cell->Next = after_me->Next;
    after_me->Next = new_cell;

    // Если вставили в конец
    if (bottom == after_me) {
        bottom = new_cell;
    }
}

// Удаление ячейки после заданной
bool DeleteAfter(Cell* after_me, Cell*& bottom) {
    if (after_me == nullptr || after_me->Next == nullptr) {
        return false;
    }

    Cell* target_cell = after_me->Next;

    after_me->Next = target_cell->Next;

    // Если удаляем последнюю ячейку
    if (bottom == target_cell) {
        bottom = after_me;
    }

    delete target_cell;

    return true;
}

// Удаление всего списка
void DestroyList(Cell*& top, Cell*& bottom) {
    while (top != nullptr) {
        Cell* next_cell = top->Next;

        delete top;

        top = next_cell;
    }

    bottom = nullptr;
}

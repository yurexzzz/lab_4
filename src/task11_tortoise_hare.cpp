
#include <iostream>
using namespace std;

// Структура ячейки списка
struct Cell {
    int Value;
    Cell* Next;
};

// Добавление элемента в конец списка
void AddAtEnd(Cell*& top, Cell*& bottom, int value) {
    Cell* new_cell = new Cell;

    new_cell->Value = value;
    new_cell->Next = nullptr;

    if (top == nullptr) {
        top = new_cell;
        bottom = new_cell;
    }
    else {
        bottom->Next = new_cell;
        bottom = new_cell;
    }
}

// Вывод списка
void PrintList(Cell* top) {
    while (top != nullptr) {
        cout << top->Value << " ";
        top = top->Next;
    }

    cout << '\n';
}

// Поиск начала цикла и его удаление
Cell* FindCycleAndBreak(Cell* top) {
    Cell* tortoise = top;
    Cell* hare = top;

    // Первый этап: поиск цикла
    while (hare != nullptr && hare->Next != nullptr) {

        tortoise = tortoise->Next;
        hare = hare->Next->Next;

        // Если указатели встретились, цикл существует
        if (tortoise == hare) {
            break;
        }
    }

    // Если кролик дошел до конца, цикла нет
    if (hare == nullptr || hare->Next == nullptr) {
        return nullptr;
    }

    // Второй этап: поиск начала цикла
    hare = top;

    while (hare != tortoise) {
        hare = hare->Next;
        tortoise = tortoise->Next;
    }

    // Сохраняем начало цикла
    Cell* cycleStart = hare;

    // Третий этап: находим последнюю ячейку цикла
    while (tortoise->Next != hare) {
        tortoise = tortoise->Next;
    }

    // Разрываем цикл
    tortoise->Next = nullptr;

    return cycleStart;
}

// Удаление всего списка
void DestroyList(Cell* top) {
    while (top != nullptr) {
        Cell* next_cell = top->Next;
        delete top;
        top = next_cell;
    }
}

int main() {
    Cell* top = nullptr;
    Cell* bottom = nullptr;

    int n;

    cout << "Введите количество элементов: ";
    cin >> n;

    if (!cin || n < 0) {
        cout << "Неверное количество элементов\n";
        return 1;
    }

    // Создаем список
    for (int i = 0; i < n; i++) {
        int value;

        cout << "Введите значение: ";
        cin >> value;

        if (!cin) {
            DestroyList(top);
            cout << "Ошибка ввода\n";
            return 1;
        }

        AddAtEnd(top, bottom, value);
    }

    cout << "\nИсходный список: ";
    PrintList(top);

    int cyclePosition;

    cout << "\nВведите номер ячейки, с которой начинается цикл "
         << "(0 - без цикла): ";
    cin >> cyclePosition;

    if (!cin || cyclePosition < 0 || cyclePosition > n) {
        DestroyList(top);
        cout << "Неверный номер ячейки\n";
        return 1;
    }

    // Создаем цикл, если пользователь указал номер ячейки
    if (cyclePosition != 0) {
        Cell* current = top;

        for (int i = 1; i < cyclePosition; i++) {
            current = current->Next;
        }

        bottom->Next = current;
    }

    // Ищем цикл и разрываем его
    Cell* cycleStart = FindCycleAndBreak(top);

    if (cycleStart != nullptr) {
        cout << "\nЦикл обнаружен!\n";
        cout << "Начало цикла: " << cycleStart->Value << '\n';
    }
    else {
        cout << "\nЦикл не обнаружен!\n";
    }

    cout << "\nСписок после удаления цикла: ";
    PrintList(top);

    DestroyList(top);

    return 0;
}

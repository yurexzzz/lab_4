#include <iostream>

#include "basic_algorithms.h"
using namespace std;

int main() {
  Cell* top;
  Cell* bottom;

  // Создаем пустой список
  CreateListWithBottom(top, bottom);

  // Добавляем элементы в конец
  AddAtEndWithBottom(top, bottom, 10);
  AddAtEndWithBottom(top, bottom, 20);
  AddAtEndWithBottom(top, bottom, 30);

  cout << "Начальный список: ";
  Iterate(top);

  // Добавляем элемент в начало
  AddAtBeginning(top, bottom, 5);

  cout << "После добавления в начало: ";
  Iterate(top);

  // Ищем элемент
  Cell* found = FindCell(top, 20);

  if (found != nullptr) {
    cout << "Найден элемент: " << found->Value << '\n';
  }

  // Вставляем 25 после 20
  InsertCell(top, bottom, found, 25);

  cout << "После вставки 25: ";
  Iterate(top);

  // Находим ячейку перед 25
  Cell* before = FindCellBefore(top, 25);

  // Удаляем 25
  if (DeleteAfter(before, bottom)) {
    cout << "После удаления 25: ";
    Iterate(top);
  }

  // Удаляем весь список
  DestroyList(top, bottom);

  cout << "После удаления всего списка: ";
  Iterate(top);

  return 0;
}

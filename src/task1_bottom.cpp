
#include <iostream>

struct Node {
  int value;
  Node* next;
};

struct List {
  Node* top;
  Node* bottom;
};

// Добавление элемента в конец списка за O(1)
void addAtEnd(List& list, int value) {
  Node* newCell = new Node{value, nullptr};

  if (list.top == nullptr) {
    list.top = newCell;
    list.bottom = newCell;
  } else {
    list.bottom->next = newCell;
    list.bottom = newCell;
  }
}

// Удаление элемента по значению
bool deleteCell(List& list, int value) {
  Node* current = list.top;
  Node* previous = nullptr;

  // Ищем нужную ячейку
  while (current != nullptr && current->value != value) {
    previous = current;
    current = current->next;
  }

  // Если элемент не найден
  if (current == nullptr) {
    return false;
  }

  // Если удаляем первый элемент
  if (previous == nullptr) {
    list.top = current->next;
  } else {
    previous->next = current->next;
  }

  // Если удаляем последний элемент
  if (current == list.bottom) {
    list.bottom = previous;
  }

  delete current;

  return true;
}

// Вывод списка
void printList(const List& list) {
  Node* current = list.top;

  while (current != nullptr) {
    std::cout << current->value << " ";
    current = current->next;
  }

  std::cout << std::endl;
}

// Освобождение памяти
void destroyList(List& list) {
  while (list.top != nullptr) {
    Node* nextCell = list.top->next;
    delete list.top;
    list.top = nextCell;
  }

  list.bottom = nullptr;
}

int main() {
  List list = {nullptr, nullptr};

  addAtEnd(list, 10);
  addAtEnd(list, 20);
  addAtEnd(list, 30);

  std::cout << "Начальный список: ";
  printList(list);

  deleteCell(list, 20);

  std::cout << "После удаления 20: ";
  printList(list);

  deleteCell(list, 30);

  std::cout << "После удаления 30: ";
  printList(list);

  destroyList(list);

  return 0;
}

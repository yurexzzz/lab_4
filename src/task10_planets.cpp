
#include <iostream>
#include <string>
using namespace std;

// Структура планеты
struct Planet {
    string Name;
    double DistanceToSun;
    double Mass;
    double Diameter;

    Planet* NextDistance = nullptr;
    Planet* NextMass = nullptr;
    Planet* NextDiameter = nullptr;
};

// Добавление планеты в три списка
void AddPlanetToList(Planet*& topDistance,
                     Planet*& topMass,
                     Planet*& topDiameter,
                     Planet* newPlanet) {

    // Добавление по расстоянию до Солнца
    Planet* current = topDistance;
    Planet* previous = nullptr;

    while (current != nullptr &&
           current->DistanceToSun < newPlanet->DistanceToSun) {
        previous = current;
        current = current->NextDistance;
    }

    newPlanet->NextDistance = current;

    if (previous == nullptr)
        topDistance = newPlanet;
    else
        previous->NextDistance = newPlanet;


    // Добавление по массе
    current = topMass;
    previous = nullptr;

    while (current != nullptr && current->Mass < newPlanet->Mass) {
        previous = current;
        current = current->NextMass;
    }

    newPlanet->NextMass = current;

    if (previous == nullptr)
        topMass = newPlanet;
    else
        previous->NextMass = newPlanet;


    // Добавление по диаметру
    current = topDiameter;
    previous = nullptr;

    while (current != nullptr &&
           current->Diameter < newPlanet->Diameter) {
        previous = current;
        current = current->NextDiameter;
    }

    newPlanet->NextDiameter = current;

    if (previous == nullptr)
        topDiameter = newPlanet;
    else
        previous->NextDiameter = newPlanet;
}

// Вывод по расстоянию
void PrintByDistance(Planet* top) {
    while (top != nullptr) {
        cout << top->Name << " - " << top->DistanceToSun << '\n';
        top = top->NextDistance;
    }
}

// Вывод по массе
void PrintByMass(Planet* top) {
    while (top != nullptr) {
        cout << top->Name << " - " << top->Mass << '\n';
        top = top->NextMass;
    }
}

// Вывод по диаметру
void PrintByDiameter(Planet* top) {
    while (top != nullptr) {
        cout << top->Name << " - " << top->Diameter << '\n';
        top = top->NextDiameter;
    }
}

// Удаление всего списка
void DestroyList(Planet* top) {
    while (top != nullptr) {
        Planet* next = top->NextDistance;
        delete top;
        top = next;
    }
}

int main() {
    Planet* topDistance = nullptr;
    Planet* topMass = nullptr;
    Planet* topDiameter = nullptr;

    int n;

    cout << "Введите количество планет: ";
    cin >> n;

    if (!cin || n < 0) {
        cout << "Неверное количество планет\n";
        return 1;
    }

    // Ввод планет
    for (int i = 0; i < n; i++) {
        Planet* p = new Planet;

        cout << "\nНазвание планеты: ";
        cin >> p->Name;

        cout << "Расстояние до Солнца: ";
        cin >> p->DistanceToSun;

        cout << "Масса: ";
        cin >> p->Mass;

        cout << "Диаметр: ";
        cin >> p->Diameter;

        if (!cin) {
            delete p;
            DestroyList(topDistance);
            cout << "Ошибка ввода\n";
            return 1;
        }

        AddPlanetToList(topDistance, topMass, topDiameter, p);
    }

    int choice = -1;

    while (choice != 0) {
        cout << "\n1. По расстоянию до Солнца\n";
        cout << "2. По массе\n";
        cout << "3. По диаметру\n";
        cout << "0. Выход\n";
        cout << "Ваш выбор: ";

        cin >> choice;

        switch (choice) {
        case 1:
            PrintByDistance(topDistance);
            break;

        case 2:
            PrintByMass(topMass);
            break;

        case 3:
            PrintByDiameter(topDiameter);
            break;

        case 0:
            cout << "Выход\n";
            break;

        default:
            cout << "Неверный выбор\n";
        }
    }

    DestroyList(topDistance);

    return 0;
}

#include "List.h"
#include <iostream>
#include <cstring>
using namespace std;

struct Person {
    char name[20];
    int age;
    Person* next;
};

Object Create() {
    return Object();
}

void print(void* b) {
    Person* a = (Person*)b;
    cout << a->name << "  " << a->age << endl;
}

int main() {
    Object L1 = Create();
    bool running = true;

    while (running) {
        cout << "Меню:\n";
        cout << "1. Добавить элемент\n";
        cout << "2. Удалить список\n";
        cout << "3. Подсчитать количество элементов в списке\n";
        cout << "4. Выйти\n";
        cout << "Выберите действие: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "Введите имя: ";
            char name[20];
            cin >> name;
            cout << "Введите возраст: ";
            int age;
            cin >> age;
            Person* p = new Person;
            strcpy_s(p->name, sizeof(p->name), name);
            p->age = age;
            p->next = nullptr;
            L1.Insert(p);
            break;
        }
        case 2: {
            L1.DeleteList();
            cout << "Список удалён.\n";
            break;
        }
        case 3: {
            cout << "Количество элементов в списке: " << L1.CountList() << endl;
            break;
        }
        case 4: {
            running = false;
            break;
        }
        default: {
            cout << "Некорректный ввод.\n";
            break;
        }
        }
    }

    return 0;
}

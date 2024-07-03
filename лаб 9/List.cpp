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
        cout << "����:\n";
        cout << "1. �������� �������\n";
        cout << "2. ������� ������\n";
        cout << "3. ���������� ���������� ��������� � ������\n";
        cout << "4. �����\n";
        cout << "�������� ��������: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "������� ���: ";
            char name[20];
            cin >> name;
            cout << "������� �������: ";
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
            cout << "������ �����.\n";
            break;
        }
        case 3: {
            cout << "���������� ��������� � ������: " << L1.CountList() << endl;
            break;
        }
        case 4: {
            running = false;
            break;
        }
        default: {
            cout << "������������ ����.\n";
            break;
        }
        }
    }

    return 0;
}

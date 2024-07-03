#include <iostream>
#include <windows.h>

using namespace std;

struct Address {
    string name;
    string city;
    Address* next;
};

void insert(Address* address, Address** phead, Address** plast) {
    if (*plast) {
        (*plast)->next = address;
        *plast = address;
    }
    else {
        *phead = *plast = address;
    }
}

void deleteKFirst(int k, Address** phead, Address** plast) {
    if (*phead == nullptr) {
        cout << "Список пуст!" << endl;
        return;
    }

    while (k > 0 && *phead != nullptr) {
        Address* temp = *phead;
        *phead = (*phead)->next;
        delete temp;
        k--;
    }

    if (*phead == nullptr) {
        *plast = nullptr; //указатель на последний элемент
    }
}

void writeToFile(Address** phead) {
    Address* t = *phead;
    FILE* fp;
    int err = fopen_s(&fp, "mlist", "wb");
    if (err != 0) {
        cerr << "Файл не открывается" << endl;
        exit(1);
    }
    cout << "Сохранение в файл" << endl;
    while (t) {
        fwrite(t, sizeof(Address), 1, fp);
        t = t->next;
    }
    fclose(fp);
}

void readFromFile(Address** phead, Address** plast) {
    Address* t;
    FILE* fp;
    int err = fopen_s(&fp, "mlist", "rb");
    if (err != 0) {
        cerr << "Файл не открывается" << endl;
        exit(1);
    }
    while (*phead) {
        *plast = (*phead)->next;
        delete* phead;
        *phead = *plast;
    }
    *phead = *plast = NULL;
    cout << "Загрузка из файла" << endl;
    while (!feof(fp)) {
        t = new Address();
        if (!t) {
            cerr << "Ошибка выделения памяти" << endl;
            return;
        }
        if (1 != fread(t, sizeof(Address), 1, fp))
            break;
        insert(t, phead, plast);
    }
    fclose(fp);
}

int main() {
    setlocale(LC_ALL, "rus");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    Address* phead = nullptr;
    Address* plast = nullptr;

    int choice;
    cout << "Выберите действие:" << endl;
    cout << "1. Добавить новый элемент" << endl;
    cout << "2. Удалить элемент по значению" << endl;
    cout << "3. Удалить первые K элементов" << endl; //задание
    cout << "4. Сохранить в файл" << endl;
    cout << "5. Загрузить из файла" << endl;
    cout << "6. Выйти" << endl;
    cout << "Введите номер действия: ";
    cin >> choice;

    switch (choice) {
    case 1:
        break;
    case 2:
        break;
    case 3:
        int k;
        cout << "Введите количество элементов для удаления: ";
        cin >> k;
        deleteKFirst(k, &phead, &plast);
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    default:
        cout << "Некорректный выбор. Пожалуйста, выберите существующее действие." << endl;
    }

    return 0;
}

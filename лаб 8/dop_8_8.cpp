#include <iostream>
#include <queue>
#include <windows.h>
using namespace std;

void inputQueue(queue<int>& q, int size) {
    int num;
    cout << "Введите " << size << " чисел для добавления в очередь:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "Число " << i + 1 << ": ";
        cin >> num;
        q.push(num);
    }
}

void displayQueue(queue<int> q) {
    cout << "Содержимое очереди: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int queueSize(queue<int> q) {
    return q.size();
}

// Функция для удаления первого отрицательного элемента из очереди
void deleteFirstNegative(queue<int>& q) {
    queue<int> temp;
    bool negativeFound = false;

    while (!q.empty()) {
        int front = q.front();
        q.pop();
        if (!negativeFound && front < 0) {
            negativeFound = true;
            continue;
        }
        temp.push(front);
    }

    while (!temp.empty()) {
        q.push(temp.front());
        temp.pop();
    }

    if (!negativeFound) {
        cout << "В очереди нет отрицательных элементов." << endl;
    }
    else {
        cout << "Первый отрицательный элемент удален из очереди." << endl;
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int maxSize;
    cout << "Введите максимальный размер очереди: ";
    cin >> maxSize;

    queue<int> q;
    inputQueue(q, maxSize);

    int choice;
    do {
        cout << "\nМеню:" << endl;
        cout << "1. Вывести содержимое очереди" << endl;
        cout << "2. Определить размер очереди" << endl;
        cout << "3. Удалить первый отрицательный элемент из очереди" << endl;
        cout << "4. Выйти" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            displayQueue(q);
            break;
        case 2:
            cout << "Размер очереди: " << queueSize(q) << endl;
            break;
        case 3:
            deleteFirstNegative(q);
            break;
        case 4:
            cout << "Программа завершена." << endl;
            break;
        default:
            cout << "Некорректный выбор. Пожалуйста, выберите существующее действие." << endl;
        }
    } while (choice != 4);

    return 0;
}

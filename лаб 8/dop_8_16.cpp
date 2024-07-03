#include <iostream>
#include <queue>
#include <windows.h>

using namespace std;

// Функция для ввода элементов в очередь
void inputQueue(queue<int>& q, int size) {
    int num;
    cout << "Введите " << size << " чисел для добавления в очередь:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "Число " << i + 1 << ": ";
        cin >> num;
        q.push(num);
    }
}

// Функция для вывода содержимого очереди
void displayQueue(queue<int> q) {
    cout << "Содержимое очереди: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

// Функция для разделения очереди на положительные и отрицательные числа
void splitQueue(queue<int>& source, queue<int>& positive, queue<int>& negative) {
    while (!source.empty()) {
        int num = source.front();
        source.pop();
        if (num >= 0)
            positive.push(num);
        else
            negative.push(num);
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int maxSize;
    cout << "Введите максимальный размер очереди: ";
    cin >> maxSize;

    queue<int> originalQueue;
    inputQueue(originalQueue, maxSize);

    int choice;
    do {
        cout << "\nМеню:" << endl;
        cout << "1. Вывести содержимое очереди" << endl;
        cout << "2. Разделить очередь на положительные и отрицательные числа" << endl;
        cout << "3. Выйти" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            displayQueue(originalQueue);
            break;
        case 2: {
            queue<int> positiveQueue, negativeQueue;
            splitQueue(originalQueue, positiveQueue, negativeQueue);

            cout << "Положительные числа из первой очереди:" << endl;
            displayQueue(positiveQueue);

            cout << "Отрицательные числа из первой очереди:" << endl;
            displayQueue(negativeQueue);
            break;
        }
        case 3:
            cout << "Программа завершена." << endl;
            break;
        default:
            cout << "Некорректный выбор. Пожалуйста, выберите существующее действие." << endl;
        }
    } while (choice != 3);

    return 0;
}

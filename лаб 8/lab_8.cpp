#include <iostream>
#include <queue>
#include <climits>
#include <Windows.h>

using namespace std;

// добавления элемента в конец очереди
void enqueue(queue<int>& q, int item) {
    q.push(item);
}

// удаления элемента из начала очереди
void dequeue(queue<int>& q) {
    if (!q.empty()) {
        q.pop();
    }
    else {
        cout << "Очередь пуста. Невозможно выполнить операцию." << endl;
    }
}

// вывод
void displayQueue(queue<int> q) {
    if (q.empty()) {
        cout << "Очередь пуста." << endl;
        return;
    }
    cout << "Содержимое очереди: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

// нахождение количества элементов между максимальным и минимальным
int countBetweenMaxMin(queue<int> q) {
    if (q.empty()) {
        cout << "Очередь пуста. Невозможно выполнить операцию." << endl;
        return 0;
    }

    int minVal = INT_MAX;
    int maxVal = INT_MIN;
    queue<int> temp = q;

    while (!temp.empty()) {
        int current = temp.front();
        temp.pop();
        if (current < minVal) {
            minVal = current;
        }
        if (current > maxVal) {
            maxVal = current;
        }
    }

    // количество элементов между минимальным и максимальным значением
    bool betweenMinMax = false;
    int count = 0;
    temp = q;
    while (!temp.empty()) {
        int current = temp.front();
        temp.pop();
        if (current == minVal || current == maxVal) {
            if (betweenMinMax) {
                break;
            }
            else {
                betweenMinMax = true;
            }
        }
        else if (betweenMinMax) {
            count++;
        }
    }

    // Если между минимальным и максимальным элементами не было найдено других элементов
    if (count == 0 && (minVal != maxVal)) {
        count = -1;
    }

    return count;
}

int main() {
    setlocale(LC_ALL, "rus");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    queue<int> q;
    int choice, item;

    cout << "Введите максимальный размер очереди: ";
    int maxSize;
    cin >> maxSize;

    do {
        cout << "\nВыберите действие:" << endl;
        cout << "1. Добавить элемент в очередь" << endl;
        cout << "2. Удалить элемент из очереди" << endl;
        cout << "3. Вывести содержимое очереди" << endl;
        cout << "4. Найти количество элементов между максимальным и минимальным элементами очереди" << endl;
        cout << "5. Выйти" << endl;
        cout << "Введите номер действия: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (q.size() < maxSize) {
                cout << "Введите элемент для добавления: ";
                cin >> item;
                enqueue(q, item);
            }
            else {
                cout << "Очередь достигла максимального размера." << endl;
            }
            break;
        case 2:
            dequeue(q);
            break;
        case 3:
            displayQueue(q);
            break;
        case 4:
            cout << "Количество элементов между максимальным и минимальным элементами очереди: " << countBetweenMaxMin(q) << endl;
            break;
        case 5:
            cout << "Программа завершена." << endl;
            break;
        default:
            cout << "Некорректный выбор. Пожалуйста, выберите существующее действие." << endl;
        }
    } while (choice != 5);

    return 0;
}

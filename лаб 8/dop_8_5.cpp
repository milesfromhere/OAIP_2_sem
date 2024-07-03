#include <iostream>
#include <queue>
#include <Windows.h>

using namespace std;

void inputQueue(queue<char>& q, int size) {
    char ch;
    cout << "Введите " << size << " символов для добавления в очередь:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "Символ " << i + 1 << ": ";
        cin >> ch;
        q.push(ch);
        ///удалени первого после пятого
        if (i == 4) {
            q.pop();
            cout << "Первый элемент удален из очереди." << endl;
        }
    }
}

void displayQueue(queue<char> q) {
    cout << "Содержимое очереди: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "rus");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int maxSize;
    cout << "Введите максимальный размер очереди: ";
    cin >> maxSize;

    queue<char> q;
    inputQueue(q, maxSize);

    int choice;
    do {
        cout << "\nМеню:" << endl;
        cout << "1. Вывести содержимое очереди" << endl;
        cout << "2. Выйти" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Очередь после ввода и удаления элементов:" << endl;
            displayQueue(q);
            break;
        case 2:
            cout << "Программа завершена." << endl;
            break;
        default:
            cout << "Некорректный выбор. Пожалуйста, выберите существующее действие." << endl;
        }
    } while (choice != 2);

    return 0;
}

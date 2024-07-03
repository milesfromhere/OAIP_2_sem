#include<iostream>
using namespace std;

struct Item {
    int data;
    Item* next;
};

Item* head = nullptr;
Item* tail = nullptr;

bool isEmpty() {
    return (head == nullptr);
}

void dequeue() {
    if (isEmpty())
        cout << "Очередь пуста" << endl;
    else {
        Item* temp = head;
        head = head->next;
        delete temp;
    }
}

void enqueue(int x) {
    Item* newItem = new Item;
    newItem->data = x;
    newItem->next = nullptr;

    if (isEmpty())
        head = tail = newItem;
    else {
        Item* prev = nullptr;
        Item* current = head;

        while (current != nullptr && current->data < x) {
            prev = current;
            current = current->next;
        }

        if (prev == nullptr) {
            newItem->next = head;
            head = newItem;
        }
        else if (current == nullptr) {
            tail->next = newItem;
            tail = newItem;
        }
        else {
            prev->next = newItem;
            newItem->next = current;
        }
    }
}

void printQueue() {
    if (isEmpty())
        cout << "Очередь пуста" << endl;
    else {
        cout << "Очередь: ";
        Item* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
}

void clearQueue() {
    while (!isEmpty())
        dequeue();
}

int main() {
    setlocale(LC_CTYPE, "Russian");
    int choice = 1, x;

    while (choice != 0) {
        cout << "1 - добавить элемент" << endl;
        cout << "2 - извлечь элемент" << endl;
        cout << "3 - вывести элементы" << endl;
        cout << "4 - очистить очередь" << endl;
        cout << "0 - выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введите элемент: ";
            cin >> x;
            enqueue(x);
            printQueue();
            break;
        case 2:
            dequeue();
            printQueue();
            break;
        case 3:
            printQueue();
            break;
        case 4:
            clearQueue();
            cout << "Очередь очищена" << endl;
            break;
        case 0:
            break;
        default:
            cout << "Неверный выбор. Попробуйте еще раз." << endl;
            break;
        }
    }

    return 0;
}

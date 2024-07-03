#include <iostream>
#include <fstream>
#include <windows.h>

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void addElement(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        std::cout << "Элемент добавлен.\n";
    }

    void deleteElement(int value) {
        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr && current->data != value) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            std::cout << "Элемент не найден.\n";
            return;
        }

        if (prev == nullptr) {
            head = current->next;
        }
        else {
            prev->next = current->next;
        }

        delete current;
        std::cout << "Элемент удален.\n";
    }

    void searchElement(int value) {
        Node* current = head;

        while (current != nullptr && current->data != value) {
            current = current->next;
        }

        if (current == nullptr) {
            std::cout << "Элемент не найден.\n";
        }
        else {
            std::cout << "Элемент найден.\n";
        }
    }

    void displayList() {
        Node* current = head;

        if (current == nullptr) {
            std::cout << "Список пуст.\n";
            return;
        }

        std::cout << "Элементы списка:\n";
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << "\n";
    }

    void writeToFile(const std::string& filename) {
        std::ofstream file(filename);

        if (!file.is_open()) {
            std::cout << "Не удалось открыть файл.\n";
            return;
        }

        Node* current = head;

        while (current != nullptr) {
            file << current->data << " ";
            current = current->next;
        }

        file.close();
        std::cout << "Список записан в файл.\n";
    }

    void readFromFile(const std::string& filename) {
        std::ifstream file(filename);

        if (!file.is_open()) {
            std::cout << "Не удалось открыть файл.\n";
            return;
        }

        int value;
        while (file >> value) {
            addElement(value);
        }

        file.close();
        std::cout << "Список считан из файла.\n";
    }

    void sumOfNegativeTwoDigitElements() {
        Node* current = head;
        int sum = 0;

        while (current != nullptr) {
            if (current->data < 0 && current->data >= -99 && current->data <= -10) {
                sum += current->data;
            }
            current = current->next;
        }

        if (sum != 0) {
            std::cout << "Сумма отрицательных двузначных элементов: " << sum << "\n";
        }
        else {
            std::cout << "Нет отрицательных двузначных элементов.\n";
        }
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    LinkedList list;
    int choice, value;
    std::string filename;

    do {
        std::cout << "\nМеню:\n";
        std::cout << "1. Добавить элемент\n";
        std::cout << "2. Удалить элемент\n";
        std::cout << "3. Найти элемент\n";
        std::cout << "4. Вывести список\n";
        std::cout << "5. Записать в файл\n";
        std::cout << "6. Считать из файла\n";
        std::cout << "7. Найти сумму отрицательных двузначных элементов\n";
        std::cout << "8. Выход\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Введите значение элемента: ";
            std::cin >> value;
            list.addElement(value);
            break;
        case 2:
            std::cout << "Введите значение элемента для удаления: ";
            std::cin >> value;
            list.deleteElement(value);
            break;
        case 3:
            std::cout << "Введите значение элемента для поиска: ";
            std::cin >> value;
            list.searchElement(value);
            break;
        case 4:
            list.displayList();
            break;
        case 5:
            std::cout << "Введите имя файла: ";
            std::cin >> filename;
            list.writeToFile(filename);
            break;
        case 6:
            std::cout << "Введите имя файла: ";
            std::cin >> filename;
            list.readFromFile(filename);
            break;
        case 7:
            list.sumOfNegativeTwoDigitElements();
            break;
        case 8:
            std::cout << "Программа завершена.\n";
            break;
        default:
            std::cout << "Некорректный выбор. Повторите попытку.\n";
            break;
        }
    } while (choice != 8);

    return 0;
}

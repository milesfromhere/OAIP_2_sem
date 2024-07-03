#include <iostream>
#include <fstream>
#include <list>
#include <windows.h>
struct Node {
    double data;
    Node* next;

    Node(double value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void addElement(double value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        std::cout << "Элемент добавлен.\n";
    }

    void deleteElement(double value) {
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

    void searchElement(double value) {
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

        double value;
        while (file >> value) {
            addElement(value);
        }

        file.close();
        std::cout << "Список считан из файла.\n";
    }

    double sumOfElementsLessThan9() {
        Node* current = head;
        double sum = 0;

        while (current != nullptr) {
            if (current->data < 9) {
                sum += current->data;
            }
            current = current->next;
        }

        return sum;
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    LinkedList list;
    int choice;
    double value;
    std::string filename;

    do {
        std::cout << "\nМеню:\n";
        std::cout << "1. Добавить элемент\n";
        std::cout << "2. Удалить элемент\n";
        std::cout << "3. Найти элемент\n";
        std::cout << "4. Вывести список\n";
        std::cout << "5. Записать в файл\n";
        std::cout << "6. Считать из файла\n";
        std::cout << "7. Найти сумму элементов < 9\n";
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
            std::cout << "Сумма элементов < 9: " << list.sumOfElementsLessThan9() << "\n";
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

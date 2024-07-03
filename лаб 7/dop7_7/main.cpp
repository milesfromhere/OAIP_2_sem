#include <iostream>
#include "stack.h"
#include <windows.h>

int main() {
    setlocale(LC_ALL, "rus");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    Stack stack;
    int choice;
    int data;
    int value;
    const char* fileName = "stack_data.txt";

    do {
        std::cout << "\n1. Добавить элемент\n2. Удалить первый элемент, превышающий значение\n3. Прочитать вершину стека\n4. Очистить стек\n5. Сохранить в файл\n6. Считать из файла\n0. Выйти\n";
        std::cout << "Введите ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Введите элемент для добавления: ";
            std::cin >> data;
            stack.push(data);
            break;
        case 2:
            std::cout << "Введите значение: ";
            std::cin >> value;
            stack.removeFirstAboveValue(value);
            std::cout << "Первый элемент, превышающий значение " << value << ", удален из стека (если такой был)." << std::endl;
            break;
        case 3:
            if (!stack.isEmpty()) {
                std::cout << "Вершина стека: " << stack.peek() << std::endl;
            }
            else {
                std::cout << "Стек пуст." << std::endl;
            }
            break;
        case 4:
            stack.clear();
            std::cout << "Стек очищен." << std::endl;
            break;
        case 5:
            stack.saveToFile(fileName);
            std::cout << "Стек сохранен в файл." << std::endl;
            break;
        case 6:
            stack.readFromFile(fileName);
            std::cout << "Стек считан из файла." << std::endl;
            break;
        case 0:
            std::cout << "Завершение программы." << std::endl;
            break;
        default:
            std::cout << "Некорректный выбор. Пожалуйста, введите снова." << std::endl;
            break;
        }
    } while (choice != 0);

    return 0;
}

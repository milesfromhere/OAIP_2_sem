#include <iostream>
#include "stack.h"
#include <windows.h>

int main() {
    setlocale(LC_ALL, "rus");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    Stack stack1;
    Stack stack2;
    int choice;
    int data;
    const char* fileName1 = "stack1_data.txt";
    const char* fileName2 = "stack2_data.txt";

    do {
        std::cout << "\n1. Добавить элемент в стек 1\n2. Добавить элемент в стек 2\n3. Удалить элементы, входящие только в один из стеков\n4. Сохранить стеки в файлы\n5. Считать стеки из файлов\n0. Выйти\n";
        std::cout << "Введите ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Введите элемент для добавления в стек 1: ";
            std::cin >> data;
            stack1.push(data);
            break;
        case 2:
            std::cout << "Введите элемент для добавления в стек 2: ";
            std::cin >> data;
            stack2.push(data);
            break;
        case 3:
            stack1.removeDifferent(stack2);
            std::cout << "Из стеков удалены элементы, входящие только в один из них." << std::endl;
            break;
        case 4:
            stack1.saveToFile(fileName1);
            stack2.saveToFile(fileName2);
            std::cout << "Стеки сохранены в файлы." << std::endl;
            break;
        case 5:
            stack1.readFromFile(fileName1);
            stack2.readFromFile(fileName2);
            std::cout << "Стеки считаны из файлов." << std::endl;
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

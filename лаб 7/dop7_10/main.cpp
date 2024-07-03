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
    int start, end;
    const char* fileName = "stack_data.txt";

    do {
        std::cout << "\n1. Добавить элемент\n2. Удалить элемент\n3. Прочитать вершину стека\n4. Проверить наличие элемента в заданном диапазоне\n5. Очистить стек\n6. Сохранить в файл\n7. Считать из файла\n0. Выйти\n";
        std::cout << "Введите ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Введите элемент для добавления: ";
            std::cin >> data;
            stack.push(data);
            break;
        case 2:
            if (!stack.isEmpty()) {
                std::cout << "Удаленный элемент: " << stack.peek() << std::endl;
                stack.pop();
            }
            else {
                std::cout << "Стек пуст." << std::endl;
            }
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
            std::cout << "Введите начало диапазона: ";
            std::cin >> start;
            std::cout << "Введите конец диапазона: ";
            std::cin >> end;
            if (stack.hasElementInRange(start, end)) {
                std::cout << "В стеке есть элементы в заданном диапазоне." << std::endl;
            }
            else {
                std::cout << "В стеке нет элементов в заданном диапазоне." << std::endl;
            }
            break;
        case 5:
            stack.clear();
            std::cout << "Стек очищен." << std::endl;
            break;
        case 6:
            stack.saveToFile(fileName);
            std::cout << "Стек сохранен в файл." << std::endl;
            break;
        case 7:
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

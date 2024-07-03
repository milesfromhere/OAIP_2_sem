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
    const char* fileName = "stack_data.txt";

    do {
        std::cout << "\n1. Поместить элемент\n2. Удалить элемент\n3. Прочитать вершину стека\n4. Очистить стек\n5. Сохранить в файл\n6. Прочитать из файла\n7. Удалить первый отрицательный элемент\n0. Выйти\n";
        std::cout << "Введите ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Введите элемент для помещения: ";
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
            stack.clear();
            std::cout << "Стек очищен." << std::endl;
            break;
        case 5:
            stack.saveToFile(fileName);
            std::cout << "Данные стека сохранены в файл." << std::endl;
            break;
        case 6:
            stack.readFromFile(fileName);
            std::cout << "Данные стека прочитаны из файла." << std::endl;
            break;
        case 7:
            stack.removeFirstNegative();
            std::cout << "Первый отрицательный элемент удален из стека." << std::endl;
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

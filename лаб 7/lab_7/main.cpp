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
        std::cout << "\n1. ��������� �������\n2. ������� �������\n3. ��������� ������� �����\n4. �������� ����\n5. ��������� � ����\n6. ��������� �� �����\n7. ������� ������ ������������� �������\n0. �����\n";
        std::cout << "������� ��� �����: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "������� ������� ��� ���������: ";
            std::cin >> data;
            stack.push(data); 
            break;
        case 2:
            if (!stack.isEmpty()) {
                std::cout << "��������� �������: " << stack.peek() << std::endl;
                stack.pop();
            }
            else {
                std::cout << "���� ����." << std::endl;
            }
            break;
        case 3:
            if (!stack.isEmpty()) {
                std::cout << "������� �����: " << stack.peek() << std::endl;
            }
            else {
                std::cout << "���� ����." << std::endl;
            }
            break;
        case 4:
            stack.clear();
            std::cout << "���� ������." << std::endl;
            break;
        case 5:
            stack.saveToFile(fileName);
            std::cout << "������ ����� ��������� � ����." << std::endl;
            break;
        case 6:
            stack.readFromFile(fileName);
            std::cout << "������ ����� ��������� �� �����." << std::endl;
            break;
        case 7:
            stack.removeFirstNegative();
            std::cout << "������ ������������� ������� ������ �� �����." << std::endl;
            break;
        case 0:
            std::cout << "���������� ���������." << std::endl;
            break;
        default:
            std::cout << "������������ �����. ����������, ������� �����." << std::endl;
            break;
        }
    } while (choice != 0);

    return 0;
}

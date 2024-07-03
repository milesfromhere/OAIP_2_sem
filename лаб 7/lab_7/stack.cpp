#include "stack.h"
#include <fstream>
#include <iostream>

Stack::Stack() {
    top = nullptr;
}

Stack::~Stack() {
    clear();
}

void Stack::push(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

void Stack::pop() {
    if (!isEmpty()) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

int Stack::peek() {
    if (!isEmpty()) {
        return top->data;
    }
    return -1; // -1 указывает на пустой стек
}

bool Stack::isEmpty() {
    return top == nullptr;
}

void Stack::clear() {
    while (!isEmpty()) {
        pop();
    }
}

void Stack::saveToFile(const char* fileName) {
    std::ofstream outFile(fileName);
    if (outFile.is_open()) {
        Node* current = top;
        while (current != nullptr) {
            outFile << current->data << std::endl;
            current = current->next;
        }
        outFile.close();
    }
    else {
        std::cerr << "Не удалось открыть файл " << fileName << std::endl;
    }
}

void Stack::readFromFile(const char* fileName) {
    clear(); // очищаем существующий стек
    std::ifstream inFile(fileName);
    if (inFile.is_open()) {
        int data;
        while (inFile >> data) {
            push(data);
        }
        inFile.close();
    }
    else {
        std::cerr << "Не удалось открыть файл " << fileName << std::endl;
    }
}

void Stack::removeFirstNegative() {
    Node* current = top;
    Node* prev = nullptr;

    while (current != nullptr) {
        if (current->data < 0) {
            // Если первый элемент отрицательный
            if (current == top) {
                pop();
                break;
            }
            else {
                prev->next = current->next;
                delete current;
                break;
            }
        }
        prev = current;
        current = current->next;
    }
}

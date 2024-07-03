#pragma once
#ifndef STACK_H
#define STACK_H

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack(); // конструктор
    ~Stack(); // деструктор

    void push(int data); // добавить элемент в стек
    void pop(); // удалить элемент из стека
    int peek(); // прочитать верхний элемент стека
    bool isEmpty(); // проверить, пуст ли стек
    void clear(); // очистить стек
    void saveToFile(const char* fileName); // сохранить стек в файл
    void readFromFile(const char* fileName); // считать стек из файла
    void removeFirstAboveValue(int value); // удалить первый элемент, превышающий заданное значение
};

#endif

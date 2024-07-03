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
    Stack(); 
    ~Stack(); 

    void push(int data); 
    void pop(); 
    int peek(); 
    bool isEmpty(); 
    void clear(); 
    void saveToFile(const char* fileName); 
    void readFromFile(const char* fileName); 
    void removeFirstNegative(); 
};

#endif

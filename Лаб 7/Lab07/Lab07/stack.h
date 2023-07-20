#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <fstream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
public:
    Stack(); // конструктор
    ~Stack(); // деструктор
    void push(int value); // добавление элемента в стек
    int pop(); // извлечение элемента из стека
    int top(); // просмотр верхнего элемента стека
    bool isEmpty(); // проверка на пустоту
    void clear(); // очистка стека
    void saveToFile(string filename); // сохранение стека в файл
    void readFromFile(string filename); // считывание стека из файла
private:
    Node* topNode;
};

#endif // STACK_H

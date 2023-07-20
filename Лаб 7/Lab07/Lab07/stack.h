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
    Stack(); // �����������
    ~Stack(); // ����������
    void push(int value); // ���������� �������� � ����
    int pop(); // ���������� �������� �� �����
    int top(); // �������� �������� �������� �����
    bool isEmpty(); // �������� �� �������
    void clear(); // ������� �����
    void saveToFile(string filename); // ���������� ����� � ����
    void readFromFile(string filename); // ���������� ����� �� �����
private:
    Node* topNode;
};

#endif // STACK_H

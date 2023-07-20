#include "stack.h"

Stack::Stack() {
    topNode = NULL;
}

Stack::~Stack() {
    clear();
}

void Stack::push(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = topNode;
    topNode = newNode;
}

int Stack::pop() {
    if (isEmpty()) {
        cout << "Stack is empty." << endl;
        return -1;
    }
    int value = topNode->data;
    Node* temp = topNode;
    topNode = topNode->next;
    delete temp;
    return value;
}

int Stack::top() {
    if (isEmpty()) {
        cout << "Stack is empty." << endl;
        return -1;
    }
    return topNode->data;
}

bool Stack::isEmpty() {
    return (topNode == NULL);
}

void Stack::clear() {
    while (!isEmpty()) {
        pop();
    }
}

void Stack::saveToFile(string filename) {
    ofstream file(filename);
    if (file.is_open()) {
        Node* current = topNode;
        while (current != NULL) {
            file << current->data << endl;
            current = current->next;
        }
        file.close();
    }
    else {
        cout << "Unable to open file." << endl;
    }
}

void Stack::readFromFile(string filename) {
    clear();
    ifstream file(filename);
    if (file.is_open()) {
        int value;
        while (file >> value) {
            push(value);
        }
        file.close();
    }
    else {
        cout << "Unable to open file." << endl;
    }
}

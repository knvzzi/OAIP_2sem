#include "Queue.h"
#include <iostream>

using namespace std;

Queue::Queue(int maxSize) {
    this->maxSize = maxSize;
    this->queueArray = new char[maxSize];
    this->front = 0;
    this->rear = -1;
    this->numItems = 0;
}

Queue::~Queue() {
    delete[] queueArray;
}

void Queue::enqueue(char item) {
    if (isFull()) {
        cout << "������� �����, ���������� �������� �������\n";
    }
    else {
        rear++;
        queueArray[rear] = item;
        numItems++;
    }
}

char Queue::dequeue() {
    if (isEmpty()) {
        cout << "������� �����, ���������� ������� �������\n";
        return '-';
    }
    else {
        char frontItem = queueArray[front];
        front++;
        numItems--;
        return frontItem;
    }
}

bool Queue::isEmpty() {
    return (numItems == 0);
}

bool Queue::isFull() {
    return (numItems == maxSize);
}

int Queue::size() {
return numItems;
}

void Queue::display() {
if (isEmpty()) {
cout << "������� �����\n";
} else {
cout << "�������:\n";
for (int i = front; i <= rear; i++) {
cout << queueArray[i] << " ";
}
cout << endl;
}
}






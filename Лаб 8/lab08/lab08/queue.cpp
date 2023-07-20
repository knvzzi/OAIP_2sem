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
        cout << "Очередь полна, невозможно добавить элемент\n";
    }
    else {
        rear++;
        queueArray[rear] = item;
        numItems++;
    }
}

char Queue::dequeue() {
    if (isEmpty()) {
        cout << "Очередь пуста, невозможно удалить элемент\n";
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
cout << "Очередь пуста\n";
} else {
cout << "Очередь:\n";
for (int i = front; i <= rear; i++) {
cout << queueArray[i] << " ";
}
cout << endl;
}
}






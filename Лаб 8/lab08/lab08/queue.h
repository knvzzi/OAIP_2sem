#ifndef QUEUE_H
#define QUEUE_H




class Queue {
private:
    int maxSize;
    char* queueArray;
    int front;
    int rear;
    int numItems;
public:
    Queue(int);
    ~Queue();
    void enqueue(char);
    char dequeue();
    bool isEmpty();
    bool isFull();
    int size();
    void display();
};

#endif

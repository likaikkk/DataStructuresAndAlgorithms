#include<iostream>
#include"_11_QueueClass.h"

using namespace std;

template<class T>
class ArrayQueue :public Queue<T> {
private:
    int maxSize;
    int front;
    int rear;
    T* queue;
public:
    ArrayQueue(int size) {
        maxSize = size+1;
        queue = new T[maxSize];
        front = rear = 0;
    }
    ~ArrayQueue() {
        delete[]queue;
    }
    void Clear() {
        front = rear;
    }
    bool EnQueue(const T item) {
        if ((rear + 1) % maxSize == front) {
            cout << "The queue is overflow." << endl;
            return false;
        }
        queue[rear] = item;
        rear = (rear + 1) % maxSize;
        return true;
    }
    bool DeQueue(T& item) {
        if (rear == front) {
            cout << "The queue is empty" << endl;
            return false;
        }
        item = queue[front];
        front = (front + 1) & maxSize;
        return true;
    }
    bool GetFront(T& item) {
        if (rear == front) {
            cout << "The queue is empty" << endl;
            return false;
        }
        item = queue[frond];
        return true;
    }
};
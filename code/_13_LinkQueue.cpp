#include<iostream>
#include"_11_QueueClass.h"

using namespace std;


template<class T>
class LinkNode {
public:
    T data;                 //data field
    LinkNode<T>* link;      //pointer field
    LinkNode() {}
    LinkNode(const T& el, LinkNode<T>* ptr = 0) {
        data = el;
        link = ptr;
    }
};

template<class T>
class LinkQueue :public Queue<T> {
private:
    int size;
    LinkNode<T>* front;
    LinkNode<T>* rear;
public:
    LinkQueue(int size) {
        size = 0;
        front = rear = NULL;
    }
    ~LinkQueue() {
        Clear();
    }
    void Clear() {
        while (front != NULL) {
            rear = front;
            front = front->link;
            delete rear;
        }
        rear = NULL;
        size = 0;
    }

    //add element item to the end of the queue
    bool EnQueue(const T item) {
        if (rear == NULL) {
            front = rear = new LinkNode<T>(item, NULL);
        }
        else {
            rear->link = new LinkNode<T>(item, NULL);
            rear = rear->link;
        }
        size++;
        return true;
    }

    //take out the first element of the queue and delete it
    bool DeQueue(T& item) {
        LinkNode<T>* temp;
        if (size == 0) {
            cout << "The queue is empty" << endl;
            return false;
        }
        item = front->data;
        temp = front;
        front = front->link;
        delete temp;
        if (front == NULL) {
            rear = NULL;
        }
        size--;
        return true;
    }

    //read the front element without deleting
    bool GetFront(T& item) {
        if (size == 0) {
            cout << "The queue is empty" << endl;
            return false;
        }
        item = front->data;
        return true;
    }
};
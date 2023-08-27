#include<iostream>
#include "_06_StackClass.h"

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
class LinkStack :public Stack<T> {
private:
    LinkNode<T>* top;           //pointer to the top of the stack
    int size;                   //the number of stored elements
public: 
    LinkStack() {               //constructor
        top = NULL;
        size = 0;
    }
    ~LinkStack() {              //destructor
        Clear();
    }
    void Clear() {              //clear the contents of the stack
        while (top != NULL) {
            LinkNode<T>* tmp = top;
            top = top->link;
            delete tmp;
        }
        size = 0;
    }
    bool Push(const T item) {   //push operation with link implementation
        LinkNode<T>* tmp = new LinkNode<T>(item, top);
        top = tmp;
        size++;
        return true;
    }
    bool Pop(T& item) {         //pop operation with link implementation
        LinkNode<T>* tmp;
        if(size==0)
        {
            cout << "The stack is empty, unable to pop." << endl;
            return false;
        }
        item = top->data;
        tmp = top->link;
        delete top;
        top = tmp;
        size--;
        return true;
    }
    bool Top(T& item) {         //read the top element without deleting
        if (size == 0) {
            cout << "The stack is empty, unable to read the top element." << endl;
            return false;
        }
        item = top->data;
        return true;
    }
};

int main() {
 LinkStack<int> stack;

    // Push some elements onto the stack
    for (int i = 1; i <= 5; ++i) {
        stack.Push(i);
    }

    cout << "Stack contents: ";
    int topItem;
    while (stack.Top(topItem)) {
        cout << topItem << " ";
        stack.Pop(topItem);
    }
    cout << endl;

    return 0;
}
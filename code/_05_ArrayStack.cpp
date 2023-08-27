#include<iostream>
#include "_06_StackClass.h"
using namespace std;

template<class T>
class ArrayStack :public Stack<T>
{
private:
    int maxSize;                //The maximum size of the stack
    int top;                    //Position of the top of the stack
    T* st;                      //Array to store stack elements
public:
    ArrayStack(int size) {      //Create a ArrayStack instance with a given length
        maxSize = size;
        top = -1;
        st = new T[maxSize];
    }
    ArrayStack() {              //Create a ArrayStack instance
        top = -1;
    }
    ~ArrayStack() {             //Destructor
        delete[]st;
    }
    void Clear() {
        top = -1;               //Clear the contents of the stack
    }
    bool Push(const T item) {   //Push operation
        if (top == maxSize - 1) {
            cout << "The stack is overflow" << endl;
            return false;
        }
        else {                  //Push and modify the top pointer
            st[++top] = item;
            return true;
        }
    }   
    bool Pop(T& item) {         //Pop operation
        if (top == -1) {        //Stack is empty
            cout << "The stack is empty, unable to delete" << endl;
            return false;
        }
        else {
            item = st[top--];   //Read the top element and modify teh top pointer
            return true;
        }
    }
    bool Top(T& item) {         //Read the top element without deleting
        if(top == -1) {         //Stack is empty
            cout << "The stack is empty, unable to read the top element" << endl;
            return false;
        }
        else {
            item = st[top];  
            return true;
        }
    }
    bool IsEmpty() {            //Check if the stack is empty
        return top == -1;
    }

    bool IsFull() {             //Check if the stack is full
        return top == maxSize-1;
    }
};

int main() {
    ArrayStack<int> stack(5);   //Creat a stack with a maximum size of 5
    cout << "Is the stack empty?" << (stack.IsEmpty() ? "Yes" : "No") << endl;
    cout << "Is the stack full?" << (stack.IsFull() ? "Yes" : "No") << endl;

    stack.Push(10);
    stack.Push(20);
    stack.Push(30); 
    int topItem;
    if (stack.Top(topItem)) {
        cout << "Top element:" << topItem << endl;
    }

    stack.Push(40);
    stack.Push(50);
    stack.Push(60);             //This should print "The stack is overflow"

    cout << "Pop elements:";
    while (!stack.IsEmpty())
    {
        if (stack.Pop(topItem))
            cout << topItem << " ";
    }
    cout << endl;

    cout << "Is the stack empty?" << (stack.IsEmpty() ? "Yes" : "No") << endl;

    return 0;
}
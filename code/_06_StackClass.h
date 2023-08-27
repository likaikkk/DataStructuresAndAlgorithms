template<class T>
class Stack {
public:
    void Clear();               //Empty stack
    bool Push(const T item);    //Stack push operation
    bool Pop(T& item);          //Read the value of the top element of the stack and delete it
    bool Top(T& item);          //Read the value of the top element of the stack without deleting it
    bool IsEmpty();             //Check if the stack is empty
    bool IsFull();              //Check if the stack is full
};
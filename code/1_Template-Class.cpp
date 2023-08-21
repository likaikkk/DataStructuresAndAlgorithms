#include <iostream>
//模板类（Template Class）是C++中的一种特殊类型的类，它允许你定义一种通用的类模板，可以用于多种不同的数据类型。模板类允许你编写一次代码，然后根据需要为不同的数据类型生成对应的类实例。这在实现通用数据结构和算法时非常有用，因为你可以避免为每种数据类型都单独编写相似的代码。

//模板类的基本思想是在类定义中使用模板参数，这些参数可以代表不同的数据类型。在使用模板类时，你需要提供实际的数据类型作为模板参数，这样编译器就会生成相应的类定义。

//以下是一个简单的模板类的示例，用于创建一个通用的栈（Stack）数据结构：
template <class T>
class Stack {
private:
    T elements[100];
    int top;

public:
    Stack() :top(-1) {}

    void Push(const T& value) {
        elements[++top] = value;
    }

    T Pop() {
        return elements[top--];
    }
};

int main() {
    Stack<int> intStack; // 使用 int 数据类型创建一个栈
    Stack<double> doubleStack; // 使用 double 数据类型创建一个栈

    intStack.Push(5);
    doubleStack.Push(3.14);

    int poppedInt = intStack.Pop();
    double poppedDouble = doubleStack.Pop();

    std::cout << poppedInt << std::endl << poppedDouble;

    return 0;
}
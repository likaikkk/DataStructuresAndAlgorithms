#include<iostream>

using namespace std;

//单链表的结点定义
template<class T>
class LinkNode {
public:
    T data;                 //数据域
    LinkNode<T>* link;      //指针域
    LinkNode() {}
    LinkNode(const T& el, LinkNode<T>* ptr = 0) {
        data = el;
        link = ptr;
    }
    /* 
    LinkNode<T>* ptr = 0 中的 ptr = 0 表示将指针 ptr 初始化为空指针（nullptr），
    在 C++ 中，空指针通常用数字 0 或者关键字 nullptr 来表示。

    在这个特定的构造函数中，LinkNode(const T& el, LinkNode<T>* ptr = 0)，第二个参数 ptr 是一个可选参数，这意味着在调用构造函数时可以不提供这个参数，如果不提供的话，就会使用默认值。默认值在这里设置为 0，即空指针。

    这种做法允许在创建节点的时候可以选择是否传入一个指向下一个节点的指针。如果你提供了这个指针，节点将连接到提供的节点，如果没有提供，它将被初始化为一个空指针，表示该节点不连接到任何其他节点，即它是链表中的最后一个节点。
     */
};

//单链表的类型定义
template<class T>
class LinkList
{
private:
    LinkNode<T>* head, * tail;      //表头和表尾指针
    //记录当前遍历位置的指针，由插入和删除操作更新
    /* prevPtr（前驱指针）：它指向当前位置的前一个节点。在插入和删除节点时，需要知道前一个节点，以便正确地建立和维护链表的连接。

currPtr（当前指针）：它指向当前位置节点。这是链表遍历和节点操作的主要指针，可以用来访问当前位置节点的数据以及进行插入、删除等操作。 */
    LinkNode<T>* prevPtr, * currPtr;
    int position;                   //当前元素在表中的位置序号，由函数reset使用
public:
    LinkList() {
        head = new LinkNode<T>; //创建一个虚拟头结点
        tail = head;
        position = 0;
        prevPtr = currPtr = head;
    }
    ~LinkList() {
        clear();
        delete head;
    }
    int getSize()const;             //返回链表中元素个数
    bool isEmpty()const;            //链表是否为空
    void reset(int pos = 0);        //初始化指针的位置（第一位数的位置设置为0）
    void next();                    //使指针移动到下一个结点
    bool endOfList()const;          //指针是否到了链尾
    int currentPosition(void);      //返回指针当前位置
    void insertHead(const T& item); //在表头插入结点
    void insertTail(const T& item); //在表尾插入结点
    void insertAt(const T& item);   //在当前结点之前插入结点
    void insertAfter(const T& item);//在当前结点之后插入结点
    void deleteCurrent();           //删除当前结点
    T& data();                      //返回对当前结点成员数据的引用
    /* 函数后加const意味着为常成员函数，返回的值也必须是const常量
    在 LinkList 类中，const T& data()const; 返回一个对当前节点数据的常引用，这意味着调用该函数的代码不能通过这个引用修改数据。如果返回的是非常引用，那么调用者可能会误解成可以通过这个引用修改数据，这与常量成员函数的设计意图相悖。*/
    void clear();                   //清空链表
    LinkNode<T>* setPos(int i);     //返回指定位置i的指针
    bool insertPos(const int i, const T value);//在指定位置插入结点
    bool deletePos(const int i);    //删除指定位置的结点
    bool invert();                  //反转整个链表
};

//清空链表
template<class T>
void LinkList<T>::clear()
{
    while (head->link != NULL) {
        LinkNode<T> *temp = head->link;
        head->link = temp->link;
        delete temp;
    }
    tail = head;
    currPtr = NULL;
    prevPtr = NULL;
    position = 0;
}

//返回指定位置i的指针
template<class T>
LinkNode<T>* LinkList<T>::setPos(int i)
{
    if (i == -1)                         //i为-1则定位到头结点
        return head;
    int count = 0;
    LinkNode<T>* p = head->link;
    while (p != NULL && count < i) {
        p = p->link;
        count++;
    }
    return p;                           //指向第i个结点，当链表长度小于i时返回NULL
}

//插入单链表的第i个结点
template<class T>
bool LinkList<T>::insertPos(const int i, const T value)
{
    LinkNode<T>* p = setPos(i - 1);         //p是第i个结点的前驱
    LinkNode<T>* q;                         //q是新插入的结点        
    if(p==NULL)
    {
        cout << "插入操作不允许" << endl;
        return false;
    }
    q = new LinkNode<T>(value, p->link);    // 创建一个新的节点q，数据值为value，指针指向p的后继节点
    p->link = q;                            // 将p的指针指向新节点q
if (p == tail)                              //在表尾进行插入操作
        tail = q;
    return true;
}

//删除指定结点
template<class T>
bool LinkList<T>::deletePos(const int i)
{
    LinkNode<T>* p, * q;
    if ((p = setPos(i - 1)) == NULL||p==tail) {
        cout << "非法删除点" << endl;
        return false;
    }
    q = p->link;                //q为真正待删除点
    p->link = q->link;
    
    if (q == tail)              //删除点为表尾，修改尾指针
        tail = p;
    
    delete q;
    return true;
}

//反转结点
template<class T>
bool LinkList<T>::invert()
{
    LinkNode<T>* q, * p, *R;
    p = head->link;             //将p指向首结点
    q = NULL;                   //q用来执行p的前一个结点    
    while (p != NULL) {             
        R = q;                  //将r接到q之后
        q = p;                  //q接到p之后    
        p = p->link;            //p移动到下一个结点    
        q->link = R;            //q接到之前的结点    
    }
    tail = head->link;
    head->link = q;
    return true;
}

//返回链表元素个数
template<class T>
int LinkList<T>::getSize() const
{
    LinkNode<T>* p=head->link;
    int i = 0;
    for (;p != NULL;i++)
        p = p->link;
    return i;
}

//链表是否为空
template<class T>
bool LinkList<T>::isEmpty() const
{
    return head->link == NULL;
}

//初始化指针的位置
template<class T>
void LinkList<T>::reset(int pos)
{
    if (pos<0 || pos>getSize()) {
        cout << "Invalid position." << endl;
        return;
    }
    position = pos;  //更新记录当前位置
    //重新设置currPtr和prevPtr
    prevPtr = head;
    currPtr = head->link;
    for (int i = 0; i < position; i++) {
        next();
    }
}

//使指针移动到下一个结点
template<class T>
void LinkList<T>::next()
{
    if (currPtr != NULL) {
        prevPtr = currPtr;
        currPtr = currPtr->link;
        position++;
    }
}

//指针是否到了链尾
template<class T>
bool LinkList<T>::endOfList() const
{
    return currPtr == NULL;
}

//返回当前指针位置
template<class T>
int LinkList<T>::currentPosition(void)
{
    return position;
}

//在表头插入结点
template<class T>
void LinkList<T>::insertHead(const T& item)
{
    LinkNode<T>* newNode = new LinkNode<T>(item, head->link);           //创建新结点，其指针指向原头结点的下一个结点
    head->link = newNode;         //将头结点的指针指向新结点
    if (tail == head)             //如果链表为空，更新尾指针
        tail = newNode;
}

//在表尾插入结点
template<class T>
void LinkList<T>::insertTail(const T& item)
{
    LinkNode<T>* newNode = new LinkNode<T>(item);

    if (isEmpty()) {
        head->link = newNode;
        tail = newNode;
    } else {
        tail->link = newNode;  // 将当前的尾结点的指针域指向新节点
        tail = newNode;        // 更新尾指针，指向新节点
    }
}

//在当前结点之前插入结点
template<class T>
void LinkList<T>::insertAt(const T& item) {
    LinkNode<T>* newNode = new LinkNode<T>(item, currPtr);
    prevPtr->link = newNode;
    currPtr = newNode;
}

//在当前结点之后插入结点
template<class T>
void LinkList<T>::insertAfter(const T& item)
{
    /* 需要注意，如果 currPtr 恰好指向链表的尾节点，那么这个实现可能会导致错误。因为在尾节点之后没有节点，直接将新节点插入 currPtr->link 可能会导致异常行为。所以，在 insertAfter 函数中，您需要检查是否到达了尾节点，然后根据情况处理插入新节点的操作。 */
    if (currPtr == tail)
        insertTail(item);
    else {
        LinkNode<T>* newNode = new LinkNode<T>(item, currPtr->link);
        currPtr->link = newNode;
    }
}

//删除当前结点
template<class T>
void LinkList<T>::deleteCurrent()
{
    if (currPtr == NULL) {
        cout << "No current node to delete." << endl;
        return;
    }
    LinkNode<T>* temp = currPtr;  // 保存当前节点指针

    // 将前一个节点的指针连接到当前节点的下一个节点
    prevPtr->link = currPtr->link;

    // 如果当前节点是尾节点，更新尾指针
    if (currPtr == tail)
        tail = prevPtr;

    // 更新当前节点指针和前一个节点指针
    currPtr = currPtr->link;
    delete temp;  // 释放内存
}

//返回对当前结点成员数据的引用
template<class T>
T& LinkList<T>::data()
{
    if (currPtr == NULL)
        // cout << "No current node" << endl;
        /*在当前节点为空（currPtr == NULL）时，您只是打印了消息而没有实际返回任何东西。
        在这种情况下，应该决定返回什么值或者是抛出一个异常。
        如果您希望在当前节点为空时返回一个默认值，可以考虑返回一个引用，该引用引用一个默认值。如果您希望在当前节点为空时抛出异常，可以使用类似 throw 语句来实现。*/
        throw runtime_error("No current node.");
    return currPtr->data;
}

int main() {
    // Create an instance of LinkList for integers
    LinkList<int> myList;

    // Insert some elements
    myList.insertTail(10);
    myList.insertTail(20);
    myList.insertTail(30);

    // Traverse and print the list
    myList.reset();
    while (!myList.endOfList()) {
        std::cout << myList.data() << " ";
        myList.next();  // Move the pointer to the next element
    }
    std::cout << std::endl;

    // Insert a new element at a specific position
    myList.insertPos(1, 15);

    // Print the updated list
    myList.reset();
    while (!myList.endOfList()) {
        std::cout << myList.data() << " ";
        myList.next();  // Move the pointer to the next element
    }
    std::cout << std::endl;

    // Delete an element at a specific position
    myList.deletePos(2);

    // Print the updated list
    myList.reset();
    while (!myList.endOfList()) {
        std::cout << myList.data() << " ";
        myList.next();  // Move the pointer to the next element
    }
    std::cout << std::endl;

    // Invert the list
    myList.invert();

    // Print the inverted list
    myList.reset();
    while (!myList.endOfList()) {
        std::cout << myList.data() << " ";
        myList.next();  // Move the pointer to the next element
    }
    std::cout << std::endl;

    return 0;
}

# 线性表（linear list）

## 1. 线性表的概念

### 1.1线性表的定义

​	线性表是n个元素的有限序列。

​	线性结构的**特点**：

1. 具有唯一的头元素
2. 具有唯一的尾元素
3. 除头元素外，集合中的每一个元素均有一个直接的前驱，例如a<sub>i</sub>的前驱是a<sub>i-1</sub>
4. 除尾元素外，集合中的每一个元素均有一个直接的后继，例如a<sub>i</sub>的前驱是a<sub>i+1</sub>

​	线性表是由具有相同数据类型的n个数据元素组成的一种`有限的而且有序`的序列。

### 1.2线性表的抽象数据类型

​	抽象数据类型是指用以表示应用问题的数据模型以及定义在该模型上的一组操作。从抽象数据类型的观点来看，**一种数据结构即为一个抽象数据类型**。一个`抽象数据类型`由`数据部分`和`操作部分两`方面来买描述。

```cpp
template <class T>
class List{
 void Clear();									//置空线性表
 bool IsEmpty();									//线性表为空时，返回true
 bool Append(const T value);						//在表尾添加元素value，表的长度加1
 bool Insert(const int p, const T value);		//在位置p插入元素value，表的长度加1
 bool Delete(const int p);						//删除位置p上的元素，表的长度减1
 bool GetValue(const int p, T& value);			//把位置p上的元素值返回到变量value中
 bool SetValue(const int p, const T value);		//把位置p上的元素修改为value
 bool GetPos(int &p, const T value);				//把值为value的元素的位置返回到变量p中
};
```

​	关于template class见[_1_Template-Class.cpp](https://github.com/likaikkk/DataStructuresAndAlgorithms/blob/master/code/_01_Template-Class.cpp)

### 1.3线性表的主要操作

1. 线性表的初始化：`void initList(List& L)`
   先决条件：线性表L已经声明但存储空间未分配
   操作结果：动态分配存储空间，构造一个空的线性表L
2. 取线性表的第i个元素的值：`DataType getValue(List& L, int i)`
3. 计算线性表的长度：`int Length(List& L)`
4. 线性表的查找：`position Search(List& L, DataType x)`
5. 线性表的插入：`int Insert (List& L, int i, DataType x)`
6. 线性表的删除：`int Remove(List& L, int i, DataType& x)`
7. 线性表的遍历：`void Traverse(List& L)`
8. 线性表的排序：`void Sort(List& L)`

以上操作时逻辑结构上定义的操作。至于如何实现细节，只有在确定了存储结构之后才能具体实现。

### 1.4线性表的存储结构

1. **定长的顺序存储结构**，简称`顺序表`，程序中通过创建数组来建立这种存储结构，特点是**线性表元素被分配到一块连续的存储空间，元素顺序存储在这些连续的空间中，数据元素之间是`“物理位置相邻”`的**。定长的顺序存储结构限定了线性表长度的变化不得超过该固定长度，这是顺序表的不足之处。
2. **变长的线性存储结构**，简称`链表`，链接式存储结构使用指针，按照线性表的前驱和后继关系将各元素用指针链接起来。变长的线性存储结构对线性表的长度不加限制。

## 2. 顺序表 SeqList 

把采用顺序存储结构的线性表简称为**顺序表**，也称为**向量**，有以下主要特征：

1. 元素的数据类型**相同**。
2. 元素顺序的存储在一片**地址连续的存储空间**中，一个元素按照存储顺序有唯一的索引值，又称为下标，可以随机存取表中的元素。
3. 逻辑关系相邻的两个元素在物理位置上也相邻。
4. 在程序中，数组变量说明语句一般使用常数作为向量长度，长度是静态常熟，在程序执行时不变。

### 2.1顺序表的实现

*见* [_02_ArrayList.cpp](https://github.com/likaikkk/DataStructuresAndAlgorithms/blob/master/code/_02_ArrayList.cpp )

### 2.2顺序表的应用

求两个顺序表的差集：见[__03_DifferenceOfSeqList.cpp_](https://github.com/likaikkk/DataStructuresAndAlgorithms/blob/master/code/_03_DifferenceOfSeqList.cpp)

## 3. 链表LinkList

### 3.1单链表

​	单链表是通过指针把它的一串内存结点链接成一个链，这些内存结点两两之间地址不必相邻。为此，他的存储结点由两部分组成：一部分存放线性表结点的数据，称为`数据域`，一部分存放指向后继结点的指针，称为`指针域`。对没有后继结点的尾结点而言，其指针域为空指针NULL。

​	【单链表的结点定义】

```cpp
templatetemplate<class T>
class LinkNode {
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
```

​	由于单链表中的结点是一个独立的对象，为了方便复用，故将其定义为一个独立的类。

​	用一个指向表首的变量`head`存放指向单链表首结点的指针。

​	用一个指向表尾的变量`tail`存放指向单链表表尾结点的指针。

​	对单链表的访问只能通过头、尾指针来进行。

​	为了便于实现，给每个单链表加上一个“头结点”，它位于单链表的第一个结点之前。头结点的data域可以不存储任何信息，也可以存放一个特殊标志或表长。

​	如图：![带头结点的单链表](https://i.postimg.cc/QM5Xgf0H/1692715967266.jpg)

​	(图中`^`代表NULL，为空指针)

​	a为一个带头结点的空链表，b为非空链表。只要表存在，它必须至少有一个头结点。

​	**`头结点好处`：**

1. **便于首结点的处理**。对带头结点的单链表，在表的任何结点之前插入结点或者删除结点，所要做的都是修改前一节点的指针域。若单链表没有头结点，则首结点没有前驱结点，在其前插入结点或删除该结点时要特殊处理。
2. **便于空表和非空表的统一处理**。不带头结点的单链表，单链表不为空表时头指针指向首结点，当单链表为空表时头指针为空`head == NULL`。而带头结点的单链表，无论是否为空，头指针都是指向头结点的非空指针，如图b所示，头指针head指向头结点。若为空表，则头结点的指针域为空`head->link==NULL`

​	【带头结点单链表的类型定义】

```cpp
template<class T>
class LinkList
{
private:
 LinkNode<T>* head, * tail;      //表头和表尾指针
 //记录当前遍历位置的指针，由插入和删除操作更新
 LinkNode<T>* prevPtr, * currPtr;
 int position;                   //当前元素在表中的位置序号，由函数reset使用
public:
 LinkList();
 ~LinkList();
 int getSize()const;             //返回链表中元素个数
 bool isEmpty()const;            //链表是否为空
 void reset(int pos = 0);        //初始化指针的位置（第一位数的位置设置为0）
 void next();                    //使指针移动到下一个结点
 bool endOfList()const;          //指针是否到了链尾
 int currentPosition(void);      //返回指针当前位置
 void insertHead(const T& item); //在表头插入结点
 void insertTail(const T& item); //在表尾插入结点
 vodi insertAt(cosnt T& item);   //在当前结点之前插入结点
 vodi insertAfter(cosnt T& item);//在当前结点之后插入结点
 void deleteCurrent();           //删除当前结点
 T& data();                      //返回对当前结点成员数据的引用
 void clear();                   //清空链表
 LinkNode<T>* setPos(int i);     //返回指定位置i的指针
 bool insertPos(const int i, const T value);//在指定位置插入结点
 bool deletePos(const int i);    //删除指定位置的结点
 bool invert();                  //反转整个链表
};
```

​	对于单链表，最常用的运算就是`检索`、`插入`、`删除`。

1. **单链表检索结点**

   ```cpp
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
   ```

   ​	链表中第i个结点是按照C/C++的数组下标编号规则，从0到n-1，头结点的编号时-1.当单链表实际长度小于给定的i时，返回NULL，当i为-1时返回头结点的指针。

2. **单链表插入结点**
   ![单链表插入运算实现方法](https://i.postimg.cc/1zBnnB6n/1692767483752.jpg)

   ```cpp
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
   ```



3. **单链表删除结点**

   ```cpp
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
   ```



4. **单链表的反转**
   <img src="https://i.postimg.cc/FKLt1GbX/1692797807696.jpg" alt="单链表的反转示意图" style="zoom: 150%;" />

      ```cpp
      template<class T>
   bool LinkList<T>::invert()
   {
       LinkNode<T>* q, * p, R;
       p = head->link;             //将p指向首结点
       q = NULL;                   //q用来执行p的前一个结点    
       while (p != NULL) {             
           r = q;                  //将r接到q之后
           q = p;                  //q接到p之后    
           p = p->link;            //p移动到下一个结点    
           q->link = r;            //q接到之前的结点    
       }
       tail = head->link;
       head->link = q;
       return true;
   }
      ```

   <img src="https://i.postimg.cc/zBWYVprR/1692798345016.jpg" alt="单链表的反转" style="zoom:150%;" />

5. **单链表完整代码见**[_04_LinkList.cpp](https://github.com/likaikkk/DataStructuresAndAlgorithms/blob/master/code/_04_LinkList.cpp)

### 3.2双向链表

​	**双向链表**其基本结构就是在单链表的每个结点中增加一个指向前驱结点的指针，结构特点如图所示，`next`表示指向后继结点的指针，prev指向前驱结点。            

[![双向链表](https://i.postimg.cc/RhcZ06Qk/1692982796354.jpg)](https://postimg.cc/xN12xdZ5)

​	【双向链表的结点定义】

```cpp
//Node definition of DoubleLinkedList
template<class T>
class DLLNode{
public:
T data;         //Save the content of the Node element
DLLNode<T>* next;   //Pointer to successor node
DLLNode<T>* prev;   //Pointer to predecessor node
//Constructor
DLLNode(const T info, DLLNode<T>* prevVal = NULL, DLLNode<T>* nextVal = NULL) {
  data = info;
  prev = prevVal;
  next = nextVal;
}
//Constructor given only bidirectional pointer
DLLNode(DLLNode<T>* prevVal = NULL, DLLNode<T>* nextVal = NULL) {
  prev = prevVal;
  next = nextVal;
}
};
```

1.【双向链表中插入新结点】

​	双向链表中要在p所指节点后插入一个新的结点q，具体操作步骤：

1. 执行`new q`开辟结点空间

2. 填写结点数据域信息

3. 填写结点在双向链表中的链接关系，即
   `q->prev = p;`

   `q->next = p->next;`

4. 修改p所指结点及后继结点在新结点插入后的链接信息：
   `p->next = q;`
   `q->next->prev = q;`

![示意图](https://i.postimg.cc/Dw608F4z/1693050401358.jpg)

2.**【双向链表中删除结点】**

1. 修改相应的指针
   `p->next->prev = p->prev;`

   `p->prev->next = p->next;`

2. 释放被删结点空间
   `delete p;`

### 3.3循环链表

​	在单链表中有一件重要的事情就是**维护表头的指针**，因为单链表具有*方向性*，所以如果链表的表头指针被破坏或损失，就会丢失整个链表，同时浪费了整个链表的存储空间。

​	将单链表的最后一个结点的指针不为`NULL`，而是指向表首结点，就成为一个**循环单链表**。如此就不用担心链表头指针遗失的问题了，因为每个结点都能是链表头部。使用循环链表的主要**优点**是：*从循环链表中的任一结点出发，都能访问表中的其它结点。*

​	循环链表分类：
![](https://i.postimg.cc/FsHZnFby/1693051322519.jpg)

1. 【**循环单链表插入结点**】
   	因为每个结点的 指针域都是指向下一个结点，所以没有所谓的从链表尾部插入的问题。通常会出现下面三种情况：

   1. *将新结点插入到带头结点的循环单链表**第一个结点之前***：首先将新结点`X`的指针域指向原链表头结点的后继，再将循环单链表的头结点指针域指向新结点`X`。
      `X->next = head->next;`
      `head->next = X;`
   2. *将新结点插入到带头结点的循环单链表**最后一个结点之后***：首先找到最后一个结点，将最后一个结点的指针域指向新结点`X`，然后将新结点`X`的指针域指向原链表头结点，再将循环单链表的尾指针指向新结点`X`.
      `tail->next = X;`
      `X->next = head;`
      `tail = X;`
   3. 将新结点插入到带头结点的循环单链表**任意结点`I`之后**：
      `X->next = I->next;`
      `I->next = x;`

2. **【循环单链表删除结点】**

   1. *删除带头结点的循环单链表的**第一个结点***：
      `Y = head->next;`
      `head->next = Y->next;`
      `delete Y;`

   2. *删除带头结点的循环单链表的**尾结点***：首先找到尾结点Y的前一个结点，将尾指针tail指向这个结点，然后将这个结点的指针域改为指向该循环单链表的头结点，最后删除Y。

      ```cpp
      CurNode = head;
      Y = tail;
      while(CurNode->next != Y){
          CurNode = CurNode->next;  //找到链表尾结点的前驱结点
      }
      tail = CurNode;
      CurNode->next = head;
      delete Y;
      ```

   3. *删除带头结点的循环单链表的**中间结点***：首先找到待删除结点Y的前一个结点，用PreNode记录下来，再将PreNode的指针域指向Y的下一个结点，最后删除Y。

      ```cpp
      PreNdoe = head;
      while(PreNode->next != Y)
          PreNode = PreNode->next;
      PreNode->next = Y->next;
      delete Y;
      ```

3. **【循环单链表的反转】**
        循环单链表的反转需要遍历整个链表，和单链表的反转类似，不同之处在于*尾结点的处理*，循环单链表尾结点的指针域需要指向循环单链表的头结点。

   ```cpp
   template<class T>
   bool LinkList<T>::invert(){
       if(head->link == NULL){
           return false;
       }
       LinkNode<T> *p,*q,*r;
       p = head->next;
       q = r = head;
       while(p != head){
           q = p->next;
           p->next = r;
           r = p;
           p = q;
       }
       tail head->next;
       head->next = r;
       return true;
   }
   ```

### 3.4链表的应用

## 4. 栈Stack

​	**栈**是一种*限制访问端口的线性表*，即栈的所有操作都限制在线性表的一端进行。线性表的元素插入（称为栈的`压入`）和删除（称为栈的`弹出`）都限制在表首进行。**表首被称为`栈顶`**，而栈的另一端称为`栈底`。栈的**特点**是：每次取出（并删除）的总是刚刚压入的元素，即在时间上最后压入的元素。而最先压入的元素则被放在栈的底部，需要到最后才能取出。因而，栈又称为“*后进先出表*‘“（last in  first out, LIFO）、“下推表”。栈通常有两种方式是实现，分别是采用顺序存储结构的`顺序栈`与链式结构的`链式栈`。
​	【栈的类定义】

```cpp
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
```

### 4.1顺序栈

​	*采用顺序存储结构的栈被称为顺序栈*，需要一块**地址连续的存储单元**存储栈中的元素。因此需要实现知道或估计栈的大小。

​	**栈的本质是简化的顺序表**，对元素数目为n的栈，首先要确定数组的哪一段表示栈顶。如果把数组的第0个位置作为栈顶，按照栈的定义，所有的插入和删除操作都在第0个位置上进行，即意味着每次的push和pop操作都需要把当前的栈的所有元素在数组中后移或者前移一个位置，时间复杂度为O(n)。反之，如果把最后一个元素的位置n-1作为栈顶，那么只需要将新元素添加在表尾，出栈操作也只需要删除表尾的元素，每次操作的时间复杂度仅为O(1)。

​	顺序栈实现时，用一个整型变量`top`(通常为栈顶指针)来指示当前栈顶位置，同时也可以表示当前栈中元素的个数。

【顺序栈的部分实现】

```cpp
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
};
```

​	当栈中已有maxSize个元素时，进栈操作会产生溢出现象，称为`上溢`；相应的，在空栈上进行出栈操作同样也会方式溢出，称为`下溢`。

​	如果出现上溢时仍希望进行进栈操作，可以考虑适当的扩充当前顺序栈的容量。

【**改进的进栈操作**】

```cpp
template<class T>
bool ArrayStack<T>::push(const T item){
 if(top == maxSize-1){
     T* newSt = new T [maxsSize*2];
     for(int i = 0; i <= top; i++){
         newSt[i] = st[i];
     }
     delete [] st;			//release the original stack
     st = newSt;
 	maxSize *= 2;
 }
 st[++top] = item;
 return true;
}
```

【ArrayStack完整代码】[_05_ArrayStack.cpp](https://github.com/likaikkk/DataStructuresAndAlgorithms/blob/master/code/_05_ArrayStack.cpp)

### 4.2链式栈

### 4.3栈与递归

### 4.4递归的应用

### 4.5栈的应用

## 5. 队列

### 5.1顺序队列

### 5.2链式队列

### 5.3队列的应用

## 6. 字符串

### 6.1基本概念

### 6.2存储结构和实现

### 6.3字符串运算的算法实现

### 6.4字符串的模式匹配
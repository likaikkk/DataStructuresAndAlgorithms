# 线性表（linear list）

## 1. 线性表的概念

#### 1.1线性表的定义

> 线性表是n个元素的有限序列。
>
> 线性结构的**特点**：
>
> 1. 具有唯一的头元素
> 2. 具有唯一的尾元素
> 3. 除头元素外，集合中的每一个元素均有一个直接的前驱，例如a<sub>i</sub>的前驱是a<sub>i-1</sub>
> 4. 除尾元素外，集合中的每一个元素均有一个直接的后继，例如a<sub>i</sub>的前驱是a<sub>i+1</sub>
>
> 线性表是由具有相同数据类型的n个数据元素组成的一种`有限的而且有序`的序列。

#### 1.2线性表的抽象数据类型

> 抽象数据类型是指用以表示应用问题的数据模型以及定义在该模型上的一组操作。从抽象数据类型的观点来看，**一种数据结构即为一个抽象数据类型**。一个`抽象数据类型`由`数据部分`和`操作部分两`方面来买描述。
>
> ```cpp
> template <class T>
> class List{
>     void Clear();									//置空线性表
>     bool IsEmpty();									//线性表为空时，返回true
>     bool Append(const T value);						//在表尾添加元素value，表的长度加1
>     bool Insert(const int p, const T value);		//在位置p插入元素value，表的长度加1
>     bool Delete(const int p);						//删除位置p上的元素，表的长度减1
>     bool GetValue(const int p, T& value);			//把位置p上的元素值返回到变量value中
>     bool SetValue(const int p, const T value);		//把位置p上的元素修改为value
>     bool GetPos(int &p, const T value);				//把值为value的元素的位置返回到变量p中
> };
> ```
>
> 关于template class见[_1_Template-Class.cpp](https://github.com/likaikkk/DataStructuresAndAlgorithms/blob/master/code/_01_Template-Class.cpp)

#### 1.3线性表的主要操作

> 1. 线性表的初始化：`void initList(List& L)`
>    先决条件：线性表L已经声明但存储空间未分配
>    操作结果：动态分配存储空间，构造一个空的线性表L
> 2. 取线性表的第i个元素的值：`DataType getValue(List& L, int i)`
> 3. 计算线性表的长度：`int Length(List& L)`
> 4. 线性表的查找：`position Search(List& L, DataType x)`
> 5. 线性表的插入：`int Insert (List& L, int i, DataType x)`
> 6. 线性表的删除：`int Remove(List& L, int i, DataType& x)`
> 7. 线性表的遍历：`void Traverse(List& L)`
> 8. 线性表的排序：`void Sort(List& L)`
>
> 以上操作时逻辑结构上定义的操作。至于如何实现细节，只有在确定了存储结构之后才能具体实现。

#### 1.4线性表的存储结构

> 1. **定长的顺序存储结构**，简称`顺序表`，程序中通过创建数组来建立这种存储结构，特点是**线性表元素被分配到一块连续的存储空间，元素顺序存储在这些连续的空间中，数据元素之间是`“物理位置相邻”`的**。定长的顺序存储结构限定了线性表长度的变化不得超过该固定长度，这是顺序表的不足之处。
>
> 2. **变长的线性存储结构**，简称`链表`，链接式存储结构使用指针，按照线性表的前驱和后继关系将各元素用指针链接起来。变长的线性存储结构对线性表的长度不加限制。

## 2. 顺序表  

把采用顺序存储结构的线性表简称为**顺序表**，也称为**向量**，有以下主要特征：

1. 元素的数据类型**相同**。
2. 元素顺序的存储在一片**地址连续的存储空间**中，一个元素按照存储顺序有唯一的索引值，又称为下标，可以随机存取表中的元素。
3. 逻辑关系相邻的两个元素在物理位置上也相邻。
4. 在程序中，数组变量说明语句一般使用常数作为向量长度，长度是静态常熟，在程序执行时不变。

#### 2.1顺序表的实现

> *见* [_02_ArrayList.cpp](https://github.com/likaikkk/DataStructuresAndAlgorithms/blob/master/code/_02_ArrayList.cpp )

#### 2.2顺序表的应用

> 求两个顺序表的差集：见[__03_DifferenceOfSeqList.cpp_]()

## 3. 链表

#### 3.1单链表

#### 3.2双向链表

#### 3.3循环链表

#### 3.4链表的应用

## 4. 栈

## 5. 队列

### 6. 字符串
#include<iostream>

using namespace std;

//������Ľ�㶨��
template<class T>
class LinkNode {
public:
    T data;                 //������
    LinkNode<T>* link;      //ָ����
    LinkNode() {}
    LinkNode(const T& el, LinkNode<T>* ptr = 0) {
        data = el;
        link = ptr;
    }
    /* 
    LinkNode<T>* ptr = 0 �е� ptr = 0 ��ʾ��ָ�� ptr ��ʼ��Ϊ��ָ�루nullptr����
    �� C++ �У���ָ��ͨ�������� 0 ���߹ؼ��� nullptr ����ʾ��

    ������ض��Ĺ��캯���У�LinkNode(const T& el, LinkNode<T>* ptr = 0)���ڶ������� ptr ��һ����ѡ����������ζ���ڵ��ù��캯��ʱ���Բ��ṩ���������������ṩ�Ļ����ͻ�ʹ��Ĭ��ֵ��Ĭ��ֵ����������Ϊ 0������ָ�롣

    �������������ڴ����ڵ��ʱ�����ѡ���Ƿ���һ��ָ����һ���ڵ��ָ�롣������ṩ�����ָ�룬�ڵ㽫���ӵ��ṩ�Ľڵ㣬���û���ṩ����������ʼ��Ϊһ����ָ�룬��ʾ�ýڵ㲻���ӵ��κ������ڵ㣬�����������е����һ���ڵ㡣
     */
};

//����������Ͷ���
template<class T>
class LinkList
{
private:
    LinkNode<T>* head, * tail;      //��ͷ�ͱ�βָ��
    //��¼��ǰ����λ�õ�ָ�룬�ɲ����ɾ����������
    /* prevPtr��ǰ��ָ�룩����ָ��ǰλ�õ�ǰһ���ڵ㡣�ڲ����ɾ���ڵ�ʱ����Ҫ֪��ǰһ���ڵ㣬�Ա���ȷ�ؽ�����ά����������ӡ�

currPtr����ǰָ�룩����ָ��ǰλ�ýڵ㡣������������ͽڵ��������Ҫָ�룬�����������ʵ�ǰλ�ýڵ�������Լ����в��롢ɾ���Ȳ����� */
    LinkNode<T>* prevPtr, * currPtr;
    int position;                   //��ǰԪ���ڱ��е�λ����ţ��ɺ���resetʹ��
public:
    LinkList() {
        head = new LinkNode<T>; //����һ������ͷ���
        tail = head;
        position = 0;
        prevPtr = currPtr = head;
    }
    ~LinkList() {
        clear();
        delete head;
    }
    int getSize()const;             //����������Ԫ�ظ���
    bool isEmpty()const;            //�����Ƿ�Ϊ��
    void reset(int pos = 0);        //��ʼ��ָ���λ�ã���һλ����λ������Ϊ0��
    void next();                    //ʹָ���ƶ�����һ�����
    bool endOfList()const;          //ָ���Ƿ�����β
    int currentPosition(void);      //����ָ�뵱ǰλ��
    void insertHead(const T& item); //�ڱ�ͷ������
    void insertTail(const T& item); //�ڱ�β������
    void insertAt(const T& item);   //�ڵ�ǰ���֮ǰ������
    void insertAfter(const T& item);//�ڵ�ǰ���֮�������
    void deleteCurrent();           //ɾ����ǰ���
    T& data();                      //���ضԵ�ǰ����Ա���ݵ�����
    /* �������const��ζ��Ϊ����Ա���������ص�ֵҲ������const����
    �� LinkList ���У�const T& data()const; ����һ���Ե�ǰ�ڵ����ݵĳ����ã�����ζ�ŵ��øú����Ĵ��벻��ͨ����������޸����ݡ�������ص��Ƿǳ����ã���ô�����߿��ܻ����ɿ���ͨ����������޸����ݣ����볣����Ա�����������ͼ��㣡�*/
    void clear();                   //�������
    LinkNode<T>* setPos(int i);     //����ָ��λ��i��ָ��
    bool insertPos(const int i, const T value);//��ָ��λ�ò�����
    bool deletePos(const int i);    //ɾ��ָ��λ�õĽ��
    bool invert();                  //��ת��������
};

//�������
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

//����ָ��λ��i��ָ��
template<class T>
LinkNode<T>* LinkList<T>::setPos(int i)
{
    if (i == -1)                         //iΪ-1��λ��ͷ���
        return head;
    int count = 0;
    LinkNode<T>* p = head->link;
    while (p != NULL && count < i) {
        p = p->link;
        count++;
    }
    return p;                           //ָ���i����㣬��������С��iʱ����NULL
}

//���뵥����ĵ�i�����
template<class T>
bool LinkList<T>::insertPos(const int i, const T value)
{
    LinkNode<T>* p = setPos(i - 1);         //p�ǵ�i������ǰ��
    LinkNode<T>* q;                         //q���²���Ľ��        
    if(p==NULL)
    {
        cout << "�������������" << endl;
        return false;
    }
    q = new LinkNode<T>(value, p->link);    // ����һ���µĽڵ�q������ֵΪvalue��ָ��ָ��p�ĺ�̽ڵ�
    p->link = q;                            // ��p��ָ��ָ���½ڵ�q
if (p == tail)                              //�ڱ�β���в������
        tail = q;
    return true;
}

//ɾ��ָ�����
template<class T>
bool LinkList<T>::deletePos(const int i)
{
    LinkNode<T>* p, * q;
    if ((p = setPos(i - 1)) == NULL||p==tail) {
        cout << "�Ƿ�ɾ����" << endl;
        return false;
    }
    q = p->link;                //qΪ������ɾ����
    p->link = q->link;
    
    if (q == tail)              //ɾ����Ϊ��β���޸�βָ��
        tail = p;
    
    delete q;
    return true;
}

//��ת���
template<class T>
bool LinkList<T>::invert()
{
    LinkNode<T>* q, * p, *R;
    p = head->link;             //��pָ���׽��
    q = NULL;                   //q����ִ��p��ǰһ�����    
    while (p != NULL) {             
        R = q;                  //��r�ӵ�q֮��
        q = p;                  //q�ӵ�p֮��    
        p = p->link;            //p�ƶ�����һ�����    
        q->link = R;            //q�ӵ�֮ǰ�Ľ��    
    }
    tail = head->link;
    head->link = q;
    return true;
}

//��������Ԫ�ظ���
template<class T>
int LinkList<T>::getSize() const
{
    LinkNode<T>* p=head->link;
    int i = 0;
    for (;p != NULL;i++)
        p = p->link;
    return i;
}

//�����Ƿ�Ϊ��
template<class T>
bool LinkList<T>::isEmpty() const
{
    return head->link == NULL;
}

//��ʼ��ָ���λ��
template<class T>
void LinkList<T>::reset(int pos)
{
    if (pos<0 || pos>getSize()) {
        cout << "Invalid position." << endl;
        return;
    }
    position = pos;  //���¼�¼��ǰλ��
    //��������currPtr��prevPtr
    prevPtr = head;
    currPtr = head->link;
    for (int i = 0; i < position; i++) {
        next();
    }
}

//ʹָ���ƶ�����һ�����
template<class T>
void LinkList<T>::next()
{
    if (currPtr != NULL) {
        prevPtr = currPtr;
        currPtr = currPtr->link;
        position++;
    }
}

//ָ���Ƿ�����β
template<class T>
bool LinkList<T>::endOfList() const
{
    return currPtr == NULL;
}

//���ص�ǰָ��λ��
template<class T>
int LinkList<T>::currentPosition(void)
{
    return position;
}

//�ڱ�ͷ������
template<class T>
void LinkList<T>::insertHead(const T& item)
{
    LinkNode<T>* newNode = new LinkNode<T>(item, head->link);           //�����½�㣬��ָ��ָ��ԭͷ������һ�����
    head->link = newNode;         //��ͷ����ָ��ָ���½��
    if (tail == head)             //�������Ϊ�գ�����βָ��
        tail = newNode;
}

//�ڱ�β������
template<class T>
void LinkList<T>::insertTail(const T& item)
{
    LinkNode<T>* newNode = new LinkNode<T>(item);

    if (isEmpty()) {
        head->link = newNode;
        tail = newNode;
    } else {
        tail->link = newNode;  // ����ǰ��β����ָ����ָ���½ڵ�
        tail = newNode;        // ����βָ�룬ָ���½ڵ�
    }
}

//�ڵ�ǰ���֮ǰ������
template<class T>
void LinkList<T>::insertAt(const T& item) {
    LinkNode<T>* newNode = new LinkNode<T>(item, currPtr);
    prevPtr->link = newNode;
    currPtr = newNode;
}

//�ڵ�ǰ���֮�������
template<class T>
void LinkList<T>::insertAfter(const T& item)
{
    /* ��Ҫע�⣬��� currPtr ǡ��ָ�������β�ڵ㣬��ô���ʵ�ֿ��ܻᵼ�´�����Ϊ��β�ڵ�֮��û�нڵ㣬ֱ�ӽ��½ڵ���� currPtr->link ���ܻᵼ���쳣��Ϊ�����ԣ��� insertAfter �����У�����Ҫ����Ƿ񵽴���β�ڵ㣬Ȼ����������������½ڵ�Ĳ����� */
    if (currPtr == tail)
        insertTail(item);
    else {
        LinkNode<T>* newNode = new LinkNode<T>(item, currPtr->link);
        currPtr->link = newNode;
    }
}

//ɾ����ǰ���
template<class T>
void LinkList<T>::deleteCurrent()
{
    if (currPtr == NULL) {
        cout << "No current node to delete." << endl;
        return;
    }
    LinkNode<T>* temp = currPtr;  // ���浱ǰ�ڵ�ָ��

    // ��ǰһ���ڵ��ָ�����ӵ���ǰ�ڵ����һ���ڵ�
    prevPtr->link = currPtr->link;

    // �����ǰ�ڵ���β�ڵ㣬����βָ��
    if (currPtr == tail)
        tail = prevPtr;

    // ���µ�ǰ�ڵ�ָ���ǰһ���ڵ�ָ��
    currPtr = currPtr->link;
    delete temp;  // �ͷ��ڴ�
}

//���ضԵ�ǰ����Ա���ݵ�����
template<class T>
T& LinkList<T>::data()
{
    if (currPtr == NULL)
        // cout << "No current node" << endl;
        /*�ڵ�ǰ�ڵ�Ϊ�գ�currPtr == NULL��ʱ����ֻ�Ǵ�ӡ����Ϣ��û��ʵ�ʷ����κζ�����
        ����������£�Ӧ�þ�������ʲôֵ�������׳�һ���쳣��
        �����ϣ���ڵ�ǰ�ڵ�Ϊ��ʱ����һ��Ĭ��ֵ�����Կ��Ƿ���һ�����ã�����������һ��Ĭ��ֵ�������ϣ���ڵ�ǰ�ڵ�Ϊ��ʱ�׳��쳣������ʹ������ throw �����ʵ�֡�*/
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

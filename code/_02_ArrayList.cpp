#include<iostream>

using namespace std;

template<class T>       //线性表的元素类型为T
class ArrayList         //定义顺序表ArrayList
{
private:
    T* arrayList;       //存储顺序表的实例
    int maxSize;
    int curLen;
    //int position;
public:
    ArrayList(const int size) {
        if (size < 1) {
            cout << "Size must be greater than 0";
            throw - 1;
        }
        maxSize = size;
        arrayList = new T[maxSize];
        curLen = 0;
        //position = 0;
    }
    ~ArrayList() {
        delete[] arrayList;
    }
    void clear() {
        delete[]arrayList;
        curLen = 0;
        //position = 0;
        arrayList = new T[maxSize];
    }
    int Length();
    void Show();
    bool Append(const T value);
    bool Insert(const int p, const T value);
    bool Delete(const int p);
    bool GetValue(const int p, T& value);
    bool SetValue(const int p, const T value);
    bool GetPos(int& p, const T value);
    int Search(T x);
};

template<class T>
int ArrayList<T>::Length()
{
    return curLen;
}

template<class T>
void ArrayList<T>::Show()
{
    for (int i = 0;i < curLen;i++) {
        cout << arrayList[i] << " ";
    }
    cout << endl;
}

template<class T>
bool ArrayList<T>::Append(const T value)
{
    if (curLen >= maxSize) {
        cout << "The List is overflow" << endl;
        return false;
    }
    arrayList[curLen] = value;
    curLen++;
    return true;
}

template<class T>
bool ArrayList<T>::Insert(const int p, const T value)
{
    if (curLen >= maxSize) {
        cout << "The List is overflow" << endl;
        return false;
    }
    if (p<0 || p>curLen) {
        cout << "Insertion point is illegal" << endl;
        return false;
    }
    for (int i = curLen;i > p;i--) {
        arrayList[i] = arrayList[i - 1];
    }
    arrayList[p] = value;
    curLen++;
    return true;
}

template<class T>
bool ArrayList<T>::Delete(const int p)
{
    if (curLen <= 0) {
        cout << "No element to delete" << endl;
        return false;
    }
    if (p<0 || p>curLen) {
        cout << "Deletion is illegal" << endl;
        return false;
    }
    for (int i = p;i < curLen - 1;i++) {
        arrayList[i] = arrayList[i + 1];
    }
    curLen--;

    return true;
}

template<class T>
bool ArrayList<T>::GetValue(const int p, T& value)
{
    if (p<0 || p>curLen) {
        cout << "Position is illegal" << endl;
        return false;
    }
    value = arrayList[p];
    return true;
}

template<class T>
bool ArrayList<T>::SetValue(const int p, const T value)
{
    if (p<0 || p>curLen) {
        cout << "Position is illegal" << endl;
        return false;
    }
    arrayList[p] = value;
    return true;
}

template<class T>
bool ArrayList<T>::GetPos(int& p, const T value)
{
    for (int i = 0;i < curLen;i++) {
        if (arrayList[i] == value)
        {
            p = i + 1;
            return true;
        }
    }
    return false;
}

template<class T>
int ArrayList<T>::Search(T x)
{
    for (int i = 0;i < curLen;i++)
        if (arrayList[i] == x)
            return i;
    return -1;
}
/*
int main() {
    ArrayList<int> arr(5);

    cout << "Appending values:" << endl;
    for (int i = 0; i < 5; i++) {
        arr.Append(i * 2);
    }

    cout << "Length of the list: " << arr.Length() << endl;

    cout << "Inserting value 10 at position 2:" << endl;
    arr.Insert(2, 10);

    cout << "List after insertion:" << endl;
    for (int i = 0; i < arr.Length(); i++) {
        int value;
        arr.GetValue(i, value);
        cout << value << " ";
    }
    cout << endl;

    cout << "Deleting value at position 3:" << endl;
    arr.Delete(3);

    cout << "List after deletion:" << endl;
    for (int i = 0; i < arr.Length(); i++) {
        int value;
        arr.GetValue(i, value);
        cout << value << " ";
    }
    cout << endl;

    int pos;
    bool found = arr.GetPos(pos, 6);
    if (found) {
        cout << "Value 6 found at position: " << pos << endl;
    }
    else {
        cout << "Value 6 not found in the list" << endl;
    }

    int index = arr.Search(8);
    if (index != -1) {
        cout << "Value 8 found at index: " << index << endl;
    }
    else {
        cout << "Value 8 not found in the list" << endl;
    }

    return 0;
}
*/
//顺序表的差集
#include "_02_ArrayList.cpp"

template <class T>
//删除A中出现的B元素的函数
void DelElem(ArrayList<T>* A, ArrayList<T>* B) {
    int i, flag, pos;
    T value;
    for (i = 0;i < B->Length();i++) {
        B->GetValue(i, value);
        flag = A->GetPos(pos, value);
        if (flag == true) {
            if (pos >= 0) {
                A->Delete(pos);     //如果找到该元素，将其从A中删除
            }
        }
    }
}


int main() {
    int i, j, flag;
    ArrayList<int> A = ArrayList<int>(20);
    ArrayList<int> B = ArrayList<int>(20);

    for (i = 1;i <= 10;i++) {
        if (A.Append(i) == false) {
            cout << "位置不合法" << endl;
            return 0;
        }
    }
    for (i = 1,j=1;j <= 6;i=i+2,j++) {
        if (B.Append(i) == false) {
            cout << "位置不合法" << endl;
            return 0;
        }
    }
    cout << "顺序表A中的元素：" << endl;
    A.Show();
    cout << "顺序表B中的元素：" << endl;
    B.Show();
    cout << "将在A中出现B的元素删除后A中的元素： " << endl;
    DelElem(&A, &B);
    A.Show();
    return 0;
}
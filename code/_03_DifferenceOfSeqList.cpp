//˳���Ĳ
#include "_02_ArrayList.cpp"

template <class T>
//ɾ��A�г��ֵ�BԪ�صĺ���
void DelElem(ArrayList<T>* A, ArrayList<T>* B) {
    int i, flag, pos;
    T value;
    for (i = 0;i < B->Length();i++) {
        B->GetValue(i, value);
        flag = A->GetPos(pos, value);
        if (flag == true) {
            if (pos >= 0) {
                A->Delete(pos);     //����ҵ���Ԫ�أ������A��ɾ��
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
            cout << "λ�ò��Ϸ�" << endl;
            return 0;
        }
    }
    for (i = 1,j=1;j <= 6;i=i+2,j++) {
        if (B.Append(i) == false) {
            cout << "λ�ò��Ϸ�" << endl;
            return 0;
        }
    }
    cout << "˳���A�е�Ԫ�أ�" << endl;
    A.Show();
    cout << "˳���B�е�Ԫ�أ�" << endl;
    B.Show();
    cout << "����A�г���B��Ԫ��ɾ����A�е�Ԫ�أ� " << endl;
    DelElem(&A, &B);
    A.Show();
    return 0;
}
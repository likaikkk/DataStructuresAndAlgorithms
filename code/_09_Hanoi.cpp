#include<iostream>
using namespace std;

void Hanoi(int n, char A, char B, char C) {
    if (n == 1) {//only one disk
        cout << "Move disk from " << A << " to " << C << endl;
    }
    else {
        Hanoi(n - 1, A, C, B);//First move n-1 disks from pole A to pole B with the aid of pole B
        cout << "Move disk from " << A << " to " << C << endl;//Move the remaining disk from pole A to pole C
        Hanoi(n - 1, B, A, C);//Finally move the n-1 disks previously moved to the B to the pole C with the aid of pole A
    }
}

int main() {
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;

    Hanoi(n, 'A', 'B', 'C');

    return 0;
}
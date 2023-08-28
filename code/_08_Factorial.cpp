#include<iostream>
using namespace std;

    long factorial(long n) {
        if (n == 0)
            return 1;
        return n * factorial(n - 1);
    }

int main(){
    int n = 10;
    cout << factorial(n);
    return 0;
}
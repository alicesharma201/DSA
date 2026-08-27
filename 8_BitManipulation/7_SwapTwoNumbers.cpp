#include<bits/stdc++.h>
using namespace std;
int main(){
    int a = -2, b = 7;

    cout << "a = " << a << ", b = " << b << endl;

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    cout << "a = " << a << ", b = " << b << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
void modify(int a, int &A){
    a += 10;
    A += 10;
}
int main(){
    int a = 1;
    int A = 10;
    modify(a, A);
    cout << "a = " << a << '\n'; // pass by value
    cout << "A = " << A << '\n'; // pass by refernce
    return 0;
}
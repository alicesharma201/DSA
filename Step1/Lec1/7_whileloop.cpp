#include <bits/stdc++.h>
using namespace std;
int main(){;
    int i = 0;
    int n = 10;
    int a = 0;
    int b = 1;
    int c = 0;

    while(i < n){
        cout << a << '\n';
        c = a + b;
        a = b;
        b = c;
        i++;
    }
    return 0;
}
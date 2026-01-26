#include<bits/stdc++.h>
// 123
// num = 3
// n = 12
// reverse = 3

// num = 2
// n = 1
// reverse = 32

// num = 1
// n = 0
// reverse = 321

int revnum(int n){
    int num = 0, reverse = 0;
    while(n > 0){
        num = n % 10;
        n = n / 10;
        reverse = (reverse*10)+num;
    }
    return reverse;
}

int main(){
    int n;
    cin >> n;
    cout << revnum(n);
    return 0;
}
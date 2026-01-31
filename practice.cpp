#include<bits/stdc++.h>

int recursion(int n){
    int sum;
    if(n == 1) return 1;
    sum = n + recursion(n-1);
    return sum;
}

int main(){
    int n;
    cin >> n;
    cout << recursion(n);
    return 0;
}
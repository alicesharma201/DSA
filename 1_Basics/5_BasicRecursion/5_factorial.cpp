#include <bits/stdc++.h>
int brute(int n){
    int fact = 1;
    for(int i = 1; i <= n; i++){
        fact *= i;
    }
    return fact;
}
int recursion(int n){
    int fact;
    if(n == 1 || n == 0) return 1;
    fact = n * recursion(n-1);
    return fact;
}
int main(){
    int n;
    cin >> n;
    cout << brute(n) << endl;
    cout << recursion(n) << endl;
    return 0;
}
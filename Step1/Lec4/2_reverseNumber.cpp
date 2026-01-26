// Problem Statement: Given an integer N return the reverse of the given number.
#include<bits/stdc++.h>
int rev(int n){
    int reverse = 0;
    int extract;
    while(n > 0){
        extract = n % 10;
        reverse = (reverse*10) + extract;
        n = n / 10;
    }
    return reverse;
}
int main(){
    int n;
    cin >> n;
    cout << rev(n);
    return 0;
}
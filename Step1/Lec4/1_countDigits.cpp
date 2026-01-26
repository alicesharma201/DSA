// Problem Statement: Given an integer N, return the number of digits in N.
#include <bits/stdc++.h>
int count(int n){ // approach 1
    int cnt = 0;
    while(n > 0){
        cnt = cnt + 1;
        n = n / 10;
    }
    return cnt;
}
int count2(int n){ // approach 2 (optimal)
    int cnt = (int)(log10(n)+1);
    return cnt;
}
int main(){
    int n;
    cin >> n;
    cout << count(n) << endl;
    cout << count2(n) << endl;
    return 0;
}
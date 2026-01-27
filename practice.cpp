#include <bits/stdc++.h>
bool check(int n){
    int degree = 0;
    int copy = n;
    int original = n;
    int sum = 0;
    
    while(copy > 0){
        copy = copy / 10;
        degree++;
    }

    while(n > 0){
        int extract = n % 10;
        sum += pow(extract, degree);
        n = n / 10;
    }

    if(sum == original) return true;
    return false;
}
int main(){
    int n;
    cin >> n;
    cout << check(n);
    return 0;
}
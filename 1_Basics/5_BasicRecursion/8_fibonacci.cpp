#include <bits/stdc++.h>

void self1(int n){ // TC: O(n) SC: O(1)
    int first = 0;
    int second = 1;
    int next;
    for(int i = 0; i <= n; i++){
        cout << first << " ";
        next = first + second;
        first = second;
        second = next;
    }
}

void self2(int n, int first, int second){ // TC: O(n) SC: O(n)
    if(n < 0) return;
    cout << first << " ";
    int next = first + second;
    first = second;
    second = next;
    self2(n-1, first, second); 
}

void brute(int n){ // TC: O(n)+O(n) SC: O(n)
    int fib[n+1];
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2; i <= n; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
    for(int i = 0; i <= n; i++) cout << fib[i] << " ";
}

int main(){
    int n;
    cin >> n;

    cout << "Self1: ";
    self1(n); 
    cout << endl;

    cout << "Self2: ";
    self2(n, 0, 1);
    cout << endl;

    cout << "Brute: ";
    brute(n);
    cout << endl;
    
    return 0;
}
#include <bits/stdc++.h>
int brute(int n){
    int sum = 0;
    for(int i = 1; i <= n; i++) sum += i;
    return sum;
}
int formula(int n){
    int sum;
    sum = (n*(n+1))/2;
    return sum;
}
int recursion(int n){
    int sum;
    if(n == 1) return 1;
    sum = n + recursion(n-1);
    return sum;
}
/* Recursive tree
recursion(5)
   |
   └── 5 + recursion(4)
            |
            └── 4 + recursion(3)
                     |
                     └── 3 + recursion(2)
                              |
                              └── 2 + recursion(1)
                                       |
                                       └── 1   (base case)
*/
int main(){
    int n;
    cin >> n;
    cout << brute(n) << endl;
    cout << formula(n) << endl;
    cout << recursion(n) << endl;
    return 0;
}
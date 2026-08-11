#include<bits/stdc++.h>
using namespace std;
int recursiveGood(long long n){
    // TC: O(n)
    // SC: O(n)
    // but gives runtime error at n = 50 on leetcode
    if(n == 0) return 1;
    if(n % 2 == 0) return 4*recursiveGood(n-1); // odd idx: 2, 3, 5, 7 = 4 digits
    else return 5*recursiveGood(n-1); // even idx: 0, 2, 4, 6, 8 = 5 digits
}
int main(){
    int n = 5; // 5*5*5*4*4 = 1600
    cout << recursiveGood(n) << endl;
    return 0;
}
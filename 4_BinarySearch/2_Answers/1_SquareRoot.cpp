#include<bits/stdc++.h>
int linearSquareRoot(int n){
    // TC: O(n)
    // SC: O(1)
    int sq = 0;
    for(int i = 1; i <= n; i++){
        if((long long)i*i <= n) sq = i;
        else break;
    }
    return sq;
}
int binarySquareRoot(int n){
    // TC: O(logn)
    // SC: O(1)
    if(n == 0) return 0;
    int low = 1, high = n;
    int sq = 0;
    while(low <= high){
        int mid = low + (high - low)/2;
        if((long long)mid * mid <= n){
            sq = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return sq;
}
int main(){
    int n = 8;
    cout << linearSquareRoot(n) << endl;
    cout << binarySquareRoot(n) << endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int bruteCount(int n){
    // TC: O(logn) because A right shift by 1 is equivalent to: n = n / 2;
    // SC: O(1)
    int cnt = 0;
    while(n){
        cnt += (n & 1); // n & 1 is also used for odd check in CP becuase last digit of an odd number is always 1 in binary
        n = n >> 1;
    }
    return cnt;
}
int optimalCount(int n){
    // TC: O(k) where k is no. of set bits or no. of 1s present in n
    // SC: O(1)
    int cnt = 0;
    while(n){
        n = n & n-1;
        cnt++;
    }
    return cnt;
}
int main(){
    cout << bruteCount(13) << endl;
    cout << __builtin_popcount(13) << endl; // stl
    cout << optimalCount(13) << endl;
    return 0;
}
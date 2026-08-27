#include<bits/stdc++.h>
using namespace std;
bool brute(int n, int i){
    // TC: O(logn)
    // SC: O(logn)
    string b;
    while(n > 0){
        b += (n % 2 == 0 ? '0' : '1');
        n /= 2;
    }
    // instead of reversing it we're gonna count from the front
    if(i >= b.size()) return false;
    return (b[i]-'0');
}

// TC: O(1)
// SC: O(1)
bool leftShift(int n, int i){
    return (n & (1 << i));
}
bool rightShift(int n, int i){
    return ((n >> i) & 1);
}
int main(){
    // we're checking (from behind) if the ith bit is set(1) or not(0)
    cout << boolalpha << brute(13, 2) << endl;
    cout << boolalpha << leftShift(13, 2) << endl;
    cout << boolalpha << rightShift(13, 2) << endl;
    return 0;
}
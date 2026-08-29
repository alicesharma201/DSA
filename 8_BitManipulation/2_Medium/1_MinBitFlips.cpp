#include<bits/stdc++.h>
using namespace std;
int minBitFlips(int start, int goal){
    // TC: O(k) no. of set bits
    // SC: O(1)
    int diff = start ^ goal; // xor gives different bits as 1
    int cnt = 0; // count set bits
    while(diff){
        diff = diff & diff-1;
        cnt++;
    }
    return cnt;
}
int main(){
    cout << minBitFlips(10, 7);
    return 0;
}

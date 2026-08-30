#include<bits/stdc++.h>
using namespace std;
int bruteXorRange(int L, int R){
    // TC: O(R-L)
    // SC: O(1)
    int ans = 0;
    for(int i = L; i <= R; i++){
        ans ^= i;
    }
    return ans;
}
int xor1toN(int n){
    if(n % 4 == 1) return 1;
    if(n % 4 == 2) return n+1;
    if(n % 4 == 3) return 0;
    return n;
}
int optimalXorRange(int L, int R){
    // idea: (3 ^ 4 ^ 5) = (1 ^ 2) ^ (1 ^ 2 ^ 3 ^ 4 ^ 5)
    // TC: O(1)
    // SC: O(1)
    return xor1toN(L-1) ^ xor1toN(R);
}
int main(){
    cout << bruteXorRange(3, 5) << endl;
    cout << optimalXorRange(3, 5) << endl;
    return 0;
}
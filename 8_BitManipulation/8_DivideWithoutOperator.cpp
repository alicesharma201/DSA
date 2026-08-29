#include<bits/stdc++.h>
using namespace std;
int bruteDivide(int dividend, int divisor){
    // TC: O(dividend) when divisor is 1 (worst case)
    // SC: O(1)
    if(dividend == INT_MIN && divisor == -1) return INT_MAX;

    int sign = 1;
    if((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) sign = -1;

    long long dend = dividend;
    long long sor = divisor;
    dend = abs(dend); // int abs(INT_MIN) ❌ -> long long abs(INT_MIN) ✅
    sor = abs(sor);

    long long sum = 0, cnt = 0;
    while(sum + sor <= dend){
        sum += sor;
        cnt++;
    }

    if(sign < 0) return -cnt;
    return cnt;
}
int optimalDivide(int dividend, int divisor){
    // TC: O((logn)^2)
    // SC: O(1)
    bool sign = true;
    if((dividend >= 0 && divisor < 0) || (dividend < 0 && divisor > 0)) sign = false;
    long dend = dividend; dend = abs(dend);
    long sor = divisor; sor = abs(sor);
    long cnt = 0;
    while(dend >= sor){
        int x = 0;
        while((sor << (x+1)) <= dend) x++;
        dend -= (sor << x);
        cnt += (1 << x); // 2^x
    }
    if(cnt == (1 << 31) && sign) return INT_MAX; // case: INT_MIN, 1
    if(cnt == (1 << 31) && !sign) return INT_MIN; // case: INT_MIN, -1
    return sign ? cnt : -cnt;
}
int main(){
    cout << bruteDivide(22, -3) << endl;
    cout << optimalDivide(22, -3) << endl;
    return 0;
}
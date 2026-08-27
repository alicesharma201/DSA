#include<bits/stdc++.h>
using namespace std;
string decimalToBinary(int n){
    // TC: O(log(n)) base 2
    // SC: O(log(n))
    if(n == 0) return "0";
    string res = "";
    while(n > 0){
        if(n % 2 == 1) res += "1";
        else res += "0";
        n /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
}
int binaryToDecimal(string num){
    // TC: O(n)
    // SC: O(1)
    int n = num.size();
    int res = 0;
    int p2 = 1;
    for(int i = n-1; i >= 0; i--){
        if(num[i] == '1')
            res += ((num[i]-'0') * p2);
        p2 *= 2;
    }
    return res;
}
int main(){
    cout << decimalToBinary(13) << endl;
    cout << binaryToDecimal("1101") << endl;
    // Right shift ">>" : 13 >> 1 = 13 / 2^1 = 6
    //  Left shift "<<" : 13 << 1 = 13 * 2^1 = 26
    return 0;
}
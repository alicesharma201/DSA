#include<bits/stdc++.h>
int stringToInteger(string s){
    // TC: O(n)
    // SC: O(1)
    if(s.empty()) return 0;
    int i = 0, n = s.size();

    while(i < n && s[i] == ' ') i++;
    if(i == n) return 0;

    int sign = 1;
    if(s[i] == '+') i++;
    else if(s[i] == '-'){
        sign = -1;
        i++;
    }
    
    long long res = 0;
    while(i < n && isdigit(s[i])){
        int digit = s[i] - '0';
        res = res * 10 + digit;
        if(sign * res >= INT_MAX) return INT_MAX;
        if(sign * res <= INT_MIN) return INT_MIN;
        i++;
    }

    return sign * res;
}
int main(){
    string s = "  -2231";
    // string s = " 442 hello";
    cout << stringToInteger(s) << endl;
    return 0;
}
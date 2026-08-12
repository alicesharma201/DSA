#include<bits/stdc++.h>
using namespace std;
int helper(string s, int i, long long res, int sign){
    if(i >= s.size() || !isdigit(s[i])) return (sign * res);
    res = (res * 10) + s[i]-'0';
    if((sign * res) >= INT_MAX) return INT_MAX;
    if((sign * res) <= INT_MIN) return INT_MIN;
    return helper(s, i+1, res, sign);
}
int recursiveStoI(string s, int i = 0){
    // TC: O(n)
    // SC: O(n)
    while(i < s.size() && s[i] == ' ') i++;
    int sign = 1;
    if(i < s.size()){
        if(s[i] == '+') i++;
        else if(s[i] == '-'){ sign = -1; i++; }
    }
    return helper(s, i, 0, sign);
}
int main(){
    string s = "    -1123hello";
    int n = s.size();
    cout << recursiveStoI(s);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
bool helper(int i, string& s, unordered_set<string>& st){
    if(i == s.size()) return true;
    if(st.find(s) != st.end()) return true;
    for(int l = 1; l <= s.size(); l++){
        string temp = s.substr(i, l);
        if(st.find(temp) != st.end() && helper(i+l, s, st)) return true;
    }
    return false;
}
bool wordBreak(string s, vector<string>& dict){
    // this will give TLE on lc, we need dp to fix it
    // TC: O(n^2 * 2^n)
    // SC: O(n)
    unordered_set<string> st(dict.begin(), dict.end());
    return helper(0, s, st);
}
int main(){
    string s = "applepenapple";
    vector<string> dict = {"apple", "pen"};
    cout << boolalpha << wordBreak(s, dict);
    return 0;
}
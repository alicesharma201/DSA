#include<bits/stdc++.h>
bool isomorphic(string s, string t){
    // TC: O(n)
    // SC: O(1) becuase of ascii
    int S = s.size(), T = t.size();
    unordered_map<char,char> hash1;
    unordered_map<char,char> hash2;
    if(S != T) return false;
    for(int i = 0; i < S; i++){
        if(hash1.find(s[i]) == hash1.end()) hash1[s[i]] = t[i];
        if(hash1[s[i]] != t[i]) return false;
    }
    for(int i = 0; i < T; i++){
        if(hash2.find(t[i]) == hash2.end()) hash2[t[i]] = s[i];
        if(hash2[t[i]] != s[i]) return false;
    }
    return true;
}
int main(){
    string s = "paper";
    string t = "title";
    cout << (isomorphic(s, t) ? "True" : "False") << endl; 
    return 0;
}
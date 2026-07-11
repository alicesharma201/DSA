#include<bits/stdc++.h>
bool bruteCheckAnagrams(string s, string t){
    // TC: O(nlogn)
    // SC: O(1)
    int S = s.size(), T = t.size();
    if(S != T) return false;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    for(int i = 0; i < S; i++){
        if(s[i] != t[i]) return false;
    }
    return true;
}
bool optimalCheckAnagrams(string s, string t){
    // TC: O(n)
    // SC: O(1)
    int S = s.size(), T = t.size();
    if(S != T) return false;
    int arr[256] = {0};
    for(int i = 0; i < S; i++){
        arr[s[i]]++;
    }
    for(int i = 0; i < T; i++){
        if(arr[t[i]] == 0) return false;
        else arr[t[i]]--;
    }
    return true;
}
int main(){
    string s = "anagram";
    string t = "nagaram";
    cout << (bruteCheckAnagrams(s, t) ? "true" : "false") << endl;
    cout << (optimalCheckAnagrams(s, t) ? "true" : "false") << endl;
    return 0;
}
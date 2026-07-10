#include<bits/stdc++.h>
string longestCommonPrefix(vector<string>& strs){
    // TC: O(nlog(mn))
    // SC: O(1)
    int n = strs.size();
    string res = "";
    if(strs.empty()) return res;
    sort(strs.begin(), strs.end());
    string first = strs[0], last = strs[n-1];
    int f = strs[0].size(), l = strs[n-1].size();
    int minSize = min(f, l);
    for(int i = 0; i < minSize; i++){
        if(first[i] == last[i]) res += first[i];
        else break;
    }
    return res;
}
int main(){
    vector<string> strs = {"flower","flow","flight"};
    cout << longestCommonPrefix(strs) << endl;
    return 0;
}
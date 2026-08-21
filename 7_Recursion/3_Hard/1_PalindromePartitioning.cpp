#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(string s, int start, int end){
    while(start <= end){
        if(s[start++] != s[end--]) return false;
    } return true;
}
void helper(int i, string s, vector<string>& val, vector<vector<string>>& res){
    if(i == s.size()){
        res.push_back(val);
        return;
    }
    for(int j = i; j < s.size(); j++){
        if(isPalindrome(s, i, j)){
            val.push_back(s.substr(i, j-i+1));
            helper(j+1, s, val, res);
            val.pop_back();
        }
    }
}
vector<vector<string>> palindromePartition(string s){
    // TC: O(n^2 * 2^n)
    // SC: O(n * 2^n)
    vector<vector<string>> res;
    vector<string> val;
    helper(0, s, val, res);
    return res;
}
int main(){
    string s = "aabb";
    for(auto i : palindromePartition(s)){
        for(auto j : i){
            cout << j << ' ';
        } cout << endl;
    }
    return 0;
}
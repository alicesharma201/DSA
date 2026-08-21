#include<bits/stdc++.h>
using namespace std;
void helper(int i, string digits, vector<string>& letters, vector<string>& res, string val){
    if(i == digits.size()){
        res.push_back(val);
        return;
    }
    for(int x = 0; x < letters[digits[i]-'2'].size(); x++){
        helper(i+1, digits, letters, res, val+letters[digits[i]-'2'][x]);
    }
}
vector<string> letterCombinations(string digits){
    // TC: O(n * 4^n)
    // SC: O(n * 4^n)
    if(digits.empty()) return {};
    vector<string> letters = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;
    string val;
    helper(0, digits, letters, res, val);
    return res;
}
int main(){
    for(auto i : letterCombinations("23")){
        cout << i << " ";
    }
    return 0;
}
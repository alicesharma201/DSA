#include<bits/stdc++.h>
using namespace std;
bool isValid(string s){
    int balance = 0;
    for(char c : s){
        if(c == '(') balance++;
        else balance--;
        if(balance < 0) return false;
    }
    return balance == 0;
}
void generateVal(int n, string val, vector<string>& res){
    if(val.size() == 2*n){
        if(isValid(val)) 
            res.push_back(val);
        return;
    }
    generateVal(n, val+'(', res);
    generateVal(n, val+')', res);
}
vector<string> bruteGenerateParenthesis(int n){
    // TC: O(2^(2n) * n) = O(4^n * n)
    // SC: O(n * C(n))
    vector<string> res;
    generateVal(n, "", res);
    return res;
}
void backtrack(int n, string val, int open, int close, vector<string>& res){
    if(val.length() == 2*n){
        res.push_back(val);
        return;
    }
    if(open < n) backtrack(n, val+'(', open+1, close, res);
    if(close < open) backtrack(n, val+')', open, close+1, res);
}
vector<string> optimalGenerateParenthesis(int n){
    // TC: O(n * C(n))
    // SC: O(n * C(n))
    // Catalan number: C(n) = (2n)! / (n!(n+1)!) is the number of valid sequences.
    vector<string> res;
    backtrack(n, "", 0, 0, res);
    return res;
}
int main(){
    int n = 2;
    // vector<string> result = bruteGenerateParenthesis(n);
    vector<string> result = optimalGenerateParenthesis(n);
    for(string& s : result){
        cout << s << endl;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
vector<string> powerSet1(string str){
    // TC: O(n * 2^n)
    // SC: O(n * 2^n)
    int n = str.size();
    int total = 1 << n;
    vector<string> substrings;
    for(int mask = 0; mask < total; mask++){
        string val;
        for(int i = 0; i < n; i++){
            if(mask & 1 << i){
                val += str[i];
            }
        }
        substrings.push_back(val);
    }
    return substrings;
}
void includeExcludeDecision(string& str, string& val, int i, vector<string>& substrings){
    if(i == str.size()){
        substrings.push_back(val);
        return;
    }
    val.push_back(str[i]);
    includeExcludeDecision(str, val, i+1, substrings); // include
    val.pop_back();
    includeExcludeDecision(str, val, i+1, substrings); // exclude
}
vector<string> powerSet2(string str){
    // TC: O(n * 2^n)
    // SC: O(n * 2^n)
    int n = str.size();
    vector<string> substrings;
    string val;
    includeExcludeDecision(str, val, 0, substrings);
    return substrings;
}
int main(){
    string str = "abc";
    // string str = "aa";
    // vector<string> res = powerSet1(str); // bit manipulation
    vector<string> res = powerSet2(str); // recursion
    for(string i : res){
        cout << "\"" << i << "\"" << " ";
    }
    return 0;
}
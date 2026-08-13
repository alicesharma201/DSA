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
int main(){
    string str = "abc";
    // string str = "aa";
    vector<string> res = powerSet1(str); // bit manipulations
    for(string i : res){
        cout << "\"" << i << "\"" << " ";
    }
    return 0;
}
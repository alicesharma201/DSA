#include<bits/stdc++.h>
using namespace std;
void helper(int k, int n, int i, vector<vector<int>>& res, vector<int>& val){
    if(k == 0){
        if(n == 0) 
            res.push_back(val);
        return;
    }
    for(int x = i; x <= min(n,9); x++){
        val.push_back(x);
        helper(k-1, n-x, x+1, res, val);
        val.pop_back();
    }
}
vector<vector<int>> combinationSum3(int k, int n){
    // TC: O(k * 2^9)
    // SC: O(k)
    vector<vector<int>> res;
    vector<int> val;
    helper(k, n, 1, res, val);
    return res;
}
int main(){
    for(auto i : combinationSum3(3, 9)){
        for(int j : i){
            cout << j << " ";
        } cout << endl;
    }
    return 0;
}
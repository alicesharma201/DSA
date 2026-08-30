#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> powerSet(vector<int>& nums){
    // TC: O(n * 2^n)
    // SC: O(n * 2^n)
    vector<vector<int>> res;
    int n = nums.size();
    int total = 1 << n;
    for(int mask = 0; mask < total; mask++){
        vector<int> val;
        for(int i = 0; i < n; i++){
            if(mask & (1 << i)){
                val.push_back(nums[i]);
            }
        }
        res.push_back(val);
    }
    return res;
}
int main(){
    vector<int> nums = {1, 2, 3};
    for(auto i : powerSet(nums)){
        for(int j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
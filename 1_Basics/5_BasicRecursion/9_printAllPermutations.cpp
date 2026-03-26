#include<bits/stdc++.h>
using namespace std;
class BrutePermute{
    // TC: O(n! * n) number of permutations * applying recursion over size of each permutation
    // SC: O(n)+O(n) recursion stack + freq
    private:
    void recursivePermute(vector<int>& nums, vector<vector<int>>& ans, vector<int>& ds, vector<int>& freq){
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(!freq[i]){ // if number is not present in the hash array
                ds.push_back(nums[i]); // push
                freq[i] = 1; // mark
                recursivePermute(nums, ans, ds, freq);
                freq[i] = 0; // unmark
                ds.pop_back(); // pop
            }
        }
    }
    public:
    vector<vector<int>> permute(vector<int>& nums){
        vector<vector<int>> ans; // stores all permutations
        vector<int> ds; // current permutation
        vector<int> freq(nums.size(), 0); // tracks used elements in ds
        recursivePermute(nums, ans, ds, freq);
        return ans;
    }
};
class OptimalPermute{
    private:
    void recursivePermute(vector<int>& nums, vector<vector<int>>& ans, int p){
        if(p == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i = p; i < nums.size(); i++){
            swap(nums[i], nums[p]);
            recursivePermute(nums, ans, p+1);
            swap(nums[i], nums[p]);
        }
    }
    public:
    vector<vector<int>> permute(vector<int>& nums){
        vector<vector<int>> ans;
        recursivePermute(nums, ans, 0);
        return ans;
    }
};
int main(){
    vector<int> nums = {1, 2, 3};
    BrutePermute b;
    OptimalPermute o;
    // vector<vector<int>> result = p.permute(nums);
    vector<vector<int>> result = o.permute(nums);
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
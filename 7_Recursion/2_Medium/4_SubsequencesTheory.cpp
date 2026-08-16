#include<bits/stdc++.h>
using namespace std;

// Print all subsequences
void helper(int i, vector<int>& nums, vector<int>& val, vector<vector<int>>& res, int& k, int& sum){
    if(i == nums.size()){
        if(sum == k){
            res.push_back(val);
        }
        return;
    }
    val.push_back(nums[i]);
    sum += nums[i];
    helper(i+1, nums, val, res, k, sum); // pick
    val.pop_back();
    sum -= nums[i];
    helper(i+1, nums, val, res, k, sum); // not pick
}
vector<vector<int>> returnSubsequences(vector<int>& nums, int k){
    vector<vector<int>> res;
    vector<int> val;
    int sum = 0;
    helper(0, nums, val, res, k, sum);
    return res;
}

// Print one answer 
bool helperOne(int i, vector<int>& nums, vector<int>& val, vector<vector<int>>& res, int& k, int& sum){
    if(i == nums.size()){
        if(sum == k){
            res.push_back(val);
            return true;
        }
        return false;
    }
    val.push_back(nums[i]);
    sum += nums[i];
    if(helperOne(i+1, nums, val, res, k, sum) == true) return true; // pick
    
    val.pop_back();
    sum -= nums[i];

    if(helperOne(i+1, nums, val, res, k, sum) == true) return true; // not pick

    return false;
}
vector<vector<int>> returnOneSubsequence(vector<int>& nums, int k){
    vector<vector<int>> res;
    vector<int> val;
    int sum = 0;
    helperOne(0, nums, val, res, k, sum);
    return res;
}

// count the subsequences
int helperCnt(int i, vector<int>& nums, int& k, int& sum){

    // This can only be done if array contains positive integers
    if(sum > k) return 0;

    if(i == nums.size()){
        if(sum == k) return 1;
        return 0;
    }

    sum += nums[i];
    int l = helperCnt(i+1, nums, k, sum); // pick

    sum -= nums[i];
    int r = helperCnt(i+1, nums, k, sum); // not pick

    return l+r;
}
int countSubsequences(vector<int>& nums, int k){
    int sum = 0;
    return helperCnt(0, nums, k, sum);
}

int main(){
    // for all:
    // TC: O(2^n)
    // SC: O(n)

    vector<int> nums = {1,2,1};
    int k = 2;

    cout << "Print all answers:\n";
    for(vector<int> i : returnSubsequences(nums, k)){
        for(int j : i){
            cout << j << " ";
        } cout << endl;
    }

    cout << "Print one answer:\n";
    for(vector<int> i : returnOneSubsequence(nums, k)){
        for(int j : i){
            cout << j << " ";
        } cout << endl;
    }

    cout << "Total Number of subsequences: " << countSubsequences(nums, k);

    return 0;
}
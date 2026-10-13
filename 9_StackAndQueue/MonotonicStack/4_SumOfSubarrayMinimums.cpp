#include<bits/stdc++.h>
using namespace std;
int brute(vector<int>& arr){
    // TC: O(n^2)
    // SC: O(1)
    int sum = 0;
    for(int i = 0; i < arr.size(); i++){
        int mini = INT_MAX;
        for(int j = i; j < arr.size(); j++){
            mini = min(arr[j], mini);
            sum += mini;
        }
    }
    return sum;
}
vector<int> NSE(vector<int>& nums){
    int n = nums.size();
    vector<int> nse(n, n);
    stack<int> mono;
    for(int i = n-1; i >= 0; i--){
        while(!mono.empty() && nums[mono.top()] >= nums[i]) mono.pop(); 
        if(!mono.empty() && nums[mono.top()] < nums[i]) nse[i] = mono.top();
        mono.push(i);
    }
    return nse;
}
vector<int> PSE(vector<int>& nums){ // previous smaller and equal element
    int n = nums.size();
    vector<int> pse(n, -1);
    stack<int> mono;
    for(int i = 0; i < n; i++){
        while(!mono.empty() && nums[mono.top()] > nums[i]) mono.pop(); 
        if(!mono.empty() && nums[mono.top()] <= nums[i]) pse[i] = mono.top();
        mono.push(i);
    }
    return pse;
}
int optimal(vector<int>& nums){
    // TC: O(n)
    // SC: O(n)
    int n = nums.size();
    int sum = 0;
    int mod = (int) 1e9 + 7;
    vector<int> nse = NSE(nums);
    vector<int> pse = PSE(nums);
    for(int i = 0; i < n; i++){
        int left = i - pse[i];
        int right = nse[i] - i;
        sum = (sum + (1LL * left * right * nums[i]) % mod) % mod;
    }
    return sum;
}
int main(){
    vector<int> nums = {3,1,2,4};
    cout << brute(nums) << endl;
    cout << optimal(nums) << endl;
    return 0;
}
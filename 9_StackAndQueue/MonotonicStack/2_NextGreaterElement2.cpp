#include<bits/stdc++.h>
using namespace std;
vector<int> brute(vector<int>& nums){
    // TC: O(n^2)
    // SC: O(n)
    int n = nums.size();
    vector<int> ans(n, -1);
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n+i; j++){
            if(nums[i] < nums[j%n]){
                ans[i] = nums[j%n];
                break;
            }
        }
    }
    return ans;
}
vector<int> selfOptimal(vector<int>& nums){
    // TC: O(n)
    // SC: O(n)
    int n = nums.size();
    vector<int> ans(n, -1);
    int maxIdx = 0;
    stack<int> mono;
    for(int i = 0; i < n; i++){
        if(nums[i] > nums[maxIdx]) maxIdx = i;
    }
    for(int i = n-1; i >= 0; i--){
        int x = (i + maxIdx + 1) % n;
        while(!mono.empty() && mono.top() <= nums[x]) mono.pop();
        if(!mono.empty()) ans[x] = mono.top();
        mono.push(nums[x]);
    }
    return ans;
}
vector<int> optimal(vector<int>& nums){
    // TC: O(n)
    // SC: O(n)
    int n = nums.size();
    vector<int> ans(n, -1);
    stack<int> mono;
    for(int i = 2*n-1; i >= 0; i--){
        while(!mono.empty() && mono.top() <= nums[i%n]) mono.pop();
        if(i < n && !mono.empty()) ans[i] = mono.top();
        mono.push(nums[i%n]);
    }
    return ans;
}
int main(){
    vector<int> nums = {3, 10, 4, 2, 12, 2, 6, 1, 11, 2, 9};
    // vector<int> nums = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    // vector<int> res = brute(nums);
    // vector<int> res = selfOptimal(nums);
    vector<int> res = optimal(nums);
    for(int i : res){
        cout << i << " ";
    }
    return 0;
}
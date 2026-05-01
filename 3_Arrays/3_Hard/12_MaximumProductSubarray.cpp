#include<bits/stdc++.h>
int bruteMaxProduct(vector<int>& nums){
    // TC: O(n^2)
    // SC: O(1)
    int n = nums.size();
    int maxProd = nums[0];
    for(int i = 0; i < n; i++){
        maxProd = max(maxProd, nums[i]);
        if(nums[i] == 0) continue;
        int prod = 1;
        for(int j = i; j < n; j++){
            if(nums[j] == 0) break;
            prod *= nums[j];
            maxProd = max(prod, maxProd);
        }
    }
    return maxProd;
}
// Pre requisite: Kadane's Algorithm
int optimalMaxProduct1(vector<int>& nums){
    // TC: O(n)
    // SC: O(1)
    int n = nums.size();
    int curr_max = nums[0];
    int curr_min = nums[0];
    int ans = nums[0];
    for(int i = 1; i < n; i++){
        if(nums[i] < 0){
            // big positive × negative → big negative
            // big negative × negative → big positive
            swap(curr_min, curr_max);
        }
        curr_min = min(nums[i], nums[i]*curr_min);
        curr_max = max(nums[i], nums[i]*curr_max);
        ans = max(ans, curr_max);
    }
    return ans;
}
int optimalMaxProduct2(vector<int>& nums){
    // TC: O(n)
    // SC: O(1)
    int n = nums.size();
    int ans = nums[0];
    int prefix = 1, suffix = 1;
    for(int i = 0; i < n; i++){
        if(prefix == 0) prefix = 1;
        if(suffix == 0) suffix = 1;
        prefix *= nums[i];
        suffix *= nums[n-i-1];
        ans = max(ans, max(prefix, suffix));
    }
    return ans;
}
int main(){
    vector<int> nums = {1, 2, -3, 0, -4, -5};
    cout << bruteMaxProduct(nums) << endl;
    cout << optimalMaxProduct1(nums) << endl;
    cout << optimalMaxProduct2(nums) << endl;
    return 0;
}
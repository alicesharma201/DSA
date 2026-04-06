// Length of the longest subarray with zero Sum
#include<bits/stdc++.h>
int brute(vector<int>& nums){
    // TC: O(n^2)
    // SC: O(1)
    int n = nums.size();
    int longest = 0;
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i; j < n; j++){
            sum += nums[j];
            if(sum == 0){
                longest = max(longest, j-i+1);
            }
        }
    }
    return longest;
}
int optimal(vector<int>& nums){
    // TC: O(nlogn)
    // SC: O(n)

    // |--------sum---------|
    // |----sum----||---0---|
    
    int n = nums.size();
    int longest = 0;
    map<int, int> prefixSum;
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += nums[i];
        if(sum == 0) longest = max(longest, i+1);
        if(prefixSum.find(sum) != prefixSum.end()) longest = max(longest, i-prefixSum[sum]);
        else prefixSum[sum] = i;
    }
    return longest;
}
int main(){
    vector<int> nums = {9, -3, 3, -1, 6, -5};
    cout << brute(nums) << endl;
    cout << optimal(nums) << endl;
    return 0;
}
#include<bits/stdc++.h>
int linear(vector<int>& nums){
    // TC: O(n)
    // SC: O(1)
    int n = nums.size();
    int mini = INT_MAX;
    for(int i = 0; i < n; i++){
        mini = min(mini, nums[i]);
    }
    return mini;
}
int binary(vector<int>& nums){
    // TC: O(logn)
    // SC: O(1)
    int low = 0, high = nums.size() - 1;
    while(low < high){
        int mid = low + (high - low)/2;
        if(nums[mid] > nums[high]) // minimum is in right half
            low = mid + 1;
        else // minimum is in left half
            high = mid;
    }
    return nums[low];
}
int main(){
    vector<int> nums = {4, 5, 6, 7, 8, 1, 2, 3};
    cout << linear(nums) << endl;
    cout << binary(nums) << endl;
    return 0;
}
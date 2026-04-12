#include<bits/stdc++.h>
int iterative(vector<int>& nums, int target){
    // TC: O(logn)
    // SC: O(1)
    int n = nums.size();
    int low = 0, high = n-1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] < target) low = mid + 1;
        else if(nums[mid] > target) high = mid - 1;
    }
    return -1;
}
int recursive(vector<int>& nums, int target, int low, int high){
    // TC: O(logn)
    // SC: O(logn) recursive call stack
    if(low > high) return -1;
    int mid = low + (high - low)/2;
    if(nums[mid] == target) 
        return mid;
    else if(nums[mid] < target) 
        return recursive(nums, target, mid+1, high);
    else 
        return recursive(nums, target, low, mid-1);
}
int wrapper(vector<int>& nums, int target){
    return recursive(nums, target, 0, nums.size()-1);
}
int main(){
    vector<int> nums = {10, 20, 30, 40, 50, 60, 70};
    int target = 50;
    cout << iterative(nums, target) << endl;
    cout << wrapper(nums, target) << endl;
    return 0;
}
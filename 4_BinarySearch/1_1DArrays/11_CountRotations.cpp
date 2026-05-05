#include<bits/stdc++.h>
// index of the smallest element = number of rotations in a sorted array
int brute(vector<int>& nums){
    // TC: O(n)
    // SC: O(1)
    int n = nums.size();
    int mini = nums[0];
    int minidx = 0;
    for(int i = 1; i < n; i++){
        if(mini > nums[i]){
            mini = nums[i];
            minidx = i;
        }
    }
    return minidx;
}
int better(vector<int>& nums){
    // TC: O(n)
    // SC: O(1)
    int n = nums.size();
    for(int i = 0; i < n-1; i++){
        if(nums[i] > nums[i+1]) return i+1;
    }
    return 0;
}
int optimal(vector<int>& nums){
    // TC: O(logn)
    // SC: O(1)
    int low = 0, high = nums.size() - 1;
    if(nums[low] <= nums[high]) return low; // early exit for no rotation sorted array
    while(low < high){
        int mid = low + (high - low)/2;
        if(nums[mid] > nums[high]) low = mid + 1;
        else high = mid;
    }
    return low;
}
int main(){
    vector<int> nums = {5, 6, 7, 8, 0, 1, 2, 3, 4};
    cout << brute(nums) << endl;
    cout << better(nums) << endl;
    cout << optimal(nums) << endl;
    return 0;
}
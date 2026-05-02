#include<bits/stdc++.h>
int linear(vector<int>& nums, int k){
    // TC: O(n)
    // SC: O(1)
    int n = nums.size();
    for(int i = 0; i < n; i++){
        if(nums[i] == k) return i;
    }
    return -1;
}
int binary(vector<int>& nums, int k){
    // Key property: pick any element from the array, one part before or after that element will always be sorted, this means either left or right part of the array will always be sorted
    // TC: O(nlogn)
    // SC: O(1)
    int low = 0, high = nums.size()-1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(nums[mid] == k) return mid;
        if(nums[low] <= nums[mid]){ // if left part is sorted
            if(k >= nums[low] && k < nums[mid]) high = mid-1;
            else low = mid+1;
        }
        else if(nums[mid] <= nums[high]){ // if right part is sorted
            if(nums[mid] < k && k <= nums[high]) low = mid+1;
            else high = mid-1;
        }
    }
    return -1;
}
int main(){
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int k = 2;
    cout << linear(nums, k) << endl;
    cout << binary(nums, k) << endl;
    return 0;
}
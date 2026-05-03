#include<bits/stdc++.h>
bool linear(vector<int>& nums, int k){
    // TC: O(n)
    // SC: O(1)
    int n = nums.size();
    for(int i = 0; i < n; i++)
        if(nums[i] == k) return true;
    return false;
}
bool binary(vector<int>& nums, int k){
    // TC: O(logn) for average but O(n) for worst
    int low = 0, high = nums.size() - 1;
    while(low <= high){
        int mid = low + (high - low) / 2; 
        if(nums[mid] == k) return true;

        // Handle duplicates
        if(nums[low] == nums[mid] && nums[mid] == nums[high]){
            low++; high--; // this can make worst case TC as O(n) for eg: {1, 1, 1, 1, 1}
            continue;
        }

        // Search the left part
        if(nums[low] <= nums[mid]){
            if(nums[low] <= k && k < nums[mid]) high = mid - 1;
            else low = mid + 1;
        }

        // Search the right part
        else if(nums[mid] <= nums[high]){
            if(nums[mid] < k && k <= nums[high]) low = mid + 1;
            else high = mid - 1;
        }
    }
    return false;
}
int main(){
    vector<int> nums = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int k = 3;
    // vector<int> nums = {1, 0, 1, 1, 1};
    // int k = 0;
    linear(nums, k) ? cout << "True\n" : cout << "False\n";
    binary(nums, k) ? cout << "True\n" : cout << "False\n";
    return 0;
}
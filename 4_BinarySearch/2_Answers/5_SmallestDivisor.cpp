#include<bits/stdc++.h>
int checkDivisor(vector<int>& nums, int i){
    int n = nums.size();
    int div = 0;
    for(int j : nums){
        div += (j + i - 1)/ i; // for ceil
    }
    return div;
}
int linearSmallestDivisor(vector<int>& nums, int limit){
    // TC: O(n * maxi)
    // SC: O(1)
    if(nums.size() > limit) return -1;
    int maxi = *max_element(nums.begin(), nums.end());
    for(int i = 1; i <= maxi; i++){
        int div = checkDivisor(nums, i);
        if(div <= limit){
            return i;
        }
    }
    return -1;
}
int binarySmallestDivisor(vector<int>& nums, int limit){
    // TC: O(n * log(max_ele))
    // SC: O(1)
    if(nums.size() > limit) return -1;
    int low = 1;
    int high = *max_element(nums.begin(), nums.end());
    while(low <= high){
        int mid = low + (high - low)/2;
        int div = checkDivisor(nums, mid);
        if(div <= limit){
            high = mid - 1;
        } else low = mid + 1;
    }
    return low;
}
int main(){
    vector<int> nums = {1, 2, 3, 4, 5}; int limit = 8;
    // vector<int> nums = {8, 4, 2, 3}; int limit = 10;
    cout << linearSmallestDivisor(nums, limit) << endl;
    cout << binarySmallestDivisor(nums, limit) << endl;
    return 0;
}
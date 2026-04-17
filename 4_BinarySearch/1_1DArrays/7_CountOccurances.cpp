#include<bits/stdc++.h>
int linearCount(vector<int>& nums, int x){
    // TC: O(n)
    // SC: O(1)
    int n = nums.size();
    int count = 0;
    for(int i = 0; i < n; i++){
        if(nums[i] == x) count++;
    }
    return count;
}
// TC: O(logn)
// SC: O(1)
int firstIdx(vector<int>& nums, int x){
    int low = 0, high = nums.size()-1;
    int first = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(nums[mid] >= x){
            if(nums[mid] == x){
                first = mid;
            }
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return first;
}
int lastIdx(vector<int>& nums, int x){
    int low = 0, high = nums.size()-1;
    int last = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(nums[mid] <= x){
            if(nums[mid] == x){
                last = mid;
            }
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return last;
}
int binaryCount(vector<int>& nums, int x){
    int first = firstIdx(nums, x);
    if(first == -1) return 0;
    int last = lastIdx(nums, x);
    return last - first + 1;
}
int main(){
    vector<int> nums = {1, 2, 2, 3, 3, 3, 4};
    int x = 2;
    cout << linearCount(nums, x) << endl;
    cout << binaryCount(nums, x) << endl;
    return 0;
}
#include<bits/stdc++.h>
int linearFindPeak(vector<int>& nums){
    // TC: O(n)
    // SC: O(1)
    int n = nums.size();
    if(n == 1) return 0;
    for(int i = 0; i < n; i++){
        if(i == 0){
            if(nums[0] > nums[1]) return 0;
        }
        else if(i == n-1){
            if(nums[n-2] < nums[n-1]) return n-1;
        }
        else if(nums[i-1] < nums[i] && nums[i] > nums[i+1]){
            return i;
        }
    }
    return -1;
}
int brute2(vector<int>& nums){
    int n = nums.size();
    if(n == 1) return 0;
    for(int i = 0; i < n; i++){
        if((i == 0 || nums[i-1] < nums[i]) && (i == n-1 || nums[i] > nums[i+1])) return i;
    }
    return -1;
}
int binaryFindPeak(vector<int>& nums){
    int n = nums.size();
    if(n == 1) return 0;
    if(nums[0] > nums[1]) return 0;
    if(nums[n-2] < nums[n-1]) return n-1;
    int low = 1, high = n-2;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1]) return mid;
        // remember that we don't have to return the highest, we can return any peak
        if(nums[mid] > nums[mid+1]) high = mid - 1; // if mid is greater than mid+1 then peak must be in left
        else low = mid + 1; // if mid is less than mid+1 then peak must be in right
    }
    return -1;
}
int optimal2(vector<int>& nums){
    int n = nums.size();
    if(n == 1) return 0;
    if(nums[0] > nums[1]) return 0;
    if(nums[n-2] < nums[n-1]) return n-1;
    int low = 1, high = n-2;
    while(low < high){
        int mid = low + (high - low)/2;
        if(nums[mid] > nums[mid+1]) high = mid; // if mid is greater than mid+1 then peak must be in left (including mid)
        else low = mid + 1; // if mid is less than mid+1 then peak must be in right
    }
    return low;
}
int main(){
    // we're assuming nums[i] != nums[i+1]
    vector<int> nums = {1, 2, 8, 4, 5, 6, 7, 6, 5};
    cout << linearFindPeak(nums) << endl;
    cout << brute2(nums) << endl;
    cout << binaryFindPeak(nums) << endl;
    cout << optimal2(nums) << endl;
    return 0;
}
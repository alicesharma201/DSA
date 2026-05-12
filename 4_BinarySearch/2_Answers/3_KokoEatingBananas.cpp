#include<bits/stdc++.h>
// We're searching on the rate, not on the array
int maximum(vector<int>& nums){
    int n = nums.size();
    int maxi = 0;
    for(int i = 0; i < n; i++){
        if(maxi < nums[i]) maxi = nums[i];
    }
    return maxi;
}
int totalHours(vector<int>& nums, int rate){
    int total = 0;
    for(int j = 0; j < nums.size(); j++){
        total += (nums[j] + rate - 1)/ rate;
    }
    return total;
}
int linearRate(vector<int>& nums, int h){
    // TC: O(maxi * n)
    // SC: O(1)
    int maxi = maximum(nums);
    for(int i = 1; i <= maxi; i++){
        int total = totalHours(nums, i);
        if(total <= h) return i;
    }
    return maxi;
}
int binaryRate(vector<int>& nums, int h){
    // TC: O(log(max) * n)
    // SC: O(1)
    int ans = 0;
    int low = 1, high = maximum(nums);
    while(low <= high){
        int mid = low + (high - low) / 2;
        int total = totalHours(nums, mid);
        if(total <= h){
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;
}
int main(){
    vector<int> nums = {3, 7, 4, 9, 2, 12};
    int h = 8;
    cout << linearRate(nums, h) << endl;
    cout << binaryRate(nums, h) << endl;
    return 0;
}
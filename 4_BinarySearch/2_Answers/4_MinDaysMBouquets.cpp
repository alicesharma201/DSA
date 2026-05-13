#include<bits/stdc++.h>
// k = number of flowers required to make a bouquet
// m = number of bouquets required
int maximum(vector<int>& nums, int n){
    int maxi = 0;
    for(int i = 0; i < n; i++){
        if(nums[i] > maxi) maxi = nums[i];
    }
    return maxi;
}
int minimum(vector<int>& nums, int n){
    int mini = INT_MAX;
    for(int i = 0; i < n; i++){
        if(nums[i] < mini) mini = nums[i];
    }
    return mini;
}
int checkDays(vector<int>& nums, int m, int k, int i, int n){
    int flowers = 0, bouquets = 0;
    for(int j = 0; j < n; j++){
        if(i >= nums[j]){
            flowers++;
            if(flowers == k){
                bouquets++;
                flowers = 0;
            }
        }
        else flowers = 0;
    }
    return (bouquets >= m);
}
int linearDay(vector<int>& nums, int m, int k){
    // TC: O(maxi * n)
    // SC: O(1)
    int n = nums.size();
    if(n < k * m) return -1; // number of flowers are less than flowers requred
    int maxi = maximum(nums, n);
    int mini = minimum(nums, n);
    for(int i = mini; i <= maxi; i++){ // checking from earliest to latest bloom day
        if(checkDays(nums, m, k, i, n)) return i;
    }
    return -1; 
}
int binaryDay(vector<int>& nums, int m, int k){
    // TC: O(log(maxi) * n)
    // SC: O(1)
    int n = nums.size();
    int ans = -1;
    if(n < (long long)k * m) return -1;
    int low = minimum(nums, n), high = maximum(nums, n);
    while(low <= high){
        int mid = low + (high - low)/2;
        if(checkDays(nums, m, k, mid, n)){
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;
}
int main(){
    vector<int> nums = {7, 7, 7, 7, 13, 11, 12, 7};
    int m = 2, k = 3;
    // vector<int> nums = {1, 10, 3, 10, 2};
    // int m = 3, k = 2;
    cout << linearDay(nums, m, k) << endl;
    cout << binaryDay(nums, m, k) << endl;
    return 0;
}
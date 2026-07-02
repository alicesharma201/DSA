#include<bits/stdc++.h>
int subarrayCount(vector<int>& nums, int limit){
    int cnt = 1, sum = 0;
    for(int num : nums){
        if(sum + num <= limit){
            sum += num;
        }else{
            sum = num;
            cnt++;
        }
    }
    return cnt;
}
int linearSplitArray(vector<int>& nums, int k){
    // TC: O(N * (high-low+1))
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);
    for(int i = low; i <= high; i++){
        if(subarrayCount(nums, i) <= k) return i;
    }
    return -1;
}
int binarySplitArray(vector<int>& nums, int k) {
    // TC: O(N * log(high-low+1))
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);
    while(low <= high){
        int mid = low + (high - low)/2;
        if(subarrayCount(nums, mid) <= k) high = mid - 1;
        else low = mid + 1;
    }
    return low;
}
int main(){
    vector<int> nums = {1,2,3,4,5};
    int k = 3;
    cout << linearSplitArray(nums, k) << endl;
    cout << binarySplitArray(nums, k) << endl;
    return 0;
}
#include<bits/stdc++.h>
int maxOnes(vector<int>& nums){
    // TC: O(n)
    // SC: O(1)
    int n = nums.size();
    int count = 0;
    int maxi = 0;
    for(int i = 0; i < n; i++){
        if(nums[i] == 1) count++; // if element is 1 increment count
        else count = 0; // if element is 0 set count to 0 (breaking the streak)
        maxi = max(maxi, count); // store maxi as the maximum of count encountered
    }
    return maxi;
}
int main(){
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    cout << maxOnes(nums);
    return 0;
}
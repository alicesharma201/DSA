#include<bits/stdc++.h>
long long maxSubarraySum(vector<int>& nums){
    int n = nums.size();
    long long sum = 0;
    long long maxi = LLONG_MIN;
    int start = 0;
    int ansStart = -1, ansEnd = -1;
    for(int i = 0; i < n; i++){
        if(sum == 0) start = i;
        sum += nums[i];
        if(sum > maxi){
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }
        if(sum < 0) sum = 0;
    }
    cout << "Start Index: " << ansStart << "\nEnd Index: " << ansEnd << endl;
    return maxi;
}
int main(){
    vector<int> nums = {-1, 2, 5, -3, 6, -9, 8};
    int res = maxSubarraySum(nums);
    cout << "Sum of the longest Subarray: " << res;
    return 0;
}
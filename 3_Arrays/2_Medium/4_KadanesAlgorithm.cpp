#include<bits/stdc++.h>
long long brute(vector<int>& nums){
    // TC: O(n^2)
    // SC: O(1)
    int n = nums.size();
    long long maxi = LLONG_MIN;
    for(int i = 0; i < n; i++){
        long long sum = 0;
        for(int j = i; j < n; j++){
            sum += nums[j];
            if(sum > maxi) maxi = sum;
        }
    }
    return maxi;
}
long long optimal(vector<int>& nums){
    // TC: O(n)
    // SC: O(1)

    // Kadane's Algorithm: Do not carray negatives into future

    int n = nums.size();
    long long sum = 0;
    long long maxi = LLONG_MIN;
    for(int i = 0; i < n; i++){
        sum += nums[i];
        if(maxi < sum) maxi = sum;
        if(sum < 0) sum = 0; // When sum becomes negative, set it zero
    }
    return maxi;
}
int main(){
    vector<int> nums = {2, 3, 5, -2, 7, -4};
    cout << brute(nums) << endl;
    cout << optimal(nums) << endl;
    return 0;
}
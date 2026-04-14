#include<bits/stdc++.h>
int linear(vector<int>& nums, int x){
    // TC: O(n)
    // SC: O(1)
    int n = nums.size();
    for(int i = 0; i < n; i++){
        if(nums[i] >= x) return i;
    }
    return n;
}
int binary(vector<int>& nums, int x){
    // TC: O(logn)
    // SC: O(1)
    int n = nums.size();
    int ans = n;
    int low = 0, high = n-1;
    while(low <= high){
        int mid = (low + high)/2;
        if(nums[mid] >= x){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}
int main(){
    vector<int> nums = {3, 5, 8, 15, 19};
    int x = 9;
    cout << linear(nums, x) << endl; // we are inserting x at this position
    cout << binary(nums, x) << endl;
    return 0;
}
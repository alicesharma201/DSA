#include<bits/stdc++.h>
// search insert position = lower bound approach
int approach(vector<int>& nums, int x){
    // TC: O(logn)
    // SC: O(1)
    int low = 0, high = nums.size()-1;
    int ans = nums.size();
    while(low <= high){
        int mid = (low + high)/2; 
        if(nums[mid] >= x){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}
int main(){
    vector<int> nums = {1, 2, 2, 4, 7};
    int x = 3;
    cout << approach(nums, x) << endl;
    return 0;
}
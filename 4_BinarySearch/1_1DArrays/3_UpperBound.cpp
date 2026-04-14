#include<bits/stdc++.h>
int linear(vector<int>& nums, int x){
    int n = nums.size();
    for(int i = 0; i < n; i++){
        if(nums[i] > x) return i;
    }
    return n;
}
int binary(vector<int>& nums, int x){
    int n = nums.size();
    int ans = n;
    int low = 0, high = n-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(nums[mid] > x){
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
    vector<int> nums = {2, 5, 5, 7, 9, 11};
    int x = 5;
    cout << linear(nums, x) << endl;
    cout << binary(nums, x) << endl; // insert x at its just greater element's position
    return 0;
}
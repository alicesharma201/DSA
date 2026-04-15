#include<bits/stdc++.h>
// TC: O(logn)
// SC: O(1)
int floor_val(vector<int>& nums, int x){
    int floorAns = -1;
    int n = nums.size();
    int low = 0, high = n-1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(nums[mid] <= x){
            floorAns = nums[mid];
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return floorAns;
}
int ceil_val(vector<int>& nums, int x){
    int ceilAns = -1;
    int n = nums.size();
    int low = 0, high = n-1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(nums[mid] >= x){
            ceilAns = nums[mid];
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ceilAns;
}
int main(){
    vector<int> nums = {2, 3, 5, 5, 7};
    int x = 4;
    cout << "floor: " << floor_val(nums, x) << endl;
    cout << "ceil: " << ceil_val(nums, x) << endl;
    return 0;
}
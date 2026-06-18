#include<bits/stdc++.h>
int linearMissing(vector<int>& nums, int k){
    // TC: O(n)
    // SC: O(1)
    int n = nums.size();
    for(int i = 0; i < n; i++){
        if(nums[i] <= k){
            k++;
        }
        else break;
    }
    return k;
}
// int binaryMissing(vector<int>& nums, int k){
//     int n = nums.size();
//     int low = 0, high = n-1;
//     while(low <= high){
//         int mid = low + (high - low)/2;
//         if(nums[mid] <= k){
//             k++;
//             low = mid + 1;
//         }
//         else high = mid - 1;
//     }
//     return k;
// }
int main(){
    // find the missing elements 
    // create the array of missing elements in ascending order
    // return the missing element at kth position of the new array
    vector<int> nums = {2,3,4,7,11};
    int k = 5; // what's the kth missing number?
    cout << linearMissing(nums, k) << endl;
    // cout << binaryMissing(nums, k) << endl;
    return 0;
}
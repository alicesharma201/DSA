#include<bits/stdc++.h>
int brute1(vector<int>& nums){
    // TC: O(n)
    // SC: O(1)
    int n = nums.size();
    if(nums.size() == 1) return nums[0];
    for(int i = 0; i < n; i++){
        if(i == 0){
            if(nums[i] != nums[i+1])
            return nums[i];
        }
        else if(i == n-1){ 
            if(nums[i] != nums[i-1])
            return nums[i];
        }
        else if(nums[i-1] != nums[i] && nums[i] != nums[i+1]) return nums[i];
    }
    return -1;
}
int brute2(vector<int>& nums){
    // TC: O(n)
    // SC: O(1)
    int n = nums.size();
    int calcXor = 0;
    for(int i = 0; i < n; i++){
        calcXor ^= nums[i];
    }
    return calcXor;
}
int optimal(vector<int>& nums){
    // every pair 'starts' at 'even' index and 'ends' at 'odd' index when the array is still balanced, if the sequence changes, then there must be a single element present
    int n = nums.size();
    if(n == 1) return nums[0];
    if(nums[0] != nums[1]) return nums[0];
    if(nums[n-1] != nums[n-2]) return nums[n-1];
    int low = 1, high = n - 2;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(nums[mid-1] != nums[mid] && nums[mid] != nums[mid+1])
            return nums[mid];
        if(nums[mid] == nums[mid ^ 1]) // eg: nums[4] == nums[5] or nums[5] == nums[4] then sequence isn't broken
            low = mid + 1;
        else 
            high = mid - 1;
    }
    return -1;
}
int main(){
    vector<int> nums = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    cout << brute1(nums) << endl;
    cout << brute2(nums) << endl;
    cout << optimal(nums) << endl;
    return 0;
}
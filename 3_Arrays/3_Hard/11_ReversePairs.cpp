#include<bits/stdc++.h>
// for i < j count the pairs such that A[i] > 2*A[j]
int bruteReversePairs(vector<int>& nums){
    // TC: O(n^2)
    // SC: O(1)
    int n = nums.size();
    int reversePairs = 0;
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(nums[i] > 2 * nums[j]) reversePairs++;
        }
    }
    return reversePairs;
}
// TC: O(n*logn) it is O(2n*logn) because of countPairs()
// SC: O(n)
void Merge(vector<int>& nums, int low, int mid, int high){
    vector<int> temp;
    int left = low, right = mid + 1;
    while(left <= mid && right <= high){
        if(nums[left] <= nums[right]){
            temp.push_back(nums[left++]);
        }
        else{
            temp.push_back(nums[right++]);
        }
    }
    while(left <= mid) temp.push_back(nums[left++]);
    while(right <= high) temp.push_back(nums[right++]);
    for(int i = low; i <= high; i++){
        nums[i] = temp[i - low];
    }
}
int countPairs(vector<int>& nums, int low, int mid, int high){
    int count = 0;
    int right = mid + 1;
    for(int i = low; i <= mid; i++){
        while(right <= high && nums[i] > 2 * nums[right]){
            right++;
        }
        count += right - (mid + 1);
    }
    return count;
}
int mergeSort(vector<int>& nums, int low, int high){
    int count = 0;
    if(low >= high) return count;
    int mid = (low + high) / 2;
    count += mergeSort(nums, low, mid);
    count += mergeSort(nums, mid+1, high);
    count += countPairs(nums, low, mid, high);
    Merge(nums, low, mid, high);
    return count;
}
int main(){
    vector<int> nums = {5, 3, 1, 2, 6};
    cout << bruteReversePairs(nums) << endl;
    int low = 0, high = nums.size() - 1;
    cout << mergeSort(nums, low, high) << endl;
    return 0;
}
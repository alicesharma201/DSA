#include<bits/stdc++.h>
// i and j are indices of an array
// find no. of pairs of (i, j) such that i < j and A[i] > A[j]
int bruteInversions(vector<int>& nums){
    // TC: O(n^2)
    // SC: O(1)
    int n = nums.size();
    int inversions = 0;
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(nums[i] > nums[j]) 
                inversions++;
        }
    }
    return inversions;
}
// While merging two sorted halves, count how many elements from the right half are smaller than elements in the left half.
// TC: O(nlogn)
// SC: O(n)
int Merge(vector<int>& nums, int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    int count = 0;

    while(left <= mid && right <= high) {
        if(nums[left] <= nums[right]) {
            temp.push_back(nums[left++]);
        } else { // right is smaller
            count += (mid - left + 1);
            temp.push_back(nums[right++]);
        }
    }
    while(left <= mid) temp.push_back(nums[left++]);
    while(right <= high) temp.push_back(nums[right++]);

    for(int i = low; i <= high; i++) {
        nums[i] = temp[i - low];
    }
    return count;
}
int mergeSort(vector<int>& nums, int low, int high) {
    int count = 0;
    if(low >= high) return count;
    int mid = (low + high) / 2;
    count += mergeSort(nums, low, mid);
    count += mergeSort(nums, mid+1, high);
    count += Merge(nums, low, mid, high);
    return count;
}
int main(){
    vector<int> nums = {5, 3, 2, 1, 4};
    cout << bruteInversions(nums) << endl;
    cout << mergeSort(nums, 0, nums.size()-1);
    return 0;
}
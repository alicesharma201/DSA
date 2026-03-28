#include<bits/stdc++.h>
vector<int> brute(vector<int>& nums){
    // TC: O(n! * n) n! to generate all the number of permutations and each one of them is of length n
    // SC:
    /* steps: 
    - generate all permutations 
    - sort
    - linear search
    - return next index
    (edge case: we can use mod if the given array is the last permutation which will give the 0th index as the next permutation)
    */

    return nums;
}
vector<int> stl(vector<int> nums){
    next_permutation(nums.begin(), nums.end());
    return nums;
}
vector<int> optimal(vector<int> nums){
    // TC: O(n+n+n) = O(n) 
    // SC: O(1)

    /* Dry run for better understanding.
    1. find the dip (start creating a line from the last element towards the first, if you find it decreasing, that's your break point): 
    - start iterating from n-2 and start decrementing it. 
    - if a[i] is less than a[i+1], i is break point
    2. find someone 'just' greater than a[break point]
    - iterate from the last till break point because the elements after the breakpoint are sorted decreasingly
    - swap break point with just greater 
    3. try to place remaining numbers in increasing sorted order
    */

    int n = nums.size();
    int idx = -1;
    for(int i = n-2; i >= 0; i--){
        if(nums[i] < nums[i+1]){
            idx = i; // break point
            break;
        }
    }
    if(idx == -1){ // if break point not found
        reverse(nums.begin(), nums.end()); // reverse takes TC: O(n)
        return nums;
    }
    for(int i = n-1; i > idx; i--){
        if(nums[idx] < nums[i]){
            swap(nums[idx], nums[i]);
            break;
        }
    }
    reverse(nums.begin()+idx+1, nums.end());

    return nums;
}
int main(){
    vector<int> nums = {2, 1, 5, 4, 3, 0, 0};
    for(int i : stl(nums)) cout << i << " "; cout << endl;
    for(int i : optimal(nums)) cout << i << " ";
    return 0;
}
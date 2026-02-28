#include<bits/stdc++.h>
bool optimal(vector<int>& vec){
    // TC: O(n)
    // SC: O(1)
    int n = vec.size();
    for(int i = 0; i <= n-2; i++){
        if(vec[i] > vec[i+1]){
            return false;
        }
    }
    return true;
}
int main(){
    vector<int> arr1 = {3, 2, 6, 1, 7, 5};
    vector<int> arr2 = {1, 2, 3, 4};
    vector<int> arr3 = {0};
    cout << (optimal(arr1) ? "True" : "False") << endl;
    cout << (optimal(arr2) ? "True" : "False") << endl;
    cout << (optimal(arr3) ? "True" : "False") << endl;
    return 0;
}
/* 
Leetcode 1752: Given an array nums, return true if the array was originally sorted in
non-decreasing order, then rotated some number of positions (including zero). Otherwise, 
return false.

// think of it like a circular loop

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int breaks = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] > nums[(i+1)%n]){
                breaks++;
            }
        }
        if(breaks > 1) return false;
        return true;
    }
};
*/
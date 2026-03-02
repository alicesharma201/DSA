#include<bits/stdc++.h>
void rotateArrayByOne(vector<int>& vec){
    int n = vec.size();
    int temp = vec[0];
    for(int i = 0; i < n-1; i++){
        vec[i] = vec[i+1];
    }
    vec[n-1] = temp;
}
int main(){
    vector<int> vec = {1, 2, 3, 4, 5};
    rotateArrayByOne(vec);
    for(int v : vec) cout << v << " ";
    return 0;
}

/*
LeetCode: Given an integer array nums, rotate the array to the 'right' by k steps, where k is non-negative.

// TC: O(n) SC: O(n)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        vector<int> temp(k);
        for(int i = 0; i < k; i++){
            temp[i] = nums[n-k+i];
        }
        for(int i = 0; i < n-k; i++){
            nums[n-i-1] = nums[n-k-i-1];
        }
        for(int i = 0; i < k; i++){
            nums[i] = temp[i];
        }
    }
};

// "In-place" 
// TC: O(n) SC: O(1)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        if(k == 0) return;

        // swapping the whole array
        int l = 0;
        int r = n-1;
        while(l < r){
            swap(nums[l], nums[r]);
            l++;
            r--;
        }

        // reverse first k
        l = 0;
        r = k-1;
        while(l < r){
            swap(nums[l], nums[r]);
            l++;
            r--;
        }

        // reverse rest
        l = k;
        r = n-1;
        while(l < r){
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
    }
};

// you can also use reverse() from stl which works like [begin, end)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        if(k == 0) return;

        // swapping the whole array
        reverse(nums.begin(), nums.end());

        // reverse first k
        reverse(nums.begin(), nums.begin()+k);

        // reverse rest
        reverse(nums.begin()+k, nums.end());
    }
};

*/
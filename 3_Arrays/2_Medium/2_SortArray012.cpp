// Dutch National Flag Problem
#include<bits/stdc++.h>
void brute(vector<int>& nums){
    // TC: O(nlogn)
    // SC: O(logn)
    sort(nums.begin(), nums.end());
}
void better(vector<int>& nums){
    // TC: O(2n) = O(n)
    // SC: O(1)
    int zero = 0, one = 0, two = 0; // counters
    int n = nums.size();
    for(int i = 0; i < n; i++){
        if(nums[i] == 0) zero++;
        else if(nums[i] == 1) one++;
        else two++;
    }
    int idx = 0;
    while(zero--){
        nums[idx++] = 0;
    }
    while(one--){
        nums[idx++] = 1;
    }
    while(two--){
        nums[idx++] = 2;
    }
    // or we can use three for loops:
    // 1st loop: from 0 to zero
    // 2nd loop: from zero to zero+one
    // 3rd loop: from zero+one to n-1
}
void optimal(vector<int>& nums){ 
    // TC: O(n)
    // SC: O(1)

    /*
    Dutch national flag algorithm:
    - 0 to low-1 = 0
    - low to mid-1 = 1
    - mid to high is unsorted
    - high+1 to n-1 = 2

    iterate over [mid...high]
    a[mid] == 0, swap(mid, low) then low++ mid++
    a[mid] == 1, mid++
    a[mid] == 2, swap(mid, high) then high--
    */ 
   
    int n = nums.size();
    int low = 0, mid = 0, high = n-1;
    while(mid <= high){
        if(nums[mid] == 0){
            swap(nums[low], nums[mid]);
            low++; 
            mid++;
        }
        else if(nums[mid] == 1){
            mid++;
        }
        else{
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}
int main(){
    vector<int> nums = {1, 0, 2, 1, 0};
    // brute(nums);
    // better(nums);
    optimal(nums);
    for(int i : nums) cout << i << " ";

    return 0;
}
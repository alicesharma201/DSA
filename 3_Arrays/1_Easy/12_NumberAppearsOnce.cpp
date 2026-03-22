#include<bits/stdc++.h>
int brute(vector<int>& nums){ // linear search
    // TC: O(n^2)
    // SC: O(1)
    int n = nums.size();
    for(int i = 0; i < n; i++){
        int count = 0;
        for(int j = 0; j < n; j++){
            if(nums[i] == nums[j]) count++;
        }
        if(count == 1) return nums[i];
    }
    return -1;
}
int better(vector<int>& nums){
    // TC: O(n+n+maxi) = O(n)
    // SC: O(maxi+1)
    int n = nums.size();
    int maxi = nums[0];
    for(int i = 0; i < n; i++) maxi = max(maxi, nums[i]);
    vector<int> hash(maxi+1, 0);
    
    // here we increment the frequency/count of the element encountered
    for(int i = 0; i < n; i++) hash[nums[i]]++; 

    // here we compare the frequency to check if the number has appeared 1 time or not
    for(int i = 0; i < maxi+1; i++) if(hash[i] == 1) return i; 
    return -1;

    // this method isn't ideal because if numbers are large then it'll cause huge waste of memory
}
int optimal(vector<int>& nums){ // XOR method
    // TC: O(n)
    // SC: O(1)
    int n = nums.size();
    int val = 0;
    for(int i = 0; i < n; i++) val ^= nums[i]; 
    return val;
}
int main(){
    vector<int> nums = {3, 2, 3, 2, 1};
    cout << brute(nums) << endl;
    cout << better(nums) << endl;
    cout << optimal(nums) << endl;
    return 0;
}
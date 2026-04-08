#include<bits/stdc++.h>
int brute(vector<int>& nums, int k){
    // TC: O(n^2)
    // SC: O(1)
    int n = nums.size();
    int subarrays = 0;
    for(int i = 0; i < n; i++){
        int Xor = 0;
        for(int j = i; j < n; j++){
            Xor ^= nums[j];
            if(Xor == k) subarrays++;
        }
    }
    return subarrays;
}
int optimal(vector<int>& nums, int k){
    /* just like prefixsum
    x ^ k = xor
    x ^ k ^ k = xor ^ k
    x = xor ^ k
    */

    // TC: O(nlogn)
    // SC: O(n)

    int n = nums.size();
    map<int, int> prefixXor;
    prefixXor[0] = 1; // so we set prefixXor = 1 so that we could add it to the counter later (base case)
    int Xor = 0;
    int xount = 0;
    for(int i = 0; i < n; i++){
        Xor ^= nums[i];
        // if(Xor == k) xount++; // we don't have to use this line if we do prefixXor[0] = 1;
        int remain = Xor ^ k; 
        if(prefixXor.find(remain) != prefixXor.end()) xount += prefixXor[remain];
        prefixXor[Xor]++;
    }
    return xount;
}
int main(){
    vector<int> nums = {4, 2, 2, 6, 2};
    int k = 6;
    cout << brute(nums, k) << endl;
    cout << optimal(nums, k) << endl;
    return 0;
}
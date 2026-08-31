#include<bits/stdc++.h>
using namespace std;
vector<int> brute(vector<int>& nums){
    // TC: O(3n + max(nums))
    // SC: O(max(nums))
    int maxi = *max_element(nums.begin(), nums.end());
    vector<int> hash(maxi+1, 0); // hash initialization takes O(max(nums))
    vector<int> vals;
    for(int i : nums){
        hash[i]++;
    }
    for(int j : nums){
        if(hash[j] == 1) vals.push_back(j);
    }
    return vals;
}
vector<int> optimal(vector<int>& nums){
    // TC: O(2n)
    // SC: O(1)
    // steps:
        // do xor of all elements and put it in x
        // do (x & x-1) ^ x to find the rightmost set bit and save its index i
        // create two buckets, store all the elements who's i-th bit is set in bucket 1, and not set in bucket 2
        // xor elements of bucket 1, similarly for bucket 2
    int x = 0;
    for(int num : nums) x ^= num;
    int i = (x & (x-1)) ^ x; // rightmost set bit
    int b1 = 0, b2 = 0;
    for(int num : nums){
        if(num & i) b1 ^= num; // if (num & rightmost-set-bit) is set
        else b2 ^= num;
    }
    return {b1, b2};
}
int main(){
    vector<int> nums = {1, 2, 1, 3, 5, 2};
    for(int i : brute(nums)) cout << i << " ";
    cout << endl;
    for(int i : optimal(nums)) cout << i << " ";
    return 0;
}
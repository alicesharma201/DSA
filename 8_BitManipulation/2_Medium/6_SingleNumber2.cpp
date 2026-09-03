#include<bits/stdc++.h>
using namespace std;
// approach1 : good old hash map, count frequencies and return the one which occured once. 
    // TC: O(n + log(map))
    // SC: O(log(map)) where map stores n/3 + 1
int approach2(vector<int>& nums){
    // TC: O(32 * n)
    // SC: O(1)
    int ans = 0;
    for(int b = 0; b < 32; b++){
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] & (1 << b)) cnt++;
        }
        if(cnt % 3 != 0) ans = ans | (1 << b); 
    }
    return ans;
}
int approach3(vector<int> nums){
    // TC: O(n/3 + nlogn)
    // SC: O(1)
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for(int i = 1; i < n; i = i+3){
        if(nums[i] != nums[i-1]) return nums[i-1];
    }
    return nums[n-1]; // last element is single
}
int approach4(vector<int>& nums){ // concept of buckets
    // i goes in ones if not in twos
    // i goes in twos if in ones
    // i goes in threes if in twos

    // TC: O(n)
    // SC: O(1)
    int ones = 0, twos = 0;
    for(int i : nums){
        ones = (ones ^ i) & ~twos;
        twos = (twos ^ i) & ~ones; 
    }
    return ones;
}
int main(){
    vector<int> nums = {2, 2, 2, 3, 5, 5, 5};
    cout << approach2(nums) << endl;
    cout << approach3(nums) << endl;
    cout << approach4(nums) << endl;
    return 0;
}
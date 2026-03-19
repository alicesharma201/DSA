#include<bits/stdc++.h>
int brute(vector<int>& nums){
    // TC: O(n^2)
    // SC: O(1)
    int maxLen = 0;
    int n = nums.size();
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i; j < n; j++){
            sum += nums[j];
            if(sum == 0){
                maxLen = max(maxLen, j-i+1);
            }
        }
    }
    return maxLen;
}
int optimal(vector<int>& nums){ 
    // TC: O(n log n) using map and O(n) average if unordered_map is used
    // SC: O(n) 
    map<long long, int> preSumMap;
    int maxLen = 0;
    long long sum = 0;
    for(int i = 0; i < nums.size(); i++){
        sum += nums[i];
        if(sum == 0){
            maxLen = max(maxLen, i+1);
        }
        long long remain = sum - 0; // here k is 0
        if(preSumMap.find(remain) != preSumMap.end()){ // if remain is already present in the hash map
            int len = i - preSumMap[remain]; 
            maxLen = max(maxLen, len); 
        }
        if(preSumMap.find(sum) == preSumMap.end()){ // if sum is NOT present in the hash map
            preSumMap[sum] = i; 
        }
    }
    return maxLen;
}
int main(){
    vector<int> nums = {9, -3, 3, -1, 6, -5};
    cout << brute(nums) << endl;
    cout << optimal(nums) << endl;
    return 0;
}
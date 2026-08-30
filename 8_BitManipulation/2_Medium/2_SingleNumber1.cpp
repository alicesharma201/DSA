#include<bits/stdc++.h>
using namespace std;
int brute(vector<int>& nums){ // linear search
    // TC: O(n^2)
    // SC: O(1)
    int n = nums.size();
    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if(nums[i] == nums[j]) cnt++;
        }
        if(cnt == 1) return nums[i];
    }
    return -1;
}
int better(vector<int>& nums){ // hash map
    // TC: O(3 * n)
    // SC: O(n)
    int maxElement = *max_element(nums.begin(), nums.end());
    vector<int> hash(maxElement+1, 0);
    for(int i : nums){
        hash[i]++;
    }
    for(int j : nums){
        if(hash[j] == 1) return j;
    }
    return -1;
}
int optimal(vector<int>& nums){ // xor
    // TC: O(n)
    // SC: O(1)
    int Xor = 0;
    for(int i : nums){
        Xor = Xor ^ i;
    }
    return Xor;
}
int main(){
    vector<int> nums = {2, 1, 4, 2, 3, 1, 4};
    cout << brute(nums) << endl;
    cout << better(nums) << endl;
    cout << optimal(nums) << endl;
    return 0;
}
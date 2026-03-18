#include<bits/stdc++.h>
int brute(vector<int>& nums){
    // TC: O(n^2)
    // SC: O(1)
    int n = nums.size();
    for(int i = 0; i < n; i++){
        int count = 0;
        for(int j = 0; j < n; j++){
            if(nums[i] == nums[j]) count++;
        }
        if(count > n/2) return nums[i];
    }
    return -1;
}
int better(vector<int>& nums){
    // TC: O(n) | worst: O(n^2)
    // SC: O(n)
    int n = nums.size();
    unordered_map<int, int> hash;
    for(int i = 0; i < n; i++){ 
        hash[nums[i]]++;
        if(hash[nums[i]] > n/2) return nums[i];
    }
    return -1;
}
int optimal(vector<int>& nums){ 
    // TC: O(n)
    // SC: O(1)
    /* 
    Moore's Voting Algorithm:
        - intially: element, count = 0
        - if any element appears: element = nums[i], count = 1
        - if nums[i] == element: count++;
        - if nums[i] != element: count--;
        - if count = 0: element = nums[i] (new element)
    - after this check if element occurs more than n/2 times
    - then return element

    // Value of 'count' does not represent occurance of 'element'!!! 
    */
    int n = nums.size();
    int count = 0; 
    int element = 0;
    for(int i = 0; i < n; i++){
        if(count == 0){ // if we dont't check this condition first the count might become negative
            element = nums[i];
            count++;
        }
        else if(element == nums[i]) count++;
        else if(element != nums[i]) count--;
    }
    // return element here if it is guarenteed
    int elementCount = 0;
    for(int i = 0; i < n; i++) if(element == nums[i]) elementCount++;
    if(elementCount > n/2) return element;
    return -1; 
}
int main(){
    vector<int> nums = {7, 0, 0, 1, 7, 7, 2, 7, 7};
    cout << brute(nums) << endl;
    cout << better(nums) << endl;
    cout << optimal(nums) << endl;
    return 0;
}
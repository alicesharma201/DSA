#include<bits/stdc++.h>
int brute(vector<int>& nums, int k){
    // TC: O(n^2)
    // SC: O(1)
    int n = nums.size();
    int len = 0; 
    for(int i = 0; i < n; i++){
        int sum = 0;
        // int count = 0;
        for(int j = i; j < n; j++){
            sum += nums[j];
            // count++;
            if(sum == k) len = max(len, j-i+1); // we use end - start + 1 instead of using count
        }
    }
    return len;
}
int better(vector<int>& nums, long long k){ 
    // TC: O(n log n) using map
    // TC: O(n) average if unordered_map is used
    // SC: O(n) 

    // This is optimal for positives and negatives.
    // If the array contains ONLY positives, a sliding window solution can do it in O(n) with O(1) space.
    
    /* Summary:
    1. update current sum
    2. check if we saw (sum-k)
    3. if yes, found subarray with sum k
    4. compute its length
    5. store prefix sum if it's new
    */

    /* Explaination: 
    hash map is stored as: {key = [currentSum], value = [CurrentSumIndex]}

    if sum = k
    sum(k) = currentSumIndex(x) - remainingSumIndex(x-k)
    (x-k) = x - k

    find if map contains the remainingSumIndex(x-k):
    if it does: store the len as currentSumIndex(x) - remainingSumIndex(x-k), then compare it with maxlen

    if we find a sum which does not exist in the map:
    we simply store the sum as key with its index as value in the hash map
    */
    map<long long, int> preSumMap;
    int maxLen = 0;
    long long sum = 0;
    for(int i = 0; i < nums.size(); i++){
        sum += nums[i];
        if(sum == k){
            maxLen = max(maxLen, i+1);
        }
        long long remain = sum - k;
        // preSumMap.find() tries to find the key(sum) in the map
        if(preSumMap.find(remain) != preSumMap.end()){ // here, if map contains the remianingSum, preSumMap.find(remain) will NOT point to end()
            int len = i - preSumMap[remain]; // length of the subarray will be currentSumIndex - remainingSumIndex(x-k)
            maxLen = max(maxLen, len); // this is how we get the longest subarray
        }
        if(preSumMap.find(sum) == preSumMap.end()){ // if map doesn't contain a sum, preSumMap.find(remain) will point to end()
            preSumMap[sum] = i; // we stored the new sum's index here
        }
    }
    return maxLen;
}
int optimal(vector<int>& nums, int k){ 
    // TC: O(2n) = O(n)
    // SC: O(1)

    // sliding window: the sum keeps increasing as we traverse the array, when the sum exceeds k, start subtracting elements from the front
    int i = 0; // right
    int j = 0; // left
    long long sum = 0;
    int maxLen = 0;
    int n = nums.size();
    while(i < n){ 
        sum += nums[i];
        while(j <= i && sum > k){ // this only runs for O(n) for the whole iteration of outer while loop
            sum -= nums[j];
            j++;
        }
        if(sum == k){
            maxLen = max(maxLen, i-j+1);
        }
        i++;
    }
    return maxLen;
}
int main(){
    vector<int> nums = {1, 2, 3, 1, 1, 1, 1, 3, 3};
    int k = 6;
    cout << brute(nums, k) << endl;
    cout << better(nums, k) << endl;
    cout << optimal(nums, k) << endl;
    return 0;
}
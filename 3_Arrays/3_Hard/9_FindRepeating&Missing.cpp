#include<bits/stdc++.h>
// vector<int> self(vector<int> nums){
//     vector<int> missrep(2, 0);
//     int n = nums.size();
//     sort(nums.begin(), nums.end());
//     for(int i = 0; i < n-1; i++){
//         if(nums[i] == nums[i+1]){
//             missrep[0] = nums[i];
//         }
//     }
//     for(int i = 0; i < n; i++){
//         if(nums[i] != i+1){
//             missrep[1] = i+1;
//             break;
//         }
//     }
//     return missrep;
// }
vector<int> brute(vector<int>& nums){
    // TC: O(n^2)
    // SC: O(1)
    int n = nums.size();
    int repeating = -1, missing = -1;
    for(int i = 1; i <= n; i++){
        int count = 0;
        for(int j = 0; j < nums.size(); j++){ // linear search
            if(nums[j] == i) count++;
        }
        if(count == 2) repeating = i; 
        else if(count == 0) missing = i;
        if(repeating != -1 && missing != -1) break;
    }
    return {repeating, missing};
}
vector<int> better(vector<int>& nums){
    // TC: O(n)
    // SC: O(n)
    int n = nums.size();
    vector<int> hash(n+1, 0);
    for(int i = 0; i < n; i++){
        hash[nums[i]]++;
    }
    int repeating = -1, missing = -1;
    for(int i = 1; i <= n; i++){
        if(hash[i] == 2) repeating = i;
        else if(hash[i] == 0) missing = i;
        if(repeating != -1 && missing != -1) break;
    }
    return {repeating, missing};
}
vector<int> optimal1(vector<int>& nums){
    // TC: O(n)
    // SC: O(1)
    int n = nums.size();
    long long naturalSum = ((long long)n * (n + 1)) / 2;
    long long ns2 = (long long)n * (n + 1) * (2 * n + 1) / 6; // sum of square of n natural numbers
    long long actualSum = 0;
    long long as2 = 0; // sum of square of elements in the array
    for(int i = 0; i < n; i++){
        actualSum += nums[i];
        as2 += (long long)nums[i] * (long long)nums[i];
    }
    long long diff1 = actualSum - naturalSum;
    long long diff2 = as2 - ns2;
    diff2 = diff2 / diff1;
    long long repeating = (diff1 + diff2) / 2;
    long long missing = repeating - diff1;
    return {(int)repeating, (int)missing};
}
int main(){
    vector<int> nums = {1, 2, 3, 6, 7, 5, 7};
    // for(int i : self(nums)) cout << i << " "; cout << endl;
    for(int i : brute(nums)) cout << i << " "; cout << endl;
    for(int i : better(nums)) cout << i << " "; cout << endl;
    for(int i : optimal1(nums)) cout << i << " "; cout << endl;
    return 0;
}
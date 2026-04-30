#include<bits/stdc++.h>
int bruteMaxProduct(vector<int>& nums){
    // TC: O(n^2)
    // SC: O(1)
    int n = nums.size();
    int maxProd = nums[0];
    for(int i = 0; i < n; i++){
        if(nums[i] == 0) continue;
        int prod = 1;
        for(int j = i; j < n; j++){
            if(nums[j] == 0) break;
            prod *= nums[j];
            maxProd = max(prod, maxProd);
        }
    }
    return maxProd;
}
// int OptimalMaxProduct(vector<int>& nums){
//     int n = nums.size();
    
//     return 0;
// }
int main(){
    vector<int> nums = {1, 2, -3, 0, -4, -5};
    cout << bruteMaxProduct(nums) << endl;
    return 0;
}
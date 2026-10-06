#include<bits/stdc++.h>
using namespace std;
vector<int> brute(vector<int>& nums){
    // TC: O(n^2)
    // SC: O(n)
    int n = nums.size(); 
    vector<int> ans(n, -1);
    for(int i = 0; i < n; i++){
        for(int g = i+1; g < n; g++){
            if(nums[i] < nums[g]){
                ans[i] = nums[g];
                break;
            }
        }
    }
    return ans;
}
vector<int> optimal(vector<int>& nums){ // Light pole analogy: Each element looks to its right, and shorter/equal poles get eliminated because a taller pole blocks them.
    // TC: O(n)
    // SC: O(1)
    int n = nums.size();
    vector<int> ans(n, -1);
    stack<int> mono;
    for(int i = n-1; i >= 0; i--){
        while(!mono.empty() && mono.top() <= nums[i]) mono.pop();
        if(!mono.empty()) ans[i] = mono.top();
        mono.push(nums[i]);
    }
    return ans;
}
int main(){
    // vector<int> nums = {4, 5, 2, 10, 8};
    vector<int> nums = {3, 3, 2, 10, 4, 5};
    // vector<int> res = brute(nums);
    vector<int> res = optimal(nums);
    for(int i : res){
        cout << i << ' ';
    }
    return 0;
}
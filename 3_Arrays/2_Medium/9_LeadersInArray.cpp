#include<bits/stdc++.h>
// Leader: Everything on the right should be smaller
vector<int> brute(vector<int>& nums){
    // TC: O(n^2)
    // SC: O(n)
    int n = nums.size();
    vector<int> leaders;
    for(int i = 0; i < n; i++){
        bool leader = true;
        for(int j = i+1; j < n; j++){
            if(nums[j] >= nums[i]){ // If any element to the right is greater or equal, nums[i] is not a leader
                leader = false;
                break;
            }
        }
        if(leader == true) leaders.push_back(nums[i]);
    }
    return leaders;
}
vector<int> extraSpaceLeaders(vector<int>& nums){
    // TC: O(n)
    // SC: O(n)
    if(nums.empty()) return {};
    int n = nums.size();
    vector<int> leaders; // extra space for storing leaders
    leaders.emplace_back(nums[n-1]);
    int rightMax = nums[n-1];
    for(int i = n-2; i >= 0; i--){
        if(rightMax < nums[i]){ 
            leaders.emplace_back(nums[i]);
            rightMax = nums[i];
        }
    }
    reverse(leaders.begin(), leaders.end());
    return leaders;
}
vector<int> inPlaceLeaders(vector<int>& nums){ // pointer method
    // TC: O(n)
    // SC: O(1)
    if(nums.empty()) return {};
    int n = nums.size();
    int rightMax = nums[n-1];
    int j = n-1; // pointing towards the first leader
    for(int i = n-2; i >= 0; i--){
        if(rightMax < nums[i]){
            rightMax = nums[i];
            nums[j-1] = nums[i];
            j--;
        }
    }
    nums.erase(nums.begin(), nums.begin()+j);
    return nums;
}
int main(){
    vector<int> nums = {10, 22, 12, 3, 0, 6};
    vector<int> lead1 = brute(nums);
    for(int i : lead1) cout << i << " "; cout << endl;
    vector<int> lead2 = extraSpaceLeaders(nums);
    for(int i : lead2) cout << i << " "; cout << endl;
    vector<int> lead3 = nums;
    inPlaceLeaders(lead3);
    for(int i : lead3) cout << i << " "; cout << endl;
    return 0;
}
#include<bits/stdc++.h>
vector<vector<int>> brute(vector<int>& nums, int n){
    // TC: O(n^3 log m) where m is unique triplets, and logm for set insertion
    // SC: O(m) unique triplets in the set
    set<vector<int>> st;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            for(int k = j+1; k < n; k++){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0){
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> result(st.begin(), st.end()); // convert set into vector
    return result;
}
vector<vector<int>> better(vector<int>& nums, int n){
    // TC: O(n^2 * logn)
    // SC: O(2 * m) for st + O(N) for hashSet
    set<vector<int>> st;
    for(int i = 0; i < n; i++){
        set<int> hashSet;
        for(int j = i+1; j < n; j++){
            int third = -(nums[i]+nums[j]);
            if(hashSet.find(third) != hashSet.end()){
                vector<int> temp = {nums[i], nums[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashSet.insert(nums[j]);
        }  
    }
    vector<vector<int>> result(st.begin(), st.end());
    return result;
}
vector<vector<int>> optimal(vector<int>& nums, int n){
    // TC: O(nlogn + n^2) = O(n^2)
    // SC: O(m)
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < n; i++){
        if(i > 0 && nums[i] == nums[i-1]) continue; // i > 0 prevents checking nums[-1]
        int j = i + 1;
        int k = n - 1;
        while(j < k){
            int sum = nums[i] + nums[j] + nums[k];
            if(sum < 0) j++;
            else if(sum > 0) k--;
            else if(sum == 0){
                result.push_back({nums[i], nums[j], nums[k]});
                j++; k--;
                while(j < k && nums[j] == nums[j-1]) j++;
                while(j < k && nums[k] == nums[k+1]) k--;
            }
        }
    }
    return result;
}
int main(){
    vector<int> nums = {-2,-2,-2,-2,-1,-1,-1,-1,0,0,0,0,2,2,2,2};
    int n = nums.size();
    // vector<vector<int>> res = brute(nums, n);
    // vector<vector<int>> res = better(nums, n);
    vector<vector<int>> res = optimal(nums, n);
    for(auto &vec : res){
        for(auto &el : vec){
            cout << el << " ";
        }
        cout << endl;
    }
    return 0;
}
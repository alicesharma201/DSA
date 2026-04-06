#include<bits/stdc++.h>
vector<vector<int>> nestedLoops(vector<int>& nums, int n){
    // TC: O(n^4 logm) quadruplets
    // SC: O(m) quadruplets
    set<vector<int>> st;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            for(int k = j+1; k < n; k++){
                for(int l = k+1; l < n; l++){
                    int sum = nums[i] + nums[j] + nums[k] + nums[l];
                    if(sum == 0){
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> result(st.begin(), st.end());
    return result;
}
vector<vector<int>> hashSet(vector<int>& nums, int n){
    // TC: O(n^3 * logn)
    // SC: O(n + m)
    set<vector<int>> st;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            set<int> hash;
            for(int k = j+1; k < n; k++){
                int four = -(nums[i] + nums[j] + nums[k]);
                if(hash.find(four) != hash.end()){
                    vector<int> temp = {nums[i], nums[j], nums[k], four};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hash.insert(nums[k]);
            }
        }
    }
    vector<vector<int>> result(st.begin(), st.end());
    return result;
}
vector<vector<int>> fourPointers(vector<int>& nums, int n){
    // TC: O(nlogn + n^3)
    // SC: O(m)
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < n; i++){
        if(i > 0 && nums[i] == nums[i-1]) continue;
        for(int j = i+1; j < n; j++){
            if(j > i+1 && nums[j] == nums[j-1]) continue;
            int k = j+1, l = n-1;
            while(k < l){
                long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                if(sum == 0){
                    result.push_back({nums[i], nums[j], nums[k], nums[l]});
                    k++; l--;
                    while(k < l && nums[k] == nums[k-1]) k++;
                    while(k < l && nums[l] == nums[l+1]) l--; 
                }
                else if(sum < 0) k++;
                else if(sum > 0) l--;
            }
        }
    }
    return result;
}
int main(){
    vector<int> nums = {1,0,-1,0,-2,2};
    int n = nums.size();
    // vector<vector<int>> res = nestedLoops(nums, n);
    // vector<vector<int>> res = hashSet(nums, n);
    vector<vector<int>> res = fourPointers(nums, n);
    for(auto &i : res){
        for(auto &j : i){
            cout << j << " ";
        }
        cout << endl;
    }
}
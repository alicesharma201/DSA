#include<bits/stdc++.h>
vector<vector<int>> brute(vector<int>& nums, int n){
    // TC: O(n^3 * log(no. of unique triplets))
    // SC: O(2 * no. of the unique triplets) + O(N) as we are using a set data structure and a list to store the triplets and extra O(N) for storing the array elements in another set.
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
    // TC: O(n^2 * log(no. of unique triplets))
    // SC: O(2 * no. of the unique triplets) + O(N) as we are using a set data structure and a list to store the triplets and extra O(N) for storing the array elements in another set.
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
// vector<vector<int>> optimal(vector<int>& nums, int n){
//     sort(nums.begin(), nums.end());
//     vector<vector<int>> result;
//     int first = 0, last = n-1;
//     while(first+1 < last){
//         int sum = nums[first] + nums[first+1] + nums[last];
//         if(sum == 0){
//             result.push_back({nums[first], nums[first+1], nums[last]});
//         }
//         else if(sum > 0){
//             last--;
//         }
//         else if(sum < 0){
//             first++;
//         }
//     }
//     return result;
// }
int main(){
    vector<int> nums = {-1,0,1,2,-1,-4};
    int n = nums.size();
    // vector<vector<int>> res = brute(nums, n);
    vector<vector<int>> res = better(nums, n);
    // vector<vector<int>> res = optimal(nums, n);
    for(auto &vec : res){
        for(auto &el : vec){
            cout << el << " ";
        }
        cout << endl;
    }
    return 0;
}
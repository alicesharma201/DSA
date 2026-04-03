#include<bits/stdc++.h>
vector<vector<int>> brute(vector<int>& nums, int n){
    // TC: O(n^3 * log(no. of unique triplets))
    // SC: O(2 * no. of unique triplets) for both st(set) and temp(vector)
    set<vector<int>> st;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            for(int k = j+1; k < n; k++){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0){
                    vector<int> vec = {nums[i], nums[j], nums[k]};
                    sort(vec.begin(), vec.end());
                    st.insert(vec);
                }
            }
        }
    }
    vector<vector<int>> temp(st.begin(), st.end()); // convert set into vector
    return temp;
}
// vector<vector<int>> better(vector<int>& nums, int n){
//     set<vector<int>> st;
//     for(int i = 0; i < n; i++){
//         for(int j = i+1; j < n; j++){
//             int remain = - nums[i] - nums[j];
//             if()
//         }
//     }
// }
int main(){
    vector<int> nums = {-1,0,1,2,-1,-4};
    int n = nums.size();
    vector<vector<int>> res = brute(nums, n);
    for(auto &vec : res){
        for(auto &el : vec){
            cout << el << " ";
        }
        cout << endl;
    }
    return 0;
}
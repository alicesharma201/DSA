#include<bits/stdc++.h>
class Brute{
public:
    // TC: O(n^2)
    // SC: O(1)
    string twoSumExists(vector<int>& nums, int target){
        int n = nums.size();
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int sum = nums[i] + nums[j];
                if(sum == target) return "YES";
            }
        }
        return "NO";
    }
    vector<int> twoSumIndices(vector<int>& nums, int target){
        int n = nums.size();
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int sum = nums[i] + nums[j];
                if(sum == target) return {i, j};
            }
        }
        return {-1, -1};
    }
};
class Better{
public:
    // TC: O(n logn) for map | O(n) for unordered_map (worst: O(n^2))
    // SC: O(n)
    string twoSumExists(vector<int>& nums, int target){
        int n = nums.size();
        unordered_map<int, int> hash;
        for(int i = 0; i < n; i++){
            int other = target - nums[i];
            if(hash.find(other) != hash.end()) return "YES";
            hash[nums[i]] = i; // we insert after checking the number inside the hash map because: We cannot put all numbers in the set from the beginning. If we do that, we might accidentally use the same number again from the same position, which is not allowed.
        }
        return "NO";
    }
    vector<int> twoSumIndices(vector<int>& nums, int target){ // this approach is optimal to return indices
        int n = nums.size();
        unordered_map<int, int> hash;
        for(int i = 0; i < n; i++){
            int other = target - nums[i];
            if(hash.find(other) != hash.end()) return {hash[other], i}; // {index of the other, index of the num[i]}
            hash[nums[i]] = i; // hash = {num[i], index of num[i]}
        }
        return {-1, -1};
    }
};
class Optimal{
public:
    string twoSumExists(vector<int> nums, int target){ 
        // TC: O(n logn) for sorting, O(n) for two pointer traversal, hence O(nlogn)
        // SC: O(1)
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int left = 0, right = n-1;
        while(left < right){
            int sum = nums[left] + nums[right];
            if(sum < target) left++;
            else if(sum > target) right--;
            else return "YES";
        }
        return "NO";
    }
    vector<int> twoSumIndices(vector<int>& nums, int target){ 
        // TC: O(n logn) for sorting, O(n) for two pointer traversal, O(n) for vector, hence O(n logn)
        // SC: O(n)
        // this approach is not optimal to return indices
        int n = nums.size();
        vector<pair<int,int>> numsIndex;
        for(int i = 0; i < n; i++) numsIndex.emplace_back(nums[i], i);
        sort(numsIndex.begin(), numsIndex.end());
        int left = 0, right = n-1;
        while(left < right){
            int sum = numsIndex[left].first + numsIndex[right].first;
            if(sum < target) left++;
            else if(sum > target) right--;
            else return {numsIndex[left].second, numsIndex[right].second};
        }
        return {-1, -1};
    }
};
int main(){
    vector<int> nums = {2,6,5,8,11};
    int target = 14;

    Brute sol1;
    cout << sol1.twoSumExists(nums, target) << " ";
    vector<int> res1 = sol1.twoSumIndices(nums, target);
    cout << "{" << res1[0] << ", " << res1[1] << "}" << endl;

    Better sol2;
    cout << sol2.twoSumExists(nums, target) << " ";
    vector<int> res2 = sol2.twoSumIndices(nums, target);
    cout << "{" << res2[0] << ", " << res2[1] << "}" << endl;

    Optimal sol3;
    cout << sol3.twoSumExists(nums, target) << " ";
    vector<int> res3 = sol3.twoSumIndices(nums, target);
    cout << "{" << res3[0] << ", " << res3[1] << "}" << endl;

    return 0;
}
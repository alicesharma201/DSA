#include<bits/stdc++.h>
int self(vector<int> nums){
    // TC: O(nlogn + n)
    // SC: O(1)
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int maxCons = 0;
    int cons = 1;
    for(int i = 0; i < n; i++){
        if(nums[i]+1 == nums[i+1]){
            cons++;
            maxCons = max(cons, maxCons);
        }
        else cons = 1;
    }
    return maxCons;
}
class Brute{
    // TC: O(n^2)
    // SC: O(1)
    private:
    int linearSearch(vector<int>& nums, int nextNum){
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] == nextNum){
                return true;
            }
        }
        return false;
    }
    public:
    int longestConsecutive(vector<int>& nums){
        int n = nums.size();
        if(n == 0) return 0;
        int longest = 1;
        for(int i = 0; i < n; i++){
            int x = nums[i];
            int count = 1;
            while(linearSearch(nums, x+1) == true){
                x += 1;
                count += 1;
            }
            longest = max(longest, count);
        }
        return longest;
    }
};
int main(){
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << self(nums) << endl;
    Brute b;
    cout << b.longestConsecutive(nums) << endl;
    return 0;
}
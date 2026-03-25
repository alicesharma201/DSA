#include<bits/stdc++.h>
class Brute{
    // TC: O(n^2)
    // SC: O(1)
    private:
    bool linearSearch(vector<int>& nums, int nextNum){
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
int self(vector<int> nums){ 
    // TC: O(nlogn + n) = O(nlogn)
    // SC: O(1)
    int n = nums.size();
    if(n == 0) return 0;
    sort(nums.begin(), nums.end());
    int maxCons = 1;
    int consecutive = 1;
    for(int i = 0; i < n-1; i++){
        if(nums[i] == nums[i+1]) continue;
        else if(nums[i]+1 == nums[i+1]){
            consecutive++;
            maxCons = max(consecutive, maxCons);
        }
        else consecutive = 1;
    }
    return maxCons;
}
int better(vector<int> nums){
    // TC: O(nlogn + n) = O(nlogn)
    // SC: O(1)
    int n = nums.size();
    if(n == 0) return 0;
    sort(nums.begin(), nums.end());
    int lastSmaller = INT_MIN;
    int currentCount = 1;
    int longest = 1;
    for(int i = 0; i < n; i++){
        if(nums[i] == lastSmaller) continue;
        else if(nums[i]-1 == lastSmaller){
            currentCount += 1;
            lastSmaller = nums[i];
        }
        else if(nums[i] != lastSmaller){
            currentCount = 1;
            lastSmaller = nums[i];
        }
        longest = max(currentCount, longest);
    }
    return longest;
}
int optimal(vector<int>& nums){ // to not destroy the array and get rid of O(nlogn), based on brute force approach
    // unordered_set TC: for best or average: O(1) ; for worst: O(n)
    // TC: for loop: O(N) + while loop: O(2N) = O(3N)
    // SC: O(N)
    int n = nums.size();
    if(n == 0) return 0;
    int longest = 1;
    unordered_set<int> st;
    for(int i = 0; i < n; i++){
        st.insert(nums[i]);
    }

    for(auto it : st){
        if(st.find(it-1) == st.end()){ //  if(it - 1 is NOT present in the set) means it is the first element
            int x = it;
            int count = 1;
            while(st.find(x+1) != st.end()){
                x++;
                count++;
            }
            longest = max(longest, count);
        }
    }

    return longest;
}
int main(){
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    Brute b;
    cout << b.longestConsecutive(nums) << endl;
    cout << self(nums) << endl;
    cout << better(nums) << endl;
    cout << optimal(nums) << endl;
    return 0;
}
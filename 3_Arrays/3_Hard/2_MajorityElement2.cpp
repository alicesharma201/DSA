#include<bits/stdc++.h>
vector<int> brute(vector<int>& nums){ // remember: there can be maximum of two majority elements
    // TC: O(n^2)
    // SC: O(2)
    int n = nums.size();
    vector<int> major;
    for(int i = 0; i < n; i++){
        if(major.size() == 0 || major[0] != nums[i]){ 
            // checking major[0] works for 2 major elements, but if logic expands → not scalable. 
            // better: if(find(major.begin(), major.end(), nums[i]) == major.end())
            int count = 0;
            for(int j = 0; j < n; j++){
                if(nums[i] == nums[j]){
                    count++;
                }
            }
            if(count > n/3){
                major.push_back(nums[i]);
            }
        }
        if(major.size() == 2) break;
    }
    return major;
}
vector<int> better(vector<int>& nums){
    // TC: O(nlogn) for map, O(n) for unordered_map, but worst case due to collisions is O(n^2)
    // SC: O(n)
    int n = nums.size();
    vector<int> temp;
    map<int, int> hash;
    for(int i = 0; i < n; i++){
        hash[nums[i]]++;
        if(hash[nums[i]] == (n/3)+1) temp.push_back(nums[i]); // the moment an element appears exactly (n/3)+1 times, it gets pushed to temp
        if(temp.size() == 2) break; // there can only be maximum of two majority elements
    }
    return temp;
}
vector<int> optimal(vector<int>& nums){
    // TC: O(2n)
    // SC: O(1)
    int n = nums.size();
    int cnt1 = 0, cnt2 = 0;
    int el1 = INT_MIN, el2 = INT_MIN;
    vector<int> temp;
    for(int i = 0; i < n; i++){
        if(cnt1 == 0 && nums[i] != el2){
            el1 = nums[i];
            cnt1 = 1;
        }
        else if(cnt2 == 0 && nums[i] != el1){
            el2 = nums[i];
            cnt2 = 1;
        }
        else if(el1 == nums[i]) cnt1++;
        else if(el2 == nums[i]) cnt2++;
        else if(el1 != nums[i] && el2 != nums[i]){ cnt1--; cnt2--; }
    }
    cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < n; i++){
        if(nums[i] == el1) cnt1++;
        else if(nums[i] == el2) cnt2++;
    }
    if(cnt1 > n/3) temp.push_back(el1);
    if(cnt2 > n/3) temp.push_back(el2);
    sort(temp.begin(), temp.end());
    return temp;
}
int main(){
    vector<int> nums = {1, 1, 1, 1, 3, 2, 2, 2};
    for(int i : brute(nums)) cout << i << " "; cout << endl;
    for(int i : better(nums)) cout << i << " "; cout << endl;
    for(int i : optimal(nums)) cout << i << " "; cout << endl;
    return 0;
}
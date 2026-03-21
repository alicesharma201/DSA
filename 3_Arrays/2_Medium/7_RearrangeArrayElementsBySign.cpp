#include<bits/stdc++.h>
void brute(vector<int>& nums){
    // TC: O(n + n/2) = O(n)
    // SC: O(n/2 + n/2) = O(n)

    /*
    - create two arrays positive and negative
    - store all the positve and negative elements in them via traversal
    - restore positives as nums[2*i]
    - restore negatives as nums[(2*i)+1]
    */

    int n = nums.size();
    vector<int> positive;
    vector<int> negative;

    for(int i = 0; i < n; i++){
        if(nums[i] > 0) positive.push_back(nums[i]);
        else negative.push_back(nums[i]);
    }

    for(int i = 0; i < n/2; i++){
        nums[2*i] = positive[i];
        nums[(2*i)+1] = negative[i];
    }
}
vector<int> optimal(vector<int>& nums){
    // TC: O(n)
    // SC: O(n)

    /* to solve the problem in a single pass and try to arrange the array elements in the correct order in that pass only
    - initialise pos as 0 and neg as 1
    - start storing nums[pos] and nums[neg] in an temp array
    - increase pos and neg by 2 
    */

    int n = nums.size();
    vector<int> temp(n, 0);
    int pos = 0, neg = 1;
    for(int i = 0; i < n; i++){
        if(nums[i] > 0){
            temp[pos] = nums[i];
            pos += 2;
        }
        else if(nums[i] < 0){
            temp[neg] = nums[i];
            neg += 2;
        }
    }
    return temp;
}
int main(){
    vector<int> nums1 = {1, 2, -4, -5};
    brute(nums1);
    for(int i : nums1) cout << i << ' ';

    cout << endl;

    vector<int> nums2 = {1, 2, -3, -1, -2, 3};
    for(int i : optimal(nums2)) cout << i << ' ';
    return 0;
}
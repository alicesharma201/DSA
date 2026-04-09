#include<bits/stdc++.h>
vector<int> approach(vector<int> nums1, vector<int>& nums2){
    // TC: O(n1)
    // SC: O(1)
    int n1 = nums1.size(), n2 = nums2.size();
    int i = n1-n2-1; 
    int j = n2-1; 
    int k = n1-1; 
    while(j >= 0){
        if(i >= 0 && nums1[i] > nums2[j])
            nums1[k--] = nums1[i--];
        else
            nums1[k--] = nums2[j--];
    }
    // so were basically putting the greater element of i or j at k's place
    return nums1;
}
int main(){
    vector<int> nums1 = {-5, -2, 4, 5, 0, 0, 0};
    vector<int> nums2 = {-3, 1, 8};
    for(int i : approach(nums1, nums2)) cout << i << " ";
    return 0;
}
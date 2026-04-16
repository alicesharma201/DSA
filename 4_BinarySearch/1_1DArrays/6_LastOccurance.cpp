#include<bits/stdc++.h>
int linearSearch(vector<int>& nums, int x){
    // TC: O(n)
    // SC: O(1)
    int n = nums.size();
    int lastIdx = -1;
    for(int i = n-1; i >= 0; i--){
        if(nums[i] == x){
            lastIdx = i;
            break;
        }
    }
    return lastIdx;
}
int binarySearch(vector<int>& nums, int x){
    // TC: O(logn)
    // SC: O(1)
    int low = 0, high = nums.size()-1;
    int lastIdx = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(nums[mid] <= x){
            if(nums[mid] == x){
                lastIdx = mid;
            }
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return lastIdx;
}
int main(){
    vector<int> nums = {2, 2, 3, 3, 3, 6, 6, 6, 7};
    int x = 6;
    cout << linearSearch(nums, x) << endl;
    cout << binarySearch(nums, x) << endl;
    return 0;
}
/* LC
class Solution {
public:
    int returnFirst(vector<int>& nums, int target){
        int first = -1;
        int low = 0, high = nums.size()-1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] >= target){ // When nums[mid] > target: The target must be to the left, so we search left (high = mid - 1)
                if(nums[mid] == target){
                    first = mid; 
                }
                high = mid - 1; // this is shrinking the right part and helps assign the first most occurance of the target, making nums[mid] shift towards the left
            }
            else low = mid + 1;
        }
        return first;
    }
    int returnLast(vector<int>& nums, int target){
        int last = -1;
        int low = 0, high = nums.size()-1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] <= target){ // When nums[mid] < target: The target must be to the right, so we search right (low = mid + 1).
                if(nums[mid] == target){
                    last = mid;
                }
                low = mid + 1; // this is shrinking the left part and helps assign the last most occurance of the target, making nums[mid] shift towards the right
            }
            else high = mid - 1;
        }
        return last;
    }
    vector<int> searchRange(vector<int>& nums, int target){
        int first = returnFirst(nums, target);
        if(first == -1) return {-1, -1};
        int last = returnLast(nums, target);
        return {first, last};
    }
};
*/
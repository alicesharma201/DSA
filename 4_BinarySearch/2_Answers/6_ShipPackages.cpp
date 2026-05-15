#include<bits/stdc++.h>
using namespace std;
int sumAll(vector<int>& nums){
    int sum = 0;
    for(int i : nums) sum += i;
    return sum;
}
int returnDays(vector<int>& nums, int capacity){
    int day = 1, load = 0;

    for(int i = 0; i < nums.size(); i++){
        if(load + nums[i] > capacity){
            day++;
            load = nums[i];
        }
        else{
            load += nums[i];
        }
    }
    return day;
}
int linearShip(vector<int>& nums, int d){
    int maxi = *max_element(nums.begin(), nums.end());
    int sum = sumAll(nums);
    for(int i = maxi; i <= sum; i++){
        if(returnDays(nums, i) <= d){
            return i;
        }
    }
    return -1;
}
int main(){
    vector<int> nums = {5, 4, 5, 2, 3, 4, 5, 6};
    int d = 5;

    cout << linearShip(nums, d) << endl;

    return 0;
}
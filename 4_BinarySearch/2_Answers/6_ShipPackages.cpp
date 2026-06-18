#include<bits/stdc++.h>
int sumAll(vector<int>& weights){
    int sum = 0;
    for(int w : weights) sum += w;
    return sum;
}
int daysTaken(vector<int>& weights, int capacity){
    int days = 1, load = 0;
    for(int i = 0; i < weights.size(); i++){
        if(load + weights[i] > capacity){
            days++;
            load = weights[i];
        }
        else{
            load += weights[i];
        }
    }
    return days;
}
int linearShip(vector<int>& weights, int maxDays){
    // TC: O((Sum-maxi+1) * n)
    // SC: O(1)
    int maxi = *max_element(weights.begin(), weights.end());
    int sum = sumAll(weights);
    for(int i = maxi; i <= sum; i++){
        if(daysTaken(weights, i) <= maxDays){
            return i;
        }
    }
    return -1;
}
int binaryShip(vector<int>& weights, int maxDays){
    // TC: O(log(high-low+1) * n)
    // SC: O(1)
    int low = *max_element(weights.begin(), weights.end());
    int high = sumAll(weights);
    // int capacity = 0;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(daysTaken(weights, mid) <= maxDays){
            // capacity = mid;
            high = mid - 1;
        }
        else low = mid + 1; // if more days taken, then increase capacity to reduce days
    }
    // return capacity;
    return low;
}
int main(){
    vector<int> weights = {3, 6, 2, 9, 1, 5};
    int maxDays = 3;
    cout << linearShip(weights, maxDays) << endl;
    cout << binaryShip(weights, maxDays) << endl;
    return 0;
}
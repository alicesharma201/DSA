// stalls : {0, 9, 4, 2, 11} : {0, 2, 4, 9, 11}
// cows : 3
// output : 4 is the minimum largest distance possible for {0, 4, 11} 

#include<bits/stdc++.h>

bool canWePlace(int dist, int cows, vector<int>& stalls){ // Can we place all cows with a given minimum distance between the stalls?
    int cowCount = 1, lastCow = stalls[0];
    for(int j = 1; j < stalls.size(); j++){
        if(stalls[j] - lastCow >= dist){
            cowCount++;
            lastCow = stalls[j];
        }
        if(cowCount >= cows) return true;
    }
    return false;
}
int brute(int cows, vector<int>& stalls){
    // TC: O(n * (maxi-mini)) = O(n^2)
    // SC: O(1)
    int n = stalls.size();
    if(n < cows) return -1; // edge case
    sort(stalls.begin(), stalls.end());
    int mini = stalls[0], maxi = stalls[n-1];
    for(int i = 1; i <= maxi-mini; i++){
        if(canWePlace(i, cows, stalls) == true){
            continue;
        }
        else return (i - 1);
    }
    return -1;
}
int optimal(int cows, vector<int>& stalls){
    // TC: O(n * log(maxi-mini)) = o(nlogn)

    /* Concept of opposite polarity:
    if 'low' is pointing at the start of [T] and 'high' is pointing at end of [F]
    {1 : T} {2 : T} {3 : F} {4 : F} {5 : F} 
    low                                  high
    then after binary search, 'low' will point at start of [F] and 'high' will point at end of [T]
    {1 : T} {2 : T} {3 : F} {4 : F} {5 : F}
               high low
    */
    sort(stalls.begin(), stalls.end());
    int low = 1, high = stalls[stalls.size()-1] - stalls[0]; 
    while(low <= high){
        int mid = low + (high - low)/2;
        if(canWePlace(mid, cows, stalls) == true) low = mid + 1;
        else high = mid - 1;
    }
    return high;
}
int main(){
    int cows = 4;
    vector<int> stalls = {0, 3, 4, 7, 10, 9}; 
    cout << brute(cows, stalls) << endl;
    cout << optimal(cows, stalls) << endl;
    return 0;
}
#include<bits/stdc++.h>
int linearMissing(vector<int>& vec, int k){
    // TC: O(n)
    // SC: O(1)
    int n = vec.size();
    for(int i = 0; i < n; i++){
        if(vec[i] <= k) k++;
        else break;
    }
    return k;
}
int binaryMissing(vector<int>& vec, int k){
    // TC: O(logn)
    // SC: O(1)
    int n = vec.size();
    int low = 0, high = n - 1;
    int missing = 0;
    while(low <= high){
        int mid = low + (high - low)/2;
        missing = vec[mid] - (mid+1);
        if(missing < k) low = mid + 1;
        else high = mid - 1;
    }
    return low + k;
}
int main(){
    vector<int> vec = {2, 4, 6, 7, 9};
    int k = 4;
    cout << linearMissing(vec, k) << endl;
    cout << binaryMissing(vec, k) << endl;
    return 0;
}
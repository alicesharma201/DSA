#include <bits/stdc++.h>
void optimal(int n, int arr[]){
    unordered_map<int,int> mpp; // if TLE use map
    for(int i = 0; i < n; i++){
        mpp[arr[i]]++; // precomputing
    }
    for(auto num : mpp){
        cout << num.first << " -> " << num.second << endl;
    }
}
int main(){
    int arr[] = {10, 15, 5, 10, 10, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    optimal(n, arr); 
    return 0;
}
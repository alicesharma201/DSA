#include<bits/stdc++.h>
void self(int arr[], int n){
    unordered_map<int,int> mpp;
    for(int i = 0; i < n; i++){
        // precomputing
        mpp[arr[i]]++;
    }

    int maxfreq = 0;
    int minfreq = n;
    int maxkey = 0;
    int minkey = 0;
    for(auto it : mpp){
        if(maxfreq < it.second){
            maxfreq = it.second;
            maxkey = it.first;
        }
        if(minfreq > it.second){
            minfreq = it.second;
            minkey = it.first;
        }
    }
    cout << "Max key: " << maxkey << endl;
    cout << "Min key: " << minkey;

}
int main(){
    int arr[] = {10, 5, 10, 15, 10, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    self(arr, n);

    return 0;
}
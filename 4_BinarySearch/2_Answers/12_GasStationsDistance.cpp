#include<bits/stdc++.h>
/*
    start with an outer loop for gas stations that have been placed, from 1 -> k
*/
int placeGasStations(vector<int>& stations, int k){
    int n = stations.size();
    vector<int> howMany(n-1, 0); // here n-1 reprsents the empty sections
    for(int gasStations = 1; gasStations <= k; gasStations++){
        long double maxVal = -1;
        int maxIdx = -1;
        for(int i = 0; i < n; i++){
            int diff = stations[i+1] - stations[i];
            int sectionLen = diff / (howMany[i]+1);
            if(maxVal < sectionLen){
                maxVal = sectionLen;
                maxIdx = i;
            }
        }
    }
}
int main(){
    vector<int> stations = {1,2,3,4,5};
    int k = 5;
    cout << placeGasStations(stations, k) << endl;
    return 0;
}
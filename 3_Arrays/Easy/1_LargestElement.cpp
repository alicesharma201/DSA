#include<bits/stdc++.h>
int brute(vector<int> vec, int n){
    // TC: O(n^2)
    // SC: O(1)
    for(int i = 0; i <= n-1; i++){
        for(int j = 0; j <= n-2; j++){
            if(vec[j] > vec[j+1]) swap(vec[j], vec[j+1]);
        }
    }
    return vec[n-1];
}
int optimal(vector<int> vec, int n){
    // TC: O(n)
    // SC: O(1)
    int largest = vec[0];
    for(int i = 1; i < n; i++){
        if(largest < vec[i]) largest = vec[i];
    }
    return largest;
}
int main(){
    vector<int> vec = {38, 23, 56, 97, 12, 109, 45, 24, 19};
    int n = vec.size();
    cout << brute(vec, n) << endl;
    cout << optimal(vec, n);
    return 0;
}
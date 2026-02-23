#include<bits/stdc++.h>
void brute(vector<int>& vec, int n){
    if(n == 1) return;
    for(int j = 0; j <= n-2; j++){
        if(vec[j] > vec[j+1]) swap(vec[j], vec[j+1]);
    }
    brute(vec, n-1);
}
void optimal(vector<int>& vec, int n){
    if(n == 1) return;
    bool didswap = false;
    for(int j = 0; j <= n-2; j++){
        if(vec[j] > vec[j+1]){
            swap(vec[j], vec[j+1]);
            didswap = true;
        }
    }
    if(didswap == false) return;
    optimal(vec, n-1);
}
int main(){
    vector<int> vec = {3, 6, 2, 7, 4, 1, 5};
    int n = vec.size();
    // brute(vec, n);
    optimal(vec, n);
    for(int i = 0; i < n; i++){
        cout << vec[i] << " ";
    }
    return 0;
}
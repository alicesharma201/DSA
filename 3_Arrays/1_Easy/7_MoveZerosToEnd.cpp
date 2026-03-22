#include<bits/stdc++.h>
vector<int> brute(vector<int>& vec, int n){
    // TC: O(n)
    // SC: O(n)
    vector<int> temp(vec.size(), 0);
    int index = 0;
    for(int i = 0; i < n; i++){
        if(vec[i] != 0){
            temp[index] = vec[i];
            index++;
        }
    }
    for(int i = 0; i < n; i++) vec[i] = temp[i];
    return vec;
}
void optimal(vector<int>& vec, int n){ // two pointer method
    // TC: O(n)
    // SC: O(1)
    int j = -1;
    for(int i = 0; i < n; i++){ 
        if(vec[i] == 0){
            j = i; // we found our first zero
            break; 
        }
    }
    if(j == -1) return; // If this is true, meaning there were no zeroes found in the array, therefore we can return
    for(int i = j+1; i < n; i++){ // we will start right next from the first zero, the we will swap it with non zero elements
        if(vec[i] != 0){
            swap(vec[i], vec[j]);
            j++;
        }
    }
}
int main(){
    vector<int> vec = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
    int n = vec.size();
    // vector<int> result = brute(vec, n);
    optimal(vec, n);
    for(int i : vec) cout << i << " ";
    return 0;
}
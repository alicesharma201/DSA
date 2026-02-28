#include<bits/stdc++.h>
bool optimal(vector<int>& vec){
    // TC: O(n)
    // SC: O(1)
    int n = vec.size();
    for(int i = 0; i <= n-2; i++){
        if(vec[i] > vec[i+1]){
            return false;
        }
    }
    return true;
}
int main(){
    vector<int> arr1 = {3, 2, 6, 1, 7, 5};
    vector<int> arr2 = {1, 2, 3, 4};
    vector<int> arr3 = {0};
    cout << (optimal(arr1) ? "True" : "False") << endl;
    cout << (optimal(arr2) ? "True" : "False") << endl;
    cout << (optimal(arr3) ? "True" : "False") << endl;
    return 0;
}
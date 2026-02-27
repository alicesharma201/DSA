#include<bits/stdc++.h>
void brute(vector<int> vec, int n){
    // TC: O(n^2)
    // SC: O(1)  
    for(int i = 0; i <= n-1; i++){
        for(int j = 0; j <= n-2; j++){
            if(vec[j] > vec[j+1]) swap(vec[j], vec[j+1]);
        }
    }
    if(n == 0 || n == 1) cout << "Second Smallest: -1\nSecond Largest: -1\n"; 
    else{
        cout << "Second Smallest: " << vec[1] << endl;
        cout << "Second Largest: " << vec[n-2] << endl;
    }
}
void better(vector<int> vec, int n){
    // TC: O(2n)
    // SC: O(1)
    int smallest = INT_MAX, secondSmallest = INT_MAX;
    int largest = INT_MIN, secondLargest = INT_MIN;
    if(n == 0 || n == 1){
        cout << "Second Smallest: -1\nSecond Largest: -1\n"; 
        return;
    }
    for(int i = 0; i < n; i++){
        if(vec[i] < smallest) smallest = vec[i];
        if(vec[i] > largest) largest = vec[i];
    }
    for(int i = 0; i < n; i++){
        if(vec[i] != smallest && vec[i] < secondSmallest) secondSmallest = vec[i];
        if(vec[i] != largest && vec[i] > secondLargest) secondLargest = vec[i];
    }
    if(secondSmallest == INT_MAX) cout << "No second smallest exists.\n";
    else cout << "Second Smallest: " << secondSmallest << endl;
    if(secondLargest == INT_MIN) cout << "No second largest exists.\n";
    else cout << "Second Largest: " << secondLargest << endl;
}
int main(){
    vector<int> vec = {2, 2, 2, 2};
    int n = vec.size();
    brute(vec, n);
    better(vec, n);
    return 0;
}
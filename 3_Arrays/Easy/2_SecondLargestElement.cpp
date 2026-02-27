#include<bits/stdc++.h>
void brute(vector<int> vec, int n){
    // TC: O(n^2)
    // SC: O(1)  
    // The brute is still logically incorrect for test cases like {1, 1, 2, 3, 4} 
    if(n == 0 || n == 1){
        cout << "Second Smallest: -1\nSecond Largest: -1\n"; 
        return;
    }
    for(int i = 0; i <= n-1; i++){
        for(int j = 0; j <= n-2; j++){
            if(vec[j] > vec[j+1]) swap(vec[j], vec[j+1]);
        }
    }
    cout << "Second Smallest: " << vec[1] << endl;
    cout << "Second Largest: " << vec[n-2] << endl;
}
void better(vector<int> vec, int n){
    // TC: O(2n) = O(n)
    // SC: O(1)
    int small = INT_MAX, secondSmall = INT_MAX;
    int large = INT_MIN, secondLarge = INT_MIN;
    if(n == 0 || n == 1){
        cout << "Second Smallest: -1\nSecond Largest: -1\n"; 
        return;
    }
    for(int i = 0; i < n; i++){
        if(vec[i] < small) small = vec[i];
        if(vec[i] > large) large = vec[i];
    }
    for(int i = 0; i < n; i++){
        if(vec[i] > small && vec[i] < secondSmall) secondSmall = vec[i];
        if(vec[i] < large && vec[i] > secondLarge) secondLarge = vec[i];
    }
    if(secondSmall == INT_MAX) cout << "No second smallest exists.\n";
    else cout << "Second Smallest: " << secondSmall << endl;
    if(secondLarge == INT_MIN) cout << "No second largest exists.\n";
    else cout << "Second Largest: " << secondLarge << endl;
}
void optimal(vector<int> vec, int n){
    // TC: O(n)
    // SC: O(1)
    if(n == 0 || n == 1){
        cout << "Second Smallest: -1\nSecond Largest: -1\n"; 
        return;
    }
    int small = INT_MAX, secondSmall = INT_MAX;
    int large = INT_MIN, secondLarge = INT_MIN;
    for(int i = 0; i < n; i++){
        if(vec[i] < small){
            secondSmall = small;
            small = vec[i];   
        }
        else if(vec[i] > small && vec[i] < secondSmall){
            secondSmall = vec[i];
        }
        if(vec[i] > large){
            secondLarge = large;
            large = vec[i];   
        }
        else if(vec[i] < large && vec[i] > secondLarge){
            secondLarge = vec[i];
        }
    }
    if(secondSmall == INT_MAX) cout << "No second smallest exists.\n";
    else cout << "Second Smallest: " << secondSmall << endl;
    if(secondLarge == INT_MIN) cout << "No second largest exists.\n";
    else cout << "Second Largest: " << secondLarge << endl;
}
int main(){
    vector<int> vec = {1, 2, 1, 6, 7, 5};
    int n = vec.size();
    brute(vec, n);
    better(vec, n);
    optimal(vec, n);
    return 0;
}
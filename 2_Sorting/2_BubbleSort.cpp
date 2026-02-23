// push the maximum to the last by adjacent swapping
// best O(n) 
// avg & worst O(n^2)
#include<bits/stdc++.h>
void bubbleSort(vector<int>& vec, int n){
    for(int i = 0; i <= n-2; i++){
        bool didSwap = false; // optimized bubble sort
        for(int j = 0; j <= n-i-2; j++){
            // j+1 ≤ n-1
            //   j ≤ n-2
            if(vec[j] > vec[j+1]){  
                swap(vec[j], vec[j+1]);
                didSwap = true;
            }
        }
        if(didSwap == false) break;
        cout << "runs\n"; // to check
    }
}
int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> vec(n);
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }
    bubbleSort(vec, n);
    cout << "Sorted Elements: ";
    for(int i = 0; i < n; i++){
        cout << vec[i] << " ";
    }
    return 0;
}
// Take an element and put it in its correct order
// its like organising a deck cards in assending order
#include<bits/stdc++.h>
vector<int> insertionSort(vector<int>& vec, int n){
    for(int i = 1; i < n; i++){
        int key = vec[i];
        int j = i - 1;
        while(j >= 0 && vec[j] > key){
            vec[j+1] = vec[j];
            j--;
        }
        vec[j+1] = key;
    }
    return vec;
}
int main(){
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> vec(n);
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }
    insertionSort(vec, n);
    for(auto el : vec) cout << el << " ";
    return 0;
}
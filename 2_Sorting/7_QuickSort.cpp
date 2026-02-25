// 1. pick up a pivot and place it in its correct place
// 2. smaller on the left, larger on the right
#include<bits/stdc++.h>
int partition(vector<int> &vec, int low, int high){
    int pivot = vec[low];
    int i = low;
    int j = high;
    while(i < j){
        while(vec[i] <= pivot && i <= high-1) i++;
        while(vec[j] > pivot && j >= low+1) j--;
        if(i<j) swap(vec[i], vec[j]);
    }
    swap(vec[low], vec[j]);
    return j;
}
void qs(vector<int>& vec, int low, int high){
    if(low < high){
        int pIndex = partition(vec, low, high);
        qs(vec, low, pIndex-1);
        qs(vec, pIndex+1, high);
    }
}
void quickSort(vector<int>& vec){
    qs(vec, 0, vec.size()-1);
}
int main(){
    vector<int> vec = {3, 6, 2, 7, 4, 1, 5};
    int n = vec.size();
    quickSort(vec);
    for(int i = 0; i < n; i++) cout << vec[i] << " ";
    return 0;
}
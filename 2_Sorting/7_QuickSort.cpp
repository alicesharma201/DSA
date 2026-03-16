// TC: O(nlogn) worst case O(n^2)
// SC: O(1)
#include<bits/stdc++.h>
// pick up a pivot and place it in its correct place
// smaller on the left, larger on the right
int partition(vector<int> &vec, int low, int high){
    int pivot = vec[low];
    int i = low;
    int j = high;
    while(i < j){
        while(vec[i] <= pivot && i <= high-1) i++; // finds element greater than the pivot
        while(vec[j] > pivot && j >= low+1) j--; // finds element less than the pivot
        if(i<j) swap(vec[i], vec[j]); // don't swap if j has crossed i
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
vector<int> quickSort(vector<int>& vec){
    qs(vec, 0, vec.size()-1);
    return vec;
}
int main(){
    vector<int> vec = {3, 6, 2, 7, 4, 1, 5};
    int n = vec.size();
    vector<int> res = quickSort(vec);
    for(int i : res) cout << i << " ";
    return 0;
}
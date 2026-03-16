// TC: O(nlog(n))
// SC: O(n) because of temp
#include<bits/stdc++.h>
// low and high are just ranges
// while left and right are pointers
void Merge(vector<int>& vec, int low, int mid, int high){ // TC: O(n)
    vector<int> temp;
    int left = low;
    int right = mid+1;
    while(left <= mid && right <= high){
        if(vec[left] <= vec[right]){
            temp.emplace_back(vec[left]);
            left++;
        }
        else{
            temp.emplace_back(vec[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.emplace_back(vec[left]);
        left++;
    }
    while(right<=high){
        temp.emplace_back(vec[right]);
        right++;
    }
    for(int i = low; i <= high; i++){
        vec[i] = temp[i-low];
    }
}
void mergeSort(vector<int>& vec, int low, int high){ // TC: (log2(n))
    if(low == high) return;
    int mid = (low+high)/2;
    mergeSort(vec, low, mid);
    mergeSort(vec, mid+1, high);
    Merge(vec, low, mid, high);
}
int main(){
    vector<int> vec = {6, 2, 7, 3, 1, 4, 9, 5, 8};
    int n = vec.size();
    mergeSort(vec, 0, n-1);
    for(int i = 0; i < n; i++){
        cout << vec[i] << " ";
    }
    return 0;
}
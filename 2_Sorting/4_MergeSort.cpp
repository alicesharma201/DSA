#include<bits/stdc++.h>
void Merge(vector<int>& vec, int low, int mid, int high){
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
void mergeSort(vector<int>& vec, int low, int high){
    if(low == high) return;
    int mid = (low+high)/2;
    mergeSort(vec, low, mid);
    mergeSort(vec, mid+1, high);
    Merge(vec, low, mid, high);
}
int main(){
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    vector<int> vec(n);
    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }
    mergeSort(vec, 0, n-1);
    for(int i = 0; i < n; i++){
        cout << vec[i] << " ";
    }
    return 0;
}
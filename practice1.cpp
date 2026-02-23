#include<bits/stdc++.h>
void bubbleSort(vector<int>& vec, int n){
    for(int i = 0; i <= n-1; i++){
        bool didSwap = false;
        for(int j = 0; j <= n-i-2; j++){
            if(vec[j] > vec[j+1]){
                int temp = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = temp;
                didSwap = true;
            }
        }
        if(didSwap == false) break; 
    }
}
void selectionSort(vector<int>& vec, int n){
    for(int i = 0; i <= n-1; i++){
        int mini = i;
        for(int j = i; j <= n-1; j++){
            if(vec[mini] > vec[j]) mini = j;
        }
        swap(vec[mini], vec[i]);
    }
}
void insertionSort(vector<int>& vec, int n){
    for(int i = 1; i < n; i++){
        int key = vec[i];
        int j = i - 1; 
        while(j >= 0 && vec[j] > key){
            vec[j+1] = vec[j];
            j--;
        }
        vec[j+1] = key;
    }
}
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
        vec[i] = temp[i - low];
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
    vector<int> vec = {5, 3, 2, 6, 8, 7, 1, 9, 4};
    int n = vec.size();
    // bubbleSort(vec, n);
    // selectionSort(vec, n);
    insertionSort(vec, n);
    // mergeSort(vec, 0, n-1);
    for(int i = 0; i < n; i++){
        cout << vec[i] << " ";
    }
    return 0;
}
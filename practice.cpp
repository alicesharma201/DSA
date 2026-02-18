#include<bits/stdc++.h>
void selectionSort(int arr[], int n){
    for(int i = 0; i <= n-2; i++){
        int mini = i;
        for(int j = i; j <= n-1; j++){
            if(arr[mini] > arr[j]) mini = j;
        }
        // int temp = mini;
        // mini = i; 
        // i = temp;
        swap(arr[mini], arr[i]);
    }
}
int main(){
    int arr[] = {5, 3, 6, 2, 4, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}
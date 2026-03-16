#include<bits/stdc++.h>
int linearSearch(int arr[], int n, int find){
    for(int i = 0; i < n; i++){
        if(arr[i] == find) return i;
    }
    return -1;
}
int main(){
    int arr[] = {3, 2, 1, 6, 7, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int find = 6;
    int result = linearSearch(arr, n, find);
    if(result == -1) cout << "Element not found";
    else cout << "Element " << find << " is found at index " << result;
    return 0;
}
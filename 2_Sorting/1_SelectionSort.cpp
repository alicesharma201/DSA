// select minimums and swap
#include<bits/stdc++.h>
void selectionSort(vector<int>& vec, int n){
    for(int i = 0; i <= n-2; i++){
        int mini = i;
        for(int j = i; j <= n-1; j++){
            if(vec[j] < vec[mini]){
                mini = j; 
            }
        }
        swap(vec[mini], vec[i]);
    }
}
int main(){
    int n;
    vector<int> vec(n);
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }
    selectionSort(vec, n);
    cout << "Sorted Elements: ";
    for(int i = 0; i < n; i++){
        cout << vec[i] << " "; 
    }
    return 0;
}
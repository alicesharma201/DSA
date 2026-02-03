#include<bits/stdc++.h>

vector<int> brute(vector<int> arr){
    int size = arr.size();
    vector<int> aux(size);
    for(int i = 0; i < size; i++){
        aux[i] = arr[size-1-i];
    }
    return aux;
}

vector<int> better(vector<int> arr){
    int size = arr.size();
    int left = 0;
    int right = size-1;
    while(left < right){
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
    return arr;
}

vector<int> stl(vector<int> arr){
    reverse(arr.begin(), arr.end());
    return arr;
}

int main(){
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> aux1 = brute(arr1);
    for(int i : aux1) cout << i << " ";
    cout << endl;

    vector<int> arr2 = {5, 10, 15, 20};
    vector<int> aux2 = better(arr2);
    for(int i : aux2) cout << i << " ";
    cout << endl;

    vector<int> arr3 = {67, 68, 69, 70};
    vector<int> aux3 = stl(arr3);
    for(int i : aux3) cout << i << " ";
    cout << endl;

    return 0;
}
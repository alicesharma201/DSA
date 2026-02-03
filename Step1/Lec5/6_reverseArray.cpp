#include <bits/stdc++.h>

void self(int arr[], int aux[], int size, int index){
    // recursive approach
    if(index == size) return;
    aux[index] = arr[size-1-index];
    self(arr, aux, size, index+1);
}

vector<int> brute(vector<int> vec){
    int size = vec.size();
    vector<int> aux(size);
    for(int i = 0; i < size; i++){
        aux[i] = vec[size-1-i];
    }
    return aux;
}

vector<int> better(vector<int> vec){
    // creating two pointers
    int front = 0;
    int back = vec.size()-1;
    while(front < back){
        swap(vec[front], vec[back]);
        front++;
        back--;
    }
    return vec;
}

int main(){
    
    int arr[] = {10, 20, 30, 40, 50};

    int size = sizeof(arr)/sizeof(arr[0]);
    int aux[size];

    cout << "Self: ";
    self(arr, aux, size, 0); 
    for(int i : aux) cout << i << " ";
    cout << endl;

    cout << "Brute force: ";
    vector<int> vec = {5, 4, 3, 2, 1};
    vector<int> bruteResult = brute(vec);
    for(int i : bruteResult) cout << i << " ";
    cout << endl;

    cout << "Better: ";
    vector<int> vec2 = {8, 6, 4, 2};
    vector<int> betterResult = better(vec2);
    for(int i : betterResult) cout << i << " ";
    cout << endl;

    /*
    using std::reverse
    The Standard Template Library provides a built-in reverse() function in <algorithm >, 
    which reverses the contents of a container in-place. 
    It uses two pointers internally to swap elements from both ends toward the center, 
    making the solution efficient and concise.
    */
    cout << "STL: ";
    vector<int> vec3 = {65, 66, 67, 68, 69};
    reverse(vec3.begin(), vec3.end());
    for(int i : vec3) cout << i << " ";
    
    return 0;
}
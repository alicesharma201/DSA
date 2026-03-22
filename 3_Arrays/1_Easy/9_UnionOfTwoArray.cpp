#include<bits/stdc++.h>
vector<int> mapMethod(vector<int>& arr1, vector<int>& arr2, int m, int n){
    // TC: O((m+n) log(m+n))
    // SC: O(m+n)
    map<int, int> freq;
    vector<int> Union;
    // If key does NOT exist, then map automatically creates the key with a default value.
    for(int i = 0; i < m; i++) freq[arr1[i]]++; // Inserting a key in map takes logN time
    for(int i = 0; i < n; i++) freq[arr2[i]]++;
    for(auto &it : freq) Union.push_back(it.first);
    return Union;
}
vector<int> setMethod(vector<int>& arr1, vector<int>& arr2){
    // TC: O((m+n) log(m+n))
    // SC: O(m+n)
    set<int> st;
    for(int i : arr1) st.insert(i); // Inserting an element in a set takes logN time
    for(int i : arr2) st.insert(i);
    vector<int> Union(st.begin(), st.end());
    return Union;
}
vector<int> optimal(vector<int>& arr1, vector<int>& arr2, int m, int n){ // Two pointer
    // TC: O(m+n)
    // SC: O(m+n)
    int i = 0, j = 0;
    vector<int> Union;
    while(i < m && j < n){
        if(arr1[i] < arr2[j]){ 
            if(Union.empty() || Union.back() != arr1[i]) Union.push_back(arr1[i]); 
            i++;
        }
        else if(arr1[i] > arr2[j]){ 
            if(Union.empty() || Union.back() != arr2[j]) Union.push_back(arr2[j]); 
            j++;
        }
        else if(arr1[i] == arr2[j]){ 
            if(Union.empty() || Union.back() != arr1[i]) Union.push_back(arr1[i]); 
            i++; j++;
        }
    }
    while(i < m){
        if(Union.empty() || Union.back() != arr1[i]) Union.push_back(arr1[i]);  
        i++;   
    }
    while(j < n){
        if(Union.empty() || Union.back() != arr2[j]) Union.push_back(arr2[j]); 
        j++;
    }

    return Union;
}
int main(){
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {2, 4, 6};
    int m = arr1.size();
    int n = arr2.size();

    vector<int> method1 = mapMethod(arr1, arr2, m, n);
    cout << "Union using map method: ";
    for(int i : method1) cout << i << " ";

    cout << "\nUnion using set method: ";
    vector<int> method2 = setMethod(arr1, arr2);
    for(int i : method2) cout << i << " ";

    cout << "\nUnion using two pointer method: ";
    vector<int> method3 = optimal(arr1, arr2, m, n);
    for(int i : method3) cout << i << " ";

    return 0;
}
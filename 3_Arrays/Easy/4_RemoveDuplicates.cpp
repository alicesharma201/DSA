/*
Problem Statement: 
Given an integer array sorted in non-decreasing order, remove the duplicates "in place" such that each unique element appears only once. The relative order of the elements should be kept the same.
If there are k elements after removing the duplicates, then the first k elements of the array should hold the final result. It does not matter what you leave beyond the first k elements.

“In-place” means:
You must modify the original data structure itself
without using extra memory that grows with input size.
Extra Space Complexity should be O(1)
*/
#include<bits/stdc++.h>
int brute(vector<int>& vec){
    // TC: O(n)
    // SC: O(n)
    unordered_set<int> seen;
    int index = 0;
    for(int num : vec){
        if(seen.find(num) == seen.end()){ // here, if set doesn't contain the element, seen.find(num) will point to end()
            seen.insert(num);
            vec[index] = num;
            index++;
        }
    }
    return index;
}
int optimal(vector<int>& vec){
    // TC: O(n)
    // SC: O(1)
    int i = 0;
    int n = vec.size();
    for(int j = 1; j < n; j++){
        if(vec[i] != vec[j]){
            vec[i+1] = vec[j];
            i++;
        }
    }
    return i+1; // here i is the 'index' till the unique elements are present
}
int main(){
    vector<int> vec1 = {1,1,2,2,2,3,3,4};
    int k = brute(vec1);
    cout << "k = " << k << "\nArray after removing duplicates: ";
    for(int i = 0; i < k; i++){
        cout << vec1[i] << " ";
    }
    cout << endl;
    vector<int> vec2 = {1,1,2,2,2,3,3};
    int K = optimal(vec2);
    cout << "k = " << K << "\nArray after removing duplicates: ";
    for(int i = 0; i < K; i++){
        cout << vec2[i] << " ";
    }
    return 0;
}
#include<bits/stdc++.h>
int brute(vector<int>& vec){
    // TC: O(n^2)
    // SC: O(1)
    int n = vec.size();
    for(int i = 1; i <= n+1; i++){ // since one element is missing, we will run the loop till n+1 starting from 1
        bool found = false;
        for(int j = 0; j < n; j++){ // checking with all the elements of the array
            if(vec[j] == i){
                found = true; 
                break;
            }
        }
        if(found == false) return i;
    }
    return -1;
}
int hashMethod(vector<int>& vec){
    // TC: O(n) + O(n) = O(n)
    // SC: O(n)
    int n = vec.size();
    vector<int> hash(n+2, 0);
    for(int j = 0; j < n; j++){ // here, if the element is present in the array, it will get incremented by 1 in the hash array
        hash[vec[j]]++;
    }
    for(int i = 1; i <= n+1; i++){ // we are ignoring the first element zero here
        if(hash[i] == 0) return i; // if element was not present, the hash array will contain zero at its position
    }
    return -1;
}
int sumMethod(vector<int>& vec){
    // TC: O(n)
    // SC: O(1)
    int n = vec.size() + 1; // size of the array + the space for the missing element
    // sum of n numbers formula (there's overflow issue)
    // int sum = (n*(n+1))/2; 
    long long sum = (long long)n*(n+1)/2;
    int actualSum = 0;
    for(int i = 0; i < n-1; i++){ // array runs till n-2 because thats the indexing for the elements in the original array
        actualSum += vec[i]; // actual sum of the array
    }
    return (sum - actualSum);
}
int xorMethod(vector<int>& vec){
    // Property of XOR : 
    // a ^ a = 0
    // a ^ 0 = a

    // TC: O(n)
    // SC: O(1)
    int n = vec.size();
    int xor1 = 0, xor2 = 0;
    for(int i = 1; i <= n+1; i++){
        xor1 ^= i; // 1 ^ 2 ^ 3 ^ 4 ^ 5
    }
    for(int i = 0; i < n; i++){
        xor2 ^= vec[i]; // 3 ^ 5 ^ 1 ^ 2
    }
    return xor1 ^ xor2; // (1 ^ 2 ^ 3 ^ 4 ^ 5) ^ (3 ^ 5 ^ 1 ^ 2) = 4
}
int main(){
    vector<int> vec = {3, 5, 1, 2};
    cout << brute(vec) << endl;
    cout << hashMethod(vec) << endl;
    cout << sumMethod(vec) << endl;
    cout << xorMethod(vec) << endl;
    return 0;
}
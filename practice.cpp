#include<bits/stdc++.h>
/*
1. take input of number of elements of array
2. enter the elements of array
3. precompute the count of numbers in hash array
4. take input of the number of queries
5. enter the queries
6. fetch the count of numbers from hash array
*/
int main(){
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // precomputing
    int hash[100] = {0};
    for(int i = 0; i < n; i++){
        hash[arr[i]] += 1;
    }

    int q;
    cout << "Number of queries: ";
    cin >> q;
    cout << "Queries: ";
    while(q--){
        int number;
        cin >> number;
        cout << number << " : " << hash[number] << endl;
    }

    
    return 0;
}
/* hashing algo
1. take input of number of elements of array
2. enter the elements of array
3. precompute the count of numbers in hash array
4. take input of the number of queries
5. enter the queries
6. return the count of numbers from hash array
*/

#include<bits/stdc++.h>
using namespace std;
int main(){

    // size of array
    cout << "Enter the size of array: ";
    int n;
    cin >> n;

    // creating array of integers
    cout << "Enter the elements of array: ";
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // precomputing: here we will count which number has appeared how many times
    // let us assume that the problem states that we can take queries upto 1 to 12
    int hash[13] = {0}; // since the query limit is upto 12, we will create a hash array of 13
    for(int i = 0; i < n; i++){
        hash[arr[i]] += 1;
    }

    // taking input of queries
    int q;
    cout << "Enter the number of queries: ";
    cin >> q;
    cout << "Enter queries: ";
    while(q--){ // while q > 0 then q--
        int number;
        cin >> number;
        // fetching
        cout << number << " appears " << hash[number] << " times" << endl;
    }

    return 0;
}

/*
For int:
    main()
        arr[10^6] is possible 
        Then it throws segmentation fault
    Globally 
        arr[1e7] is possible (which is 10^7)

For bool: 
    main()
        arr[10^7]
    Global
        arr[10^8]
*/
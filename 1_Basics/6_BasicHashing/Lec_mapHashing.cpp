/* Hashing using Maps

Key   → number
Value → frequency (count)

We don't need to create a large hash array (like size 10^7) because
map / unordered_map store only the elements that actually appear,
along with their counts → more memory efficient for large ranges.

Time Complexity:

map:
    - Stores keys in sorted order (implemented using Red-Black Tree)
    - Insertion / Fetching: O(log N) in worst / average / best case
unordered_map:
    - Stores keys using hashing
    - Insertion / Fetching: O(1) in average / best case
    - O(N) in worst case (due to collisions)
∴ Prefer unordered_map in most cases.
   Use map if ordering is required or worst-case TLE occurs.

pair<int,int> can be used as a key in map,
but not directly in unordered_map (needs custom hash).

------------------------------------------------------

Collision:

A collision occurs when two different keys produce
the same hash index after applying a hash function.

Example:
Let h(x) = x % 10

h(15) = 5
h(25) = 5

Both keys map to the same index (5) → Collision occurs.

In STL (like unordered_map), hashing and collision
handling are done internally (no need to implement manually).

Some hashing methods:
1. Division Method      → h(x) = x % m
2. Folding Method
3. Mid-Square Method
*/

#include<bits/stdc++.h>
int main(){
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of array: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // precomputing
    map<int, int> mpp; 
    for(int i = 0; i < n; i++){
        mpp[arr[i]]++;
    }

    // a map stores everything in sorted order
    // for(auto num : mpp) cout << num.first << ": " << num.second << endl;

    int q;
    cout << "Enter the size of queries: ";
    cin >> q;
    cout << "Enter the queries: ";
    while(q--){
        int number;
        cin >> number;
        // fetch
        cout << number << " -> " << mpp[number] << endl;
    }

    return 0;
}
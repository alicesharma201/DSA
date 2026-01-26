// priority_queue is not a linear data structure but a tree data structure
// aka Max heap

/* Time complexity:
push: logn
pop: logn
top: O(1)
*/

#include<bits/stdc++.h>
int main(){
    priority_queue<int> pq;
    pq.push(5); // {5}
    pq.push(2); // {5, 2}
    pq.push(10); // {10, 5, 2}
    pq.emplace(8); // {10, 8, 5, 2}

    cout << pq.top() << endl; // 10

    // size swap empty function same as others

    // Minimum Heap (like a minimum priority queue)
    priority_queue<int, vector<int>, greater<int>> mpq;
    mpq.push(5); // {5}
    mpq.push(2); // {2, 5}
    mpq.push(10); // {2, 5, 10}
    mpq.push(8); // {2, 5, 8, 10}

    cout << mpq.top() << endl; // 2

    return 0;
}
#include<bits/stdc++.h>
int main(){
    queue<int> q;
    q.push(1); // {1}
    q.push(2); // {1, 2}
    q.push(3); // {1, 2, 3}

    q.back() += 3; // {1, 2, 6}

    cout << q.back() << endl; // 6

    cout << q.front() << endl; // 1

    q.pop(); // {2, 6}
    cout << q.front() << endl; // 2

    // size swap empty same as stack

    return 0;
}
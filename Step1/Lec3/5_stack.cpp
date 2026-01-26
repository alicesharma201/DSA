#include <bits/stdc++.h>

int main(){
    stack<int> st;
    st.push(1); // {1}
    st.push(5); // {5, 1}
    st.push(3); // {3, 5, 1}
    st.emplace(9); // {9, 3, 5, 1}

    cout << "LIFO: " << st.top() << endl; // 9
    st.pop();
    cout << "LIFO: " << st.top() << endl; // 3
    cout << "size: " << st.size() << endl; 
    cout << "is empty? " << st.empty() << endl; // 0:false 1:true

    stack<int>st1, st2;
    st1.swap(st2); // swap funtion

    return 0;
}
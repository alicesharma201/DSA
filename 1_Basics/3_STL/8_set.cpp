// set: sorted and unique
// everything happens in 'logn' time complexity

#include <bits/stdc++.h>
int main(){
    set<int>st;
    st.insert(3); // {3}
    st.insert(2); // {2, 3}
    st.emplace(2); // {2, 3}
    st.emplace(1); // {1, 2, 3}
    st.insert(4); // {1, 2, 3, 4}

    // .find() returns an iterator which points to the element's address
    auto it1 = st.find(3);

    // if element does not exist in set, it returns an iterator which points at st.end()
    auto it2 = st.find(6);

    // .erase() takes logarithmic time
    st.erase(1);

    int cnt = st.count(3); // if present, returns 1. If not, returns 0.

    auto it3 = st.find(3); // returns the iterator

    st.erase(it3); // can erase an element or iterator

    auto it4 = st.find(2);
    auto it5 = st.find(4);
    st.erase(it4, it5); // [first, last) only 4 is left now

    set<int> st2 = {10, 11, 12, 14};
    auto it6 = st2.lower_bound(11); // returns an iterator pointing towards 11
    auto it7 = st2.upper_bound(11); // returns an iterator pointing towards 12
    cout << *it6 << " " << *it7 << endl;

    // here, 13 doesn't exist, so it points towards the next element
    auto it8 = st2.lower_bound(13);
    auto it9 = st2.upper_bound(13);
    cout << *it8 << " " << *it9 << endl;

    // points at end()
    auto it10 = st2.lower_bound(15);
    auto it11 = st2.upper_bound(15);
    cout << *it10 << " " << *it11 << endl; 

    return 0;
}
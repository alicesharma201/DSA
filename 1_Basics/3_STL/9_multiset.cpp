// multiset: sorted but 'not' unique
#include <bits/stdc++.h>
int main(){
    multiset<int>ms;
    ms.insert(1); // {1}
    ms.insert(1); // {1, 1}
    ms.insert(1); // {1, 1, 1}

    // set: count() returns 1 or 0 if element exists or not
    // multiset: count() gives the no. of occurance of element
    int cnt = ms.count(1); 
    cout << cnt << endl;

    ms.erase(1); // {} erases all elements

    multiset<int>ms2 = {2, 2, 2};
    ms2.erase(ms2.find(2)); // {2, 2} only one occurance is erased
    for(auto it : ms2) cout << it << " ";

    return 0;
}
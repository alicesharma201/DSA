// map: container which stores unique keys in sorted order, and values(which can be same)
// map<key, value> var;
// time complexity: O(logn)
#include <bits/stdc++.h>
int main(){
    map<int, int> mp;
    /* examples of declaring map:
    map<int, pair<int, int>> map1;
    map<pair<int, int>, int> map2;
    */
    
    // ways to insert elements
    mp[1] = 6; // var[key] = value
    mp.emplace(3, 5); // (key, value)
    mp.insert({2, 7}); // ({key, value})

    for(auto it : mp) cout << it.first << ", " << it.second << endl;
    cout << mp[1] << endl; // gives value
    cout << mp[5] << endl; // null

    cout << "using iterator: ";
    auto it = mp.find(2);
    cout << (*it).first << " " << (*it).second << endl;

    map<pair<int, int>, int> mp2;
    mp2[{2,3}] = 1;

    // lower_bound, upper_bound are like set and erase, swap, size, empty, etc. are same

    return 0;
}
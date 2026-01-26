#include<bits/stdc++.h>
int main(){

    pair<int, int> p = {3, 2};
    cout << p.first << " " << p.second << endl;

    pair<int, pair<int, int>> three = {3, {6, 9}};
    cout << three.first << " " << three.second.first << " " << three.second.second << endl;

    pair<int, int> arr[] = {{1, 6}, {9, 11}, {4, 7}, {20, 30}};
    cout << arr[0].first << " " << arr[3].second;
    
    return 0;
}
#include<bits/stdc++.h>

bool comp(pair<int,int> p1, pair<int,int> p2){
    if(p1.second < p2.second) return true;
    if(p1.second > p2.second) return false;
    if(p1.second == p2.second){ 
        if(p1.first < p2.first) return false; // decending order for first
        if(p1.first > p2.first) return true;
    }

    return false;
}

int main(){

    /* sort: [begin, end)
    sort(a, a+n);
    sort(v.begin, v.end); for vectors
    can sort any container
    can't sort map tho
    */

    int a[5] = {4, 3, 2, 5, 1};
    sort(a, a+5);
    for(auto it : a) cout << it << " ";
    cout << endl;

    int maxi = *max_element(a, a+5);
    cout << "max_element: " << maxi << endl;
    int mini = *min_element(a, a+5);
    cout << "min_element: " << mini << endl;

    cout << "Decending order: ";
    // sort(a, a+n, greater<int>())
    int d[4] = {20, 70, 40, 50};
    sort(d, d+4, greater<int>());
    for(auto it : d) cout << it << " ";
    cout << endl;

    /* To sort in your own way: 
    {{1,2}, {2,1}, {4,1}}

    Problem: 
    Sort it accoring to 'second' element
    if second element is same,
    then sort it according to 'first' element but in 'descending'

    we will create a boolean comparator

    required output: {{4,1}, {2,1}, {1,2}}
    */

    pair<int,int> p[] = {{1,2}, {2,1}, {4,1}};
    cout << "Sort my way using bool comparator: ";
    sort(p, p+3, comp);
    for(auto it : p) cout << it.first << " " << it.second << " , ";
    cout << endl;

    cout << "Builtin Popcount: ";
    int num = 7; // 111 in binary
    int cnt = __builtin_popcount(num);
    cout << cnt << " "; // returns set bits, meaning number of occurances of 1 stored in a 32 bit format

    long long numll = 98765432198765;
    int cntll = __builtin_popcountll(numll);
    cout << cntll << endl; 

    cout << "Permutations in dictionary/lexicographical order: ";
    string s = "123";
    sort(s.begin(), s.end()); // to start with the first permutation of dictionary order
    do{
        cout << s << " ";
    }while(next_permutation(s.begin(), s.end()));

    return 0;
}
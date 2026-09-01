#include<bits/stdc++.h>
using namespace std;
vector<int> brute(int n){
    // TC: O(n)
    // SC: O(res)
    vector<int> res;
    for(int i = 1; i <= n; i++){
        if(n % i == 0) res.push_back(i);
    }
    return res;
}
vector<int> optimal(int n){
    // TC: O(sqrt(n))
    // SC: O(res)
    vector<int> res;
    for(int i = 1; i * i <= n; i++){
        if(n % i == 0){
            res.push_back(i);
            if(i != n/i) res.push_back(n/i);
        }
    }
    return res;
}
int main(){
    for(int i : brute(36)) cout << i << " "; cout << endl;
    for(int i : optimal(36)) cout << i << " "; cout << endl;
    return 0;
}
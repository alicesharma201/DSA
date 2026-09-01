#include<bits/stdc++.h>
using namespace std;
bool prime(int n){
    int cnt = 0;
    for(int i = 1; i * i <= n; i++){
        if(n % i == 0){
            cnt++;
            if(n/i != i) cnt++;
        }
    }
    if(cnt == 2) return true;
    return false;
}
vector<int> brute(int n){ // brute force
    // TC: approx O(√n * 2 * √n) = O(2n)
    vector<int> res;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            if(prime(i)) res.push_back(i);
            if(n/i != i){
                if(prime(n/i)) res.push_back(n/i);
            }
        }
    }
    if(n > 1) res.push_back(n);
    return res;
}
vector<int> optimal(int n){ // personal preference
    // TC: O(√n + logn)
    vector<int> res;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            res.push_back(i);
            while(n % i == 0) n = n / i; // only for repeated primes
        }
    }
    if(n > 1) res.push_back(n);
    return res;
}
int main(){
    int n = 780;
    for(int i : brute(n)) cout << i << " "; cout << endl;
    for(int i : optimal(n)) cout << i << " ";
    return 0;
}
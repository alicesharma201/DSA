#include<bits/stdc++.h>
using namespace std;
bool isPrime(int n){
    int cnt = 0;
    for(int i = 1; i * i <= n; i++){
        if(n % i == 0){
            cnt++;
            if(i != n/i) cnt++;
        }
    }
    if(cnt == 2) return true;
    return false;
}
vector<int> selfBrute(vector<vector<int>>& queries){
    // TC: O((R - L + 1) × √R)
    vector<int> ans;
    for(int i = 0; i < queries.size(); i++){
        int primeCnt = 0;
        for(int j = queries[i][0]; j <= queries[i][1]; j++){
            if(isPrime(j)) primeCnt++;
        }
        ans.push_back(primeCnt);
    }
    return ans;
}
vector<int> selfOptimal(vector<vector<int>>& queries){ // Sieve of Eratosthenes
    vector<int> ans;
    int maxVal = 0;
    for (auto query : queries) {
        maxVal = max(maxVal, query[1]);
    }
    vector<bool> prime(maxVal+1, true);
    prime[0] = prime[1] = false;
    for(int i = 2; i*i < maxVal; i++){
        if(prime[i]){ // if its true
            for(int j = i*i; j < maxVal; j += i){
                prime[j] = 0; // set it to false
            }
        }
    }
    for(int i = 0; i < queries.size(); i++){
        int cnt = 0;
        for(int j = queries[i][0]; j <= queries[i][1]; j++){
            if(prime[j]) cnt++;
        }
        ans.push_back(cnt);
    }
    return ans;
}
// there's a prefix sum method that you should try and understand which is actually optimal
int main(){
    vector<vector<int>> queries = {{2,5}, {4,7}};
    for(int i : selfBrute(queries)) cout << i << " "; cout << endl;
    for(int i : selfOptimal(queries)) cout << i << " ";
    return 0;
}
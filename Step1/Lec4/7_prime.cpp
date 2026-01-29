#include<bits/stdc++.h>
bool brute(int n){
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(n % i == 0) {
            cnt++;
        }
    }
    if(cnt == 2) return true;
    return false;
}
bool optimal(int n){
    int cnt;
    for(int i = 1; i * i <= n; i++){
        if(n % i == 0){
            cnt++;
            if(n/i != i) cnt++;
        } 
    }
    if(cnt == 2) return true;
    return false;
}
int main(){
    int n;
    cin >> n;
    cout << brute(n) << endl;
    cout << optimal(n) << endl;
    // cout << app3(n) << endl;
    return 0;
}
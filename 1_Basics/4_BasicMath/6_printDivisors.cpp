#include<bits/stdc++.h>
vector<int> brute(int n){ // O(n)
    vector<int> folder;
    for(int el = 1; el <= n; el++){
        if(n % el == 0){
            folder.push_back(el);
        }
    }
    return folder;
}
vector<int> optimal(int n){ // O(sqrt(n))
    vector<int> folder;
    for(int i = 1; i*i <= n; i++){ // sqrt(n)
        if(n % i == 0){
            folder.push_back(i);
            if(i != n/i) folder.push_back(n/i);
        }
    }
    return folder;
}
int main(){
    int n;
    cin >> n;

    // brute
    vector<int> divisors1 = brute(n);
    for(int i : divisors1) cout << i << " ";
    cout << endl;

    // optimal
    vector<int> divisors2 = optimal(n); 
    for(int i : divisors2) cout << i << " ";
    cout << endl;

    return 0;
}
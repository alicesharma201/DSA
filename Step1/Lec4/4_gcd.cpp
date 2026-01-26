#include <bits/stdc++.h>

int brute(int n1, int n2){
    int gcd = 1;
    for(int i = 1; i <= min(n1, n2); i++){
        if(n1 % i == 0 && n2 % i == 0){
            gcd = i;
        }
    }
    return gcd;
}

int better(int n1, int n2){
    int gcd = 1;
    for(int i = min(n1, n2); i > 0; i--){
        if(n1 % i == 0 && n2 % i == 0){
            return i;
        }
    }
    return 1;
}

int optimal(int n1, int n2){ // euclidean algorithm
    if(n1 == min(n1,n2)){
        do{

        }while(n2 < n2-n1);
        if(n2 > n2-n1) 
    }

}

int main(){
    int n1, n2;
    cin >> n1 >> n2;
    cout << brute(n1, n2) << endl;
    cout << better(n1, n2) << endl;
    cout << optimal(n1, n2) << endl;
    return 0;
}
#include <bits/stdc++.h>
bool check(int n){
    int toCount = n;
    int count = 0;
    int original = n;
    int sum = 0;

    while(toCount > 0){
        toCount = toCount / 10;
        count++;
    } // or just use count = to_string(n).length()
    
    while(n > 0){
        int extract = n % 10;
        n = n / 10;
        sum += pow(extract, count);
    }

    return sum == original;
}
int main(){
    int n;
    cin >> n;
    if(check(n)) cout << n << " is an Armstrong number.";
    else cout << n << " is NOT an Armstrong number.";
    return 0;
}
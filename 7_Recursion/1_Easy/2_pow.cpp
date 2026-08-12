#include<bits/stdc++.h>
using namespace std;
double iterativePower(double x, int n){
    // TC: O(n)
    // SC: O(1)
    // Why it fails? it is too slow, if n is INT_MAX it'll have to do INT_MAX iterations
    if(n == 0 || x == 1) return 1;
    if(n == 1) return x;
    double ans = 1;
    long long temp = n;
    if(n < 0){
        x = 1/x;
        temp = -1*(1LL)*n; // handes the edge case n = -2,147,483,648(INT_MIN) -> 2,147,483,648 : integer overflow because INT_MAX is 2,147,483,647
    }
    for(long long i = 0; i < temp; i++){
        ans *= x;
    }
    return ans;
}
double betterPower(double x, int n){
    // TC: O(logn)
    // SC: O(1)
    if(n == 0 || x == 1) return 1;
    if(n == 1) return x;
    double ans = 1;
    long long temp = n;
    if(temp < 0){
        x = 1/x;
        temp = -1*temp;
    }
    while(temp){
        if(temp % 2 == 0){
            x = x * x;
            temp = temp/2;
        }else{
            ans = ans * x;
            temp = temp-1;
        }
    }
    return ans;
}
double helper(double x, long long n){
    if(n == 0 || x == 1) return 1;
    if(n == 1) return x;
    if(n % 2 == 0) return helper((x*x),(n/2));
    else return x * helper(x, n-1);
}
double recursivePower(double x, int n){
    // TC: O(logn)
    // SC: O(logn)
    long long temp = n;
    if(temp < 0) return helper(1/x, -1*temp);
    return helper(x, temp);
}
int main(){
    cout << iterativePower(2, 10) << endl;
    cout << betterPower(2, 10) << endl;
    cout << recursivePower(2, 10) << endl;
    return 0;
}
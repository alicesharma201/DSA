#include <bits/stdc++.h>
bool check(int n){
    int reverse = 0;
    int original = n;
    while(n > 0){
        int ld = n % 10;
        reverse = (reverse*10) + ld;
        n = n / 10;
    }
    if(original == reverse) return true;
    else return false;
}
int main(){
    int n;
    cin >> n;
    if(check(n)) cout << n << " is a palindrome";
    else cout << n << "It is not a palindrome";
    return 0;
}

/* leetcode
class Solution {
public:
    bool isPalindrome(int x) {
        int original = x;
        int reverse = 0;
        if(x < 0) return false;
        while(x > 0){
            int num = x % 10;
            if(reverse > INT_MAX / 10) return false;
            reverse = (reverse*10)+num;
            x = x / 10;
        }
        return original == reverse;
    }
};
*/
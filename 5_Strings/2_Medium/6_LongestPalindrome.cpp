#include<bits/stdc++.h>

bool isPalindrome(const string& s, int first, int last) {
    while(first <= last){
        if(s[first] != s[last]) return false;
        first++; last--;
    }
    return true;
}
string bruteLongestPalindrome(const string& s) {
    // TC: O(n^3)
    int n = s.size();
    int len = n;
    while(len > 0) {
        int start = 0, end = start+len-1;
        while(end < n) {
            if(isPalindrome(s, start, end))
                return s.substr(start, len);
            start++; end++;
        }
        len--;
    }
    return "";
}

void helper(int left, int right, int& bestStart, int& bestLen, const string& s){
    int n = s.size();
    while(left > -1 && right < n && s[left] == s[right]){
        if(right - left + 1 > bestLen){
            bestStart = left;
            bestLen = right - left + 1;
        }
        left--; right++;
    }
}
string optimalLongestPalindrome(const string& s) {
    // TC: O(n^2)
    // Expand-around-center
    // every string has n odd centers and n-1 even centers
    int bestStart = 0, bestLen = 1;
    int n = s.size();
    for(int i = 0; i < n; i++){
        helper(i, i, bestStart, bestLen, s); // odd check
        helper(i, i+1, bestStart, bestLen, s); // even check
    }
    return s.substr(bestStart, bestLen);
}

int main(){
    string s = "actuallau";
    cout << bruteLongestPalindrome(s) << endl;
    cout << optimalLongestPalindrome(s) << endl;
    return 0;
}
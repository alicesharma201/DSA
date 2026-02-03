#include<bits/stdc++.h>
// #include<cctype>
// isalnum() is alpha + numeric

bool self(const string& phrase){ 
    int n = phrase.length(); 
    for(int i = 0; i < n/2; i++){ 
        if(phrase[i] != phrase[n-1-i]){ 
            return false; 
        } 
    } 
    return true; 
}

bool brute(const string& phrase){
    int n = phrase.length();
    int left = 0;
    int right = n-1;
    while(left < right){
        if(!isalnum(phrase[left])) left++;
        else if(!isalnum(phrase[right])) right--;
        else if(tolower(phrase[left]) != tolower(phrase[right])) return false;
        else{
            left++;
            right--;
        }
    }
    return true;
}

bool optimal(int i, const string& phrase){
    if(i >= phrase.length()/2) return true;
    if(phrase[i] != phrase[phrase.length() - 1 - i]) return false;
    return optimal(i+1, phrase);
}

int main(){
    string phrase;
    getline(cin, phrase); 
    
    cout << self(phrase) << endl;

    cout << brute(phrase) << endl;

    cout << optimal(0, phrase);

    return 0;
}

/* Leetcode
class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0; 
        int end = s.length()-1;
        return helper(s, start, end);
    }
    bool helper(const string& s, int start, int end) {
        if(start >= end) return true;
        else if(!isalnum(s[start])) return helper(s, start+1, end);
        else if(!isalnum(s[end])) return helper(s, start, end-1);
        else if(tolower(s[start]) != tolower(s[end])) return false;
        return helper(s, start+1, end-1);
    }
};
*/
#include<bits/stdc++.h>
int atMostKDistinct(string s, int k){
    // Sliding window
    // TC: O(n)
    // SC: O(1)
    int left = 0;
    unordered_map<char,int> freq;
    int res = 0;
    for(int right = 0; right < s.size(); right++){
        freq[s[right]]++;
        while(freq.size() > k){
            freq[s[left]]--;
            if(freq[s[left]] == 0) freq.erase(s[left]);
            left++;
        }
        res += (right - left + 1);
    }
    return res;
}
int countSubstrings(string s, int k){
    // Exactly k = atMost(k) - atMost(k-1)
    if(k == 0) return 0;
    return atMostKDistinct(s, k) - atMostKDistinct(s, k-1);
}
int main(){
    // string s = "pqpqs"; int k = 2;
    string s = "abcbaa"; int k = 3;
    cout << countSubstrings(s, k) << endl;
    return 0;
}
#include<bits/stdc++.h>
int beautySum(string s) {
    // TC: O(n^2)
    // SC: O(1) because 26 lowercase letters use constant space
    int n = s.size();
    int sum = 0;
    for(int i = 0; i < n; i++){
        unordered_map<char,int> freq;
        for(int j = i; j < n; j++){
            freq[s[j]]++;
            int maxi = INT_MIN, mini = INT_MAX;
            for(auto it : freq){
                maxi = max(maxi, it.second);
                mini = min(mini, it.second);
            }
            sum += (maxi-mini); // beauty
        }
    }
    return sum;
}
int main(){
    // string s = "aabcbaa";
    string s = "yahghsy";
    cout << beautySum(s) << endl;
    return 0;
}
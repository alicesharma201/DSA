#include<bits/stdc++.h>
int maxSize(int hash[], int h){
    int maxIdx = 0;
    for(int i = 1; i < h; i++){
        if(hash[maxIdx] < hash[i]){
            maxIdx = i;
        }
    }
    return maxIdx;
}
vector<char> frequencySort(string s) {
    // TC: O(n)
    // SC: O(1)
    vector<char> res;
    int n = s.size();
    int hash[256] = {0};
    int h = sizeof(hash)/sizeof(hash[0]);
    for(int i = 0; i < n; i++){
        hash[s[i]]++;
    }
    for(int i = 0; i < h; i++){
        int maxi = maxSize(hash, h);
        if(hash[maxi] == 0) break;
        res.push_back((char)maxi);
        hash[maxi] = 0;
    }
    return res;
}
int main(){
    string s = "tree";
    for(char i : frequencySort(s)) cout << i << " ";
    return 0;
}
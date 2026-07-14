#include<bits/stdc++.h>
int romanToInteger(string s){
    unordered_map<char,int> hash = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    int total = 0;
    for(int i = 0; i < s.size(); i++){
        if(i+1 < s.size() && hash[s[i]] < hash[s[i+1]]){
            total += hash[s[i+1]] - hash[s[i]];
            i++;
        }
        else total += hash[s[i]];
    }
    return total;
}
int main(){
    // string s = "LVIII";
    string s = "MCMXCIV";
    cout << romanToInteger(s) << endl;
    return 0;
}
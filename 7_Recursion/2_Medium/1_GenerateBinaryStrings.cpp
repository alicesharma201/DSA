#include<bits/stdc++.h>
using namespace std;
void generateBinary(int n, string curr, vector<string>& result){
    // TC: O(2^n)
    // SC: O(n)
    if(curr.size() == n){
        result.push_back(curr);
        return;
    }
    generateBinary(n, curr+"0", result);
    if(curr.empty() || curr.back() != '1'){
        generateBinary(n, curr+"1", result);
    }
}
int main(){
    // n = 3 {000, 001, 010, 100, 101} excluding {111, 110, 011}
    // n = 2 {00, 01, 10} excluding {11}
    int n = 3;
    vector<string> result;
    generateBinary(n, "", result);
    for(string& s : result){
        cout << s << " ";
    } cout << endl;

    return 0;
}
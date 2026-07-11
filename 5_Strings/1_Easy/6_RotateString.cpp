#include<bits/stdc++.h>
bool bruteRotateString(string s, string goal){
    // TC: O(n^2)
    // SC: O(n)  
    int n = s.size();
    if(n != goal.size()) return false;
    for(int i = 0; i < n; i++){
        string rotated = s.substr(i, n-i) + s.substr(0, i);
        if(rotated == goal) return true;
    }
    return false;
}
bool optimalRotateString(string s, string goal){
    // TC: O(n)
    // SC: O(n)
    int n = s.size();
    if(n != goal.size()) return false;
    string ss = s + s;
    for(int i = 0; i < n; i++){
        if(ss.substr(i, n) == goal) return true;
    }
    return false;
}
int main(){
    string s = "rotation", goal = "tionrota";
    // string s = "hello", goal = "lohelx";
    bruteRotateString(s, goal) ? cout << "True" << endl : cout << "False" << endl;
    optimalRotateString(s, goal) ? cout << "True" << endl : cout << "False" << endl;
    return 0;
}
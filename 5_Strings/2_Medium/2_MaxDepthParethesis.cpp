#include<bits/stdc++.h>
int countDepth(string s){
    // TC: O(n)
    // SC: O(1)
    int maxi = 0, cnt = 0;
    for(int i : s){
        if(i == '(') cnt++;
        else if(i == ')') cnt--;
        maxi = max(maxi, cnt);
    }
    return maxi;
}
int main(){
    string s = "(1+(2*3)+((8)/4))+1";
    cout << countDepth(s) << endl;
    return 0;
}
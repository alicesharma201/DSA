#include<bits/stdc++.h>
string largestOddNum(string num){
    // TC: O(n)
    // SC: O(1)
    int last;
    for(int i = num.size(); i >= 0; i--){
        if((num[i] - '0') % 2 == 1){
            last = i;
            break; 
        }
    }
    int first = 0;
    while(first <= num.size() && num[first] == '0') first++;
    return num.substr(first, last-first+1);
}
int main(){
    string num = "0214638";
    cout << largestOddNum(num) << endl;
    return 0;
}
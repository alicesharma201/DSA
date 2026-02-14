/*
For lowercase:
    arr[26]
    char - 'a'
For uppercase:
    arr[26]
    char - 'A'
For every ascii character:
    arr[256]
    Always use arrays for characters cuz there are only 256 chars
    you won't need to subtract anything
*/

#include<bits/stdc++.h>
int main(){
    string s;
    cout << "Enter string: ";
    cin >> s;

    int hash[26] = {0};
    for(int i = 0; i < s.size(); i++){
        hash[s[i] - 'a'] += 1;
    }

    int q;
    cout << "Enter number of queries: ";
    cin >> q;
    cout << "Enter queries: ";
    while(q--){
        char ch;
        cin >> ch;
        cout << ch << " : " << hash[ch - 'a'] << endl;
    }
    return 0;
}
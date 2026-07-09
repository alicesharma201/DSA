#include<bits/stdc++.h>
string bruteReverseWords(string s){
    // TC: O(3n) = O(n)
    // SC: O(n)
    int n = s.size();
    vector<string> words;
    for(int i = 0; i < n; i++){
        string word = "";
        if(s[i] == ' ') continue; 
        while(i < n && s[i] != ' '){
            word += s[i];
            i++;
        }
        words.push_back(word);
    }
    reverse(words.begin(), words.end());
    string output;
    for(int i = 0; i < words.size(); i++){
        output += words[i];
        if(i != words.size()-1) output += ' ';
    }
    return output;
}
string optimalReverseWords(string s){
    // TC: O(n)
    // SC: O(n)
    string result = "";
    int i = s.size() - 1;
    while (i >= 0) {
        while (i >= 0 && s[i] == ' ') i--;
        if (i < 0) break; // when there are no longer any words left

        int end = i; // marking the end of the word
        while (i >= 0 && s[i] != ' ')  i--; // find beginning of word

        string word = s.substr(i + 1, end - i); // extract the word, parameters: start of the word, length of the word
        
        if (!result.empty()) result += " ";
        result += word;
    }
    return result;
}
int main(){
    string s = " the quick    brown fox  ";
    cout << bruteReverseWords(s) << endl;
    cout << optimalReverseWords(s) << endl;
    return 0;
}
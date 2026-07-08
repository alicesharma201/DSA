#include<bits/stdc++.h>
string removeOuterParentheses(string s){
    // TC: O(n)
    // think of the outer parentheses as lunchboxes and the inner ones as sandwiches, you want to preserve the sandwiches inside and discard the lunch box
    string output = "";
    int depth = 0;
    for(char c : s){
        if(c == '('){
            depth++;
            if(depth > 1) output.push_back(c);
        }else{
            depth--;
            if(depth > 0) output.push_back(c);
        }
    }
    return output;
}
int main(){
    string s = "()(()())(())"; // ()()()
    cout << removeOuterParentheses(s) << endl;
    return 0;
}
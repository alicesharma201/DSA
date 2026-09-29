#include<bits/stdc++.h>
using namespace std;
string prefixToPostfix(string& prefix){
    // TC: O(n)
    // SC: O(n)
    unordered_set<char> operators = {'+', '-', '*', '/', '^'};
    stack<string> stk;
    for(int i = prefix.size()-1; i >= 0; i--){
        if(operators.find(prefix[i]) != operators.end()){
            string first = stk.top(); stk.pop();
            string second = stk.top(); stk.pop();
            stk.push(first + second + string(1, prefix[i]));
        }else{
            stk.push(string(1, prefix[i]));
        }
    }
    string postfix = stk.top();
    return postfix;
}
int main(){
    string prefix = "*+ab-cd";
    cout << prefixToPostfix(prefix) << endl;
    return 0;
}
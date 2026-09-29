#include<bits/stdc++.h>
using namespace std;
string postfixToPrefix(string& postfix){
    // TC: O(n)
    // SC: O(n)
    unordered_set<char> operators = {'+', '-', '*', '/', '^'};
    stack<string> stk;
    for(char i : postfix){
        if(operators.find(i) != operators.end()){
            string first = stk.top(); stk.pop();
            string second = stk.top(); stk.pop();
            stk.push(string(1, i) + second + first);
        }else{
            stk.push(string(1, i));
        }
    }
    string prefix = stk.top();
    return prefix;
}
int main(){
    string postfix = "abc*+d-";
    cout << postfixToPrefix(postfix) << endl;
    return 0;
}
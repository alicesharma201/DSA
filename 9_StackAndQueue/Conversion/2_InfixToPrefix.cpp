#include<bits/stdc++.h>
using namespace std;
string infixToPrefix(string exp){
    // TC: O(n)
    // SC: O(n)

    unordered_map<char,int> precedence = {
        {'^', 3},
        {'*', 2},
        {'/', 2},
        {'+', 1},
        {'-', 1}
    };

    reverse(exp.begin(), exp.end());

    for(int i = 0; i < exp.size(); i++){
        if(exp[i] == '(') exp[i] = ')';
        else if(exp[i] == ')') exp[i] = '(';
    }

    stack<char> stk;
    string reversePostfix = "";
    for(char i : exp){
        if(i == '(') stk.push(i);
        else if(i == ')'){
            while(!stk.empty() && stk.top() != '('){
                reversePostfix += stk.top();
                stk.pop();
            }
            stk.pop();
        }
        else if(precedence.find(i) == precedence.end()){
            reversePostfix += i;
        }
        else{
            if(i == '^'){
                while(!stk.empty() && stk.top() != '(' && precedence[i] <= precedence[stk.top()]){
                    reversePostfix += stk.top();
                    stk.pop();
                }
            }else{
                while(!stk.empty() && stk.top() != '(' && precedence[i] < precedence[stk.top()]){
                    reversePostfix += stk.top();
                    stk.pop();
                }
            }
            stk.push(i);
        }
    }

    while(!stk.empty()){
        reversePostfix += stk.top();
        stk.pop();
    }

    reverse(reversePostfix.begin(), reversePostfix.end());
    string prefix = reversePostfix;

    return prefix;
}
int main(){
    string exp = "(A+B)*C-D+F";
    cout << infixToPrefix(exp) << endl;
    return 0;
}
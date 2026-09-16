#include<bits/stdc++.h>
using namespace std;
string infixToPostfix(string& infix){
    // TC: O(n)
    // SC: O(n)
    string postfix = "";
    unordered_map<char, int> precedence = {
        {'^', 3},
        {'*', 2},
        {'/', 2},
        {'+', 1},
        {'-', 1}
    };
    stack<char> stk;
    for(char i : infix){
        if(i == ' ') continue;
        else if(i == '('){
            stk.push(i);
        }
        else if(i == ')'){
            while(!stk.empty() && stk.top() != '('){
                postfix += stk.top();
                stk.pop();
            }
            stk.pop();
        }
        else if(precedence.find(i) == precedence.end()){ // operand
            postfix.push_back(i);
        }
        else{ 
            // I found an operator. Before putting it on the stack, get rid of every operator already on the stack that should happen before me.
            while(!stk.empty() && precedence[i] <= precedence[stk.top()]){
                postfix += stk.top();
                stk.pop();
            }
            stk.push(i);
        }
    }
    while(!stk.empty()){
        postfix.push_back(stk.top());
        stk.pop();
    }
    return postfix;
}
int main(){
    string infix = "a + b * (c^d - e) ^ (f + g * h) - i";
    cout << infixToPostfix(infix) << endl;
    return 0;
}
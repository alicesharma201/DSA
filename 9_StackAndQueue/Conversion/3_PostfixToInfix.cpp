#include<bits/stdc++.h>
using namespace std;
string postfixToInfix(string exp){
    // TC: O(n)
    // SC: O(n)
    stack<string> stk;
    unordered_set<char> operators = {'^', '*', '/', '+', '-'};
    for(auto c : exp){
        if(operators.find(c) != operators.end()){
            string second = stk.top(); stk.pop();
            string first = stk.top(); stk.pop();
            string s = "(" + first + string(1, c) + second + ")";
            stk.push(s);
        }
        else{
            string s = string(1,c);
            stk.push(s);
        }
    }
    return stk.top();
}
int main(){
    // Whenever we observe an operotor, pop the last two elements and insert the operator between the elements
    string exp = "AB-DE+F*/";
    cout << postfixToInfix(exp) << endl;
    return 0;
}
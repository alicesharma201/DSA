#include<bits/stdc++.h>
using namespace std;
string prefixToInfix(string exp){
    // TC: O(n)
    // SC: O(n)
    stack<string> stk;
    unordered_set<char> operators = {'^', '*', '/', '+', '-'};
    for(int i = exp.size()-1; i >= 0; i--){
        if(operators.find(exp[i]) != operators.end()){
            string first = stk.top(); stk.pop();
            string second = stk.top(); stk.pop();
            string s = "(" + first + string(1,exp[i]) + second + ")";
            stk.push(s);
        }
        else{
            stk.push(string(1,exp[i]));
        }
    }
    
    return stk.top();
}
int main(){
    // right to left traversal
    string exp = "*+ab-cd";
    cout << prefixToInfix(exp) << endl;
    return 0;
}
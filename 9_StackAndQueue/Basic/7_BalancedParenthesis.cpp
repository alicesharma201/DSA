#include<bits/stdc++.h>
using namespace std;
bool isValid(string s) {
    // TC: O(n)
    // SC: O(n) stack space

    // Steps:
    // - when we get a open bracket, push it
    // - check if stack is still empty, if it is, then there was a closing bracket, we cannot push a closing bracket before an open one, so return false
    // - check if the top is the opening bracket and i is its pair closing bracket, so pop that open bracket
    // - otherwise return false
    // - once the loop is over, if stack is emtpy, return true, else false

    stack<char> st;
    for(char i : s){
        if(i == '(' || i == '[' || i == '{') st.push(i);
        else if(st.empty()) return false;
        else if(st.top() == '(' && i == ')') st.pop();
        else if(st.top() == '[' && i == ']') st.pop();
        else if(st.top() == '{' && i == '}') st.pop();
        else return false;
    }
    return st.empty();
}
int main(){
    cout << boolalpha << isValid("()") << endl;
    cout << boolalpha << isValid("()[]{}") << endl;
    cout << boolalpha << isValid("(]") << endl;
    cout << boolalpha << isValid("([)]") << endl;
    cout << boolalpha << isValid("(") << endl;
    cout << boolalpha << isValid("]") << endl;
    return 0;
}
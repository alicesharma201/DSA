#include<bits/stdc++.h>
using namespace std;
void insertBottom(stack<int>& s, int temp){
    if(s.empty()){
        s.push(temp);
        return;
    }
    int val = s.top();
    s.pop();
    insertBottom(s, temp);
    s.push(val);
}
void reverseStack(stack<int>& s){
    if(s.empty()) return;
    int temp = s.top();
    s.pop();
    reverseStack(s);
    insertBottom(s, temp);
}
int main(){
    stack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);

    cout << "Before: ";
    while(!stk.empty()){
        cout << stk.top() << " ";
        stk.pop();
    }

    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    reverseStack(stk);

    cout << "\nAfter: ";
    while(!stk.empty()){
        cout << stk.top() << " ";
        stk.pop();
    }
    return 0;
}
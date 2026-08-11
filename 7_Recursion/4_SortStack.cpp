#include<bits/stdc++.h>
using namespace std;
void insertVal(stack<int>& s, int temp){
    if(s.empty() || s.top() <= temp){
        s.push(temp);
        return;
    }
    int val = s.top();
    s.pop();
    insertVal(s, temp);
    s.push(val);
}
void sortStack(stack<int>& s){
    if(!s.empty()){
        int temp = s.top();
        s.pop();
        sortStack(s);
        insertVal(s, temp);
    }
}
int main(){
    stack<int> stk;
    stk.push(4);
    stk.push(1);
    stk.push(3);
    stk.push(2);
    sortStack(stk);
    while(!stk.empty()){ // it prints in descending order
        cout << stk.top() << " ";
        stk.pop();
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
void printStack1(stack<pair<int,int>> ms){
    while(!ms.empty()){
        cout << ms.top().first << ' ';
        ms.pop();
    }
    cout << '\n';
}
void printStack2(stack<int> ms){
    while(!ms.empty()){
        cout << ms.top() << ' ';
        ms.pop();
    }
    cout << '\n';
}
class MinStack1{
public:
    // TC: O(1)
    // SC: O(2N)
    stack<pair<int,int>> ms; 
    void push(int value){
        if(ms.empty()) ms.push({value, value});
        else ms.push({value, min(value, ms.top().second)});
    }
    void pop(){
        ms.pop();
    }
    int top(){
        return ms.top().first;
    }
    int getMin(){
        return ms.top().second;
    }
    void print(){
        printStack1(ms);
    }
};
class MinStack2{
public:
    // TC: O(1)
    // SC: O(n)
    stack<int> ms; // use long long on LC
    int mini = INT_MAX; // okay for smaller inputs, otherwise use LLONG_MAX on LC
    void push(int value){
        if(ms.empty()){
            mini = value;
            ms.push(value);
        }else if(mini > value){
            ms.push(2*value - mini); // newVal = 2*value - prevMini
            mini = value; // here, mini is the top value
        }else ms.push(value);
    }
    void pop(){
        if(ms.empty()) return;
        if(mini > ms.top()){
            mini = 2*mini - ms.top(); // prevMini = 2*value - newVal
        }
        ms.pop();
    }
    int top(){
        if(mini > ms.top()) return mini;
        return ms.top();
    }
    int getMin(){
        return mini;
    }
    void print(){
        printStack2(ms);
    }
};
int main(){
    // MinStack1 a;
    MinStack2 a;
    a.push(5);
    a.push(8);
    cout << "top: " << a.top() << endl;
    cout << "min: " << a.getMin() << endl;
    a.push(3);
    a.print();
    cout << "top: " << a.top() << endl;
    cout << "min: " << a.getMin() << endl;
    a.pop();
    a.print();
    cout << "min: " << a.getMin() << endl;
    a.push(10);
    a.print();
    cout << "min: " << a.getMin() << endl;
    return 0;
}
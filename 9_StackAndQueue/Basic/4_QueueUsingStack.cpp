#include<bits/stdc++.h>
using namespace std;
void printStack(stack<int> s) {
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\n";
}
class MyQueue1{ // TC: O(2n) for push
public:
    stack<int> s1;
    stack<int> s2;
    void push(int x){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        if(s1.empty()) s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    int pop(){
        int val = s1.top();
        s1.pop();
        return val;
    }
    int peek(){
        return s1.top();
    }
    bool empty(){
        return s1.empty();
    }
    void print(){
        printStack(s1);
    }
};
class MyQueue2{ // TC: O(1) for push
public:
    stack<int> s1;
    stack<int> s2;
    void push(int x){
        s1.push(x);
    }
    int pop(){
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int val = s2.top();
        s2.pop();
        return val;
    }
    int peek(){
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    bool empty(){
        return s2.empty() && s1.empty();
    }
    void print(){
        if(s2.empty()){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
    }
        printStack(s2);
    }
};
int main(){
    // MyQueue1 a;
    MyQueue2 a;
    a.push(5);
    a.push(6);
    a.push(7);
    a.print();
    cout << a.pop() << endl;
    cout << a.peek() << endl;
    return 0;
}

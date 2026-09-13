#include<bits/stdc++.h>
using namespace std;
void printQueue(queue<int> q) {
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n";
}
class MyStack{
    queue<int> q;
    public:
    void push(int x){ // O(n)
        int s = q.size();
        q.push(x);
        for(int i = 0; i < s; i++){
            q.push(q.front());
            q.pop();
        }
    }
    int pop(){ // O(1)
        if(q.empty()) return -1;
        int val = q.front();
        q.pop();
        return val;
    }
    int top(){ // O(1)
        if(q.empty()) return -1;
        return q.front();
    }
    bool isEmpty(){ // O(1)
        return q.empty();
    }
    void print(){
        printQueue(q);
    }
};
int main(){
    MyStack a;
    cout << boolalpha << a.isEmpty() << endl;
    a.push(1);
    a.push(2);
    a.push(3);
    a.print();
    a.push(4);
    a.print();
    cout << a.pop() << endl;
    cout << a.top() << endl;
    a.print();

    return 0;
}
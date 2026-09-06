#include<bits/stdc++.h>
using namespace std;
class ArrayStack{
    int top = -1;
    static const int capacity = 10;
    int arr[capacity];
public:
    void push(int num){
        if(top == capacity-1) cout << "Stack is full\n";
        else arr[++top] = num;
    }
    int pop(){
        if(top == -1){
            cout << "Nothing to pop\n";
            return -1;
        }
        return arr[top--];
    }
    int peek(){
        if(top == -1){
            cout << "Nothing to peek\n";
            return -1;
        }
        return arr[top];
    }
    int size(){
        return top + 1;
    }
    bool isEmpty(){
        return top == -1;
    }
    void print(){
        if(top == -1){
            cout << "Nothing to print\n";
            return;
        }
        for(int i = 0; i <= top; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main(){
    ArrayStack a;
    a.push(5);
    a.push(7);
    a.push(9);
    a.print();
    cout << a.peek() << endl;
    cout << a.size() << endl;
    cout << a.pop() << endl;
    cout << a.peek() << endl;
    a.print();
    
    return 0;
}
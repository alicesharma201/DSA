#include<bits/stdc++.h>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class LLStack{
    ListNode* top = nullptr;
    int cnt = 0;
    public:
    void push(int num){
        ListNode* node = new ListNode(num, top);
        top = node;
        cnt++;
    }
    int pop(){
        if(top == nullptr){
            cout << "No nodes left\n";
            return -1;
        }
        ListNode* temp = top;
        top = top->next;
        cnt--;
        int val = temp->val;
        delete temp;
        return val;
    }
    void print(){
        for(ListNode* temp = top; temp != nullptr; temp = temp->next){
            cout << temp->val << " ";
        }
        cout << endl;
    }
    int peek(){
        return top != nullptr ? top->val : -1;
    }
    int size(){
        return cnt;
    }
    bool isEmpty(){
        return top == nullptr;
    }
    ~LLStack(){ // destructor
        while(top != nullptr){
            ListNode* temp = top;
            top = top->next;
            delete temp;
        }
    }
};
int main(){
    LLStack l;
    l.push(5);
    l.push(6);
    l.push(7);
    l.print();
    cout << l.pop() << " is popped" << endl;
    l.print();
    cout << "empty: " << boolalpha << l.isEmpty() << endl;
    cout << "top: " << l.peek() << endl;
    cout << "size: " << l.size() << endl;
    l.push(8);
    l.print();
    cout << "size: " << l.size() << endl;

    return 0;
}
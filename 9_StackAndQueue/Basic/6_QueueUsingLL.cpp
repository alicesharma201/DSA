#include<bits/stdc++.h>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class LLQueue{
    ListNode* start = nullptr;
    ListNode* end = nullptr;
    int cnt = 0;
    public:
    void enqueue(int num){
        ListNode* node = new ListNode(num);
        if(end) end->next = node;
        if(cnt == 0) start = node;
        end = node;
        cnt++;
    }
    int dequeue(){
        if(cnt == 0){
            cout << "Nothing to dequeue\n";
            return -1;
        }
        ListNode* toDelete = start;
        start = start->next;
        int val = toDelete->val;
        delete toDelete;
        cnt--;
        if(start == nullptr) end = nullptr;
        return val;
    }
    int size(){
        return cnt;
    }
    bool isEmpty(){
        return cnt == 0;
    }
    void print(){
        for(ListNode* temp = start; temp != nullptr; temp = temp->next){
            cout << temp->val << " ";
        }
        cout << endl;
    }
};
int main(){
    LLQueue q;
    cout << q.dequeue() << endl;
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.print();
    cout << q.dequeue() << endl;
    cout << "Size: " << q.size() << endl;
    cout << "Empty: " << boolalpha << q.isEmpty() << endl;
    q.print(); 
    return 0;
}
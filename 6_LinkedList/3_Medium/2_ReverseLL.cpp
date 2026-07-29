#include<bits/stdc++.h>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
void print(ListNode* head){
    for(ListNode* temp = head; temp != nullptr; temp = temp->next){
        cout << temp->val << " ";
    }
    cout << endl;
}
ListNode* bruteReverseLL(ListNode* head){
    // TC: O(2n)
    // SC: O(n)
    if(head == nullptr || head->next == nullptr) return head;
    ListNode* temp = head;
    stack<int> st;
    while(temp){
        st.push(temp->val);
        temp = temp->next;
    }
    temp = head;
    while(temp){
        temp->val = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}
ListNode* optimalReverseLL(ListNode* head){
    // TC: O(n)
    // SC: O(1)
    if(head == nullptr || head->next == nullptr) return head;
    ListNode* temp = head;
    ListNode* prev = nullptr;
    while(temp){
        ListNode* ahead = temp->next;
        temp->next = prev;
        prev = temp;
        temp = ahead;
    }
    return prev;
}
ListNode* recursiveReverseLL(ListNode* head){
    // TC: O(n)
    // SC: O(n)
    if(head == nullptr || head->next == nullptr) return head;
    ListNode* newHead = recursiveReverseLL(head->next);
    ListNode* front = head->next;
    front->next = head;
    head->next = nullptr;
    return newHead;
}
int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    
    // head = bruteReverseLL(head);
    // head = optimalReverseLL(head);
    head = recursiveReverseLL(head);
    print(head);

    return 0;
}
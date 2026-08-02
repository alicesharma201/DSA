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
ListNode* bruteDeleteMiddle(ListNode* head){
    // TC: O(n + n/2)
    // SC: O(1)
    if(head == nullptr || head->next == nullptr) return nullptr;
    ListNode* temp = head;
    int cnt = 0;
    while(temp){
        cnt++;
        temp = temp->next;
    }
    int mid = cnt/2;
    temp = head;
    while(--mid){ // stand one node behind the node to delete
        temp = temp->next;
    }
    ListNode* toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;

    return head;
}
ListNode* optimalDeleteMiddle(ListNode* head){
    // TC: O(n/2)
    // SC: O(1)
    if(head == nullptr || head->next == nullptr) return nullptr;
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = nullptr;
    while(fast && fast->next){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = slow->next;
    delete slow;

    return head;
}
int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    // head = bruteDeleteMiddle(head);
    head = optimalDeleteMiddle(head);
    print(head);

    return 0;
}
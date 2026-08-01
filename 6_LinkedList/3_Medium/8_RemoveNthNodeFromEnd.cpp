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
ListNode* bruteRemove(ListNode* head, int n){
    // TC: O(L + L-N) where L is length of LL, worst O(2L)
    // SC: O(1)
    if(head == nullptr) return nullptr;
    ListNode* temp = head;
    int cnt = 0;
    while(temp){
        cnt++;
        temp = temp->next;
    }
    int x = cnt - n + 1;
    temp = head;
    if(x == 1){
        ListNode* ahead = temp->next;
        delete temp;
        return ahead;
    }
    ListNode* prev = nullptr;
    while(--x){
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    delete temp;
    return head;
}
ListNode* optimalRemove(ListNode* head, int n){
    // TC: O(L) where L is the length of the LL
    // SC: O(1)
    if(head == nullptr) return nullptr;
    ListNode* fast = head;
    ListNode* slow = head;
    for(int i = 0; i < n; i++){
        fast = fast->next;
    }
    if(fast == nullptr){
        ListNode* ahead = head->next;
        delete head;
        return ahead;
    }
    while(fast->next){
        fast = fast->next;
        slow = slow->next;
    }
    ListNode* toDelete = slow->next;
    slow->next = toDelete->next;
    delete toDelete;
    return head;
}
int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    int n = 4;
    
    // head = bruteRemove(head, n);
    head = optimalRemove(head, n);
    print(head);

    return 0;
}
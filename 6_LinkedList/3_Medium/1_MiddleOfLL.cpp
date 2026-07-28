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
ListNode* bruteMiddle(ListNode* head){
    // TC: O(n + (n/2))
    // SC: O(1)
    int cnt = 0;
    ListNode* temp = head;
    while(temp){
        cnt++;
        temp = temp->next;
    }
    int mid = cnt/2;
    temp = head;
    while(mid--){
        temp = temp->next;
    }
    return temp;
}
ListNode* optimalMiddle(ListNode* head){
    // TC: O(n)
    // SC: O(1)
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
int main(){
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(5);
    head->next->next->next = new ListNode(1);

    // head = bruteMiddle(head);
    head = optimalMiddle(head);
    print(head);

    return 0;
}
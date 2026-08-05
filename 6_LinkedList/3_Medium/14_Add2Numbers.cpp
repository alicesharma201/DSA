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
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    // TC: O(max(l1, l2))
    // SC: O(1) except output list
    ListNode* dummy = new ListNode(-1);
    ListNode* temp = dummy;
    int carry = 0;
    while(carry || l1 || l2){
        int sum = carry;
        if(l1){
            sum += l1->val;
            l1 = l1->next;
        }
        if(l2){
            sum += l2->val;
            l2 = l2->next;
        }
        carry = sum / 10;
        temp->next = new ListNode(sum % 10);
        temp = temp->next;
    }
    return dummy->next;
}
int main(){
    ListNode* l1 = new ListNode(9);
    l1->next = new ListNode(9);
    l1->next->next = new ListNode(9);
    l1->next->next->next = new ListNode(9);

    ListNode* l2 = new ListNode(8);
    l2->next = new ListNode(7);

    ListNode* head = addTwoNumbers(l1, l2);
    print(head); // the total sum is reversed

    return 0;
}
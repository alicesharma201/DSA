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
ListNode* bruteSort012(ListNode* head){
    // TC: O(2n)
    // SC: O(1)
    ListNode* temp = head;
    int zero = 0, one = 0, two = 0;
    while(temp){
        if(temp->val == 0) zero++;
        else if(temp->val == 1) one++;
        else if(temp->val == 2) two++;
        temp = temp->next;
    }
    temp = head;
    while(temp){
        if(zero-- > 0) temp->val = 0;
        else if(one-- > 0) temp->val = 1;
        else if(two-- > 0) temp->val = 2;
        temp = temp->next;
    }
    return head;
}
ListNode* optimalSort012(ListNode* head){
    // TC: O(n)
    // SC: O(1)
    if(head == nullptr || head->next == nullptr) return head;
    ListNode* zeroHead = new ListNode(-1), *zero = zeroHead;
    ListNode* oneHead = new ListNode(-1), *one = oneHead;
    ListNode* twoHead = new ListNode(-1), *two = twoHead;
    ListNode* temp = head;
    while(temp){
        if(temp->val == 0){
            zero->next = temp;
            zero = temp;
        }else if(temp->val == 1){
            one->next = temp;
            one = temp;
        }else if(temp->val == 2){
            two->next = temp;
            two = temp;
        }
        temp = temp->next;
    }
    zero->next = oneHead->next ? oneHead->next : twoHead->next;
    one->next = twoHead->next;
    two->next = nullptr;
    ListNode* newHead = zeroHead->next;
    delete zeroHead; delete oneHead; delete twoHead;
    return newHead;
}
int main(){
    ListNode* head = new ListNode(2);
    head->next = new ListNode(1);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(0);
    head->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next = new ListNode(0);
    head->next->next->next->next->next->next = new ListNode(1);

    // head = bruteSort012(head);
    head = optimalSort012(head);
    print(head);

    return 0;
}
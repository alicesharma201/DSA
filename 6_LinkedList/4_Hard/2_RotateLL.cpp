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
// brute: attach the last node to the first node k times
    // TC: O(n*k)
    // SC: O(1)
ListNode* rotateRight(ListNode* head, int k){
    // Turn it into a circular ll and then break it at lenght-k
    // TC: O(n)
    // SC: O(1)
    if(head == nullptr || head->next == nullptr || k == 0) return head;
    ListNode* temp = head;
    int len = 1;
    while(temp->next){
        len++;
        temp = temp->next;
    }
    k %= len;
    if(k == 0) return head;
    int position = len - k;
    temp->next = head;
    while(position--){
        temp = temp->next;
    }
    ListNode* newhead = temp->next;
    temp->next = nullptr;
    return newhead;
}
int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    head = rotateRight(head, 3);
    print(head);

    return 0;
}
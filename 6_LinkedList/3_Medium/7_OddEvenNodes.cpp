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
ListNode* bruteSegregate(ListNode* head){
    // TC: O(n/2 + n/2 + n) = O(2n) = O(n)
    // SC: O(n)
    if(head == nullptr || head->next == nullptr) return head;
    vector<int> vals;
    ListNode* temp = head;
    while(temp && temp->next){
        vals.push_back(temp->val);
        temp = temp->next->next;
    }
    if(temp) vals.push_back(temp->val); // We do this because of the while (temp && temp->next) condition. In case when temp is actually at a valid value but temp->next is nullptr, the while loop will end without pushing the last node inside the vector. So we do a check outside that if temp actually exists, we will push it into our vector
    temp = head->next;
    while(temp && temp->next){
        vals.push_back(temp->val);
        temp = temp->next->next;
    }
    if(temp) vals.push_back(temp->val); // similarly for even
    temp = head;
    for(int i : vals){
        temp->val = i;
        temp = temp->next;
    }
    return head;
}
ListNode* optimalSegregate(ListNode* head){
    // TC: O(n)
    // SC: O(1)
    if(head == nullptr || head->next == nullptr) return head;
    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* evenHead = head->next;
    while(even && even->next){
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}
int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // head = bruteSegregate(head);
    head = optimalSegregate(head);
    print(head);

    return 0;
}
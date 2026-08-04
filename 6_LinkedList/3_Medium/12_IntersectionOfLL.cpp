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
ListNode* bruteIntersection(ListNode* head1, ListNode* head2){
    // TC: O(n*m)
    // SC: O(1)
    for(ListNode* temp1 = head1; temp1 != nullptr; temp1 = temp1->next){
        for(ListNode* temp2 = head2; temp2 != nullptr; temp2 = temp2->next){
            if(temp1 == temp2) return temp1;
        }
    }
    return nullptr;
}
ListNode* betterIntersection(ListNode* head1, ListNode* head2){
    // TC: O(n+m)
    // SC: O(n)
    unordered_set<ListNode*> st;
    while(head1){
        st.insert(head1);
        head1 = head1->next;
    }
    while(head2){
        if(st.find(head2) != st.end()) return head2;
        head2 = head2->next;
    }
    return nullptr;
}
ListNode* optimalIntersection1(ListNode* head1, ListNode* head2){
    // TC: O(n+(n-m)+m) = O(2n) where n > m
    // SC: O(1)
    ListNode* temp1 = head1;
    ListNode* temp2 = head2;
    int len1 = 0, len2 = 0;
    while(temp1 || temp2){ // O(n)
        if(temp1){
            len1++;
            temp1 = temp1->next;
        }
        if(temp2){
            len2++;
            temp2 = temp2->next;
        }
    }
    temp1 = head1;
    temp2 = head2;
    if(len1 > len2){ 
        int diff = len1-len2;
        while(diff--) temp1 = temp1->next; // O(n-m)
    }
    else{
        int diff = len2-len1;
        while(diff--) temp2 = temp2->next;
    } 
    while(temp1){ // O(m)
        if(temp1 == temp2) return temp1;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return nullptr;
}
ListNode* optimalIntersection2(ListNode* head1, ListNode* head2){
    // TC: O(n+m)
    // SC: O(1)
    ListNode* temp1 = head1;
    ListNode* temp2 = head2;
    while(temp1 != temp2){
        temp1 = (temp1 == nullptr) ? head2 : temp1->next;
        temp2 = (temp2 == nullptr) ? head1 : temp2->next;
    }
    return temp1;
}
int main(){
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);
    ListNode* head2 = new ListNode(9);
    head2->next = new ListNode(8);
    head2->next->next = head1->next->next->next;

    print(head1);
    print(head2);

    // ListNode* intersection = bruteIntersection(head1, head2);
    // ListNode* intersection = betterIntersection(head1, head2);
    // ListNode* intersection = optimalIntersection1(head1, head2);
    ListNode* intersection = optimalIntersection2(head1, head2);
    print(intersection);

    return 0;
}
#include<bits/stdc++.h>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode* child;
    ListNode(int x) : val(x), next(nullptr), child(nullptr) {}
    ListNode(int x, ListNode* next, ListNode* child) : val(x), next(next), child(child) {}
};

void printNext(ListNode* head){
    for(ListNode* temp = head; temp != nullptr; temp = temp->next){
        cout << temp->val << " ";
    }
    cout << endl;
}
ListNode* findMiddle(ListNode* head){
    if(head == nullptr || head->next == nullptr) return head;
    ListNode* slow = head;
    ListNode* fast = head->next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
ListNode* mergeNextLL(ListNode* l, ListNode* r){
    ListNode* dummy = new ListNode(-1);
    ListNode* temp = dummy;
    ListNode* l1 = l; ListNode* l2 = r;
    while(l1 && l2){
        if(l1->val <= l2->val){
            temp->next = l1;
            l1 = l1->next;
        }else{
            temp->next = l2;
            l2 = l2->next;
        }
        temp = temp->next;
    }
    if(l1) temp->next = l1;
    else temp->next = l2;
    return dummy->next;
}
ListNode* sortLL(ListNode* head){
    if(head == nullptr || head->next == nullptr) return head;
    ListNode* middle = findMiddle(head);
    ListNode* l = head;
    ListNode* r = middle->next;
    middle->next = nullptr;
    l = sortLL(l);
    r = sortLL(r);
    return mergeNextLL(l,r);
}
ListNode* selfFlatten(ListNode* head){ // Assuming that child nodes aren't sorted
    // N : total number of nodes
    // TC: O(N + NlogN) = O(NlogN)
    // SC: O(logN)
    ListNode* temp = head;
    while(temp){
        ListNode* nextNode = temp->next;
        temp->next = temp->child;
        while(temp->child){
            temp->next = temp->child;
            temp = temp->child;
        }
        temp->next = nextNode;
        temp = nextNode;
    }
    head = sortLL(head);
    return head;
}

void printChild(ListNode* head){
    ListNode* temp = head;
    while(temp){
        cout << temp->val << " ";
        temp = temp->child;
    }
    cout << '\n';
}
ListNode* convert(vector<int>& store){
    int n = store.size();
    if(n == 0) return nullptr;
    ListNode* head = new ListNode(store[0]);
    ListNode* temp = head;
    for(int i = 1; i < n; i++){
        ListNode* newNode = new ListNode(store[i]);
        temp->child = newNode;
        temp = temp->child;
    }
    return head;
}
ListNode* bruteFlatten(ListNode* head){
    // N = total no. of nodes
    // TC: O(N + N(logN) + N) = O(NlogN)
    // SC: O(N + N) = O(N)
    vector<int> store;
    ListNode* temp = head;
    while(temp){
        ListNode* t = temp;
        while(t){
            store.push_back(t->val);
            t = t->child;
        }
        temp = temp->next;
    }
    sort(store.begin(), store.end());
    head = convert(store);
    return head;
}

ListNode* mergeChildLL(ListNode* l1, ListNode* l2){
    ListNode* dummy = new ListNode(-1);
    ListNode* temp = dummy;
    while(l1 && l2){
        if(l1->val <= l2->val){
            temp->child = l1;
            l1 = l1->child;
        }else{
            temp->child = l2;
            l2 = l2->child;
        }
        temp = temp->child;
        temp->next = nullptr;
    }
    if(l1) temp->child = l1;
    else temp->child = l2;
    return dummy->child;
}
ListNode* optimalFlatten(ListNode* head){
    // The linkedlist is vertically sorted (child nodes are sorted)
    // here n = width and m = height of linkedlist
    // TC: O(n * (2m + 3m +...+ nm)) = O(m * n^2)
    // SC: O(n) recursive stack space
    if(head == nullptr || head->next == nullptr) return head;
    ListNode* mergedHead = optimalFlatten(head->next);
    return mergeChildLL(mergedHead, head);
}

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(3);
    head->next->child = new ListNode(4);
    head->next->child->child = new ListNode(9);
    head->next->next = new ListNode(2);
    head->next->next->child = new ListNode(5);
    head->next->next->child->child = new ListNode(7);
    head->next->next->child->child->child = new ListNode(12);
    head->next->next->next = new ListNode(6);
    head->next->next->next->child = new ListNode(8);
    head->next->next->next->child->child = new ListNode(10);

    // head = selfFlatten(head);
    // printNext(head);

    // head = bruteFlatten(head);
    head = optimalFlatten(head);
    printChild(head); // we will have to return a vertically flattened linkedlist

    return 0;
}
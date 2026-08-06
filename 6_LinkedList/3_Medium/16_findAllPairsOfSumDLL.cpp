#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node* back;
    Node(int data1) : data(data1), next(nullptr), back(nullptr) {}
    Node(int data1, Node* next1, Node* back1) : data(data1), next(next1), back(back1) {}
};
vector<vector<int>> bruteFindPairs(Node* head, int k){
    // TC: near about O(n^2)
    // SC: O(1)
    vector<vector<int>> output;
    for(Node* temp1 = head; temp1->next; temp1 = temp1->next){
        for(Node* temp2 = temp1->next; temp2; temp2 = temp2->next){
            if(temp1->data + temp2->data == k) output.push_back({temp1->data, temp2->data});
            if(temp1->data + temp2->data > k) break;
        }
    }
    return output;
}
vector<vector<int>> optimalFindPairs(Node* head, int k){
    // TC: O(2n) = O(n)
    // SC: O(1)
    vector<vector<int>> output;
    Node* low = head;
    Node* high = head;
    while(high->next) high = high->next;
    while(low != high && low->back != high){
        int sum = low->data + high->data;
        if(sum < k) low = low->next;
        else if(sum > k) high = high->back;
        else{
            output.push_back({low->data, high->data});
            low = low->next;
            high = high->back;
        }
    }
    return output;
}
int main(){
    Node* head = new Node(1);
    head->next = new Node(2, nullptr, head);
    head->next->next = new Node(3, nullptr, head->next);
    head->next->next->next = new Node(4, nullptr, head->next->next);
    head->next->next->next->next = new Node(5, nullptr, head->next->next->next);

    // vector<vector<int>> res = bruteFindPairs(head, 5);
    vector<vector<int>> res = optimalFindPairs(head, 5);
    for(auto i : res){
        cout << "{" << i[0] << "," << i[1] << "}" << endl;
    }

    return 0;
}
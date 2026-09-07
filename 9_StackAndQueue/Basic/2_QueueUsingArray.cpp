#include<bits/stdc++.h>
using namespace std;
class Q{
    int start = -1, end = -1;
    static const int capacity = 4;
    int arr[capacity];
    int currSize = 0;
public:
    void enqueue(int num){
        if(currSize == capacity){
            cout << "No capacity left\n";
            return;
        }
        else if(currSize == 0){
            start = end = 0;
        }
        else{
            end = (end+1) % capacity;
        }
        arr[end] = num;
        currSize++;
    }
    int dequeue(){
        if(currSize == 0){
            cout << "Nothing to dequeue\n";
            return -1;
        }
        int el = arr[start];
        if(currSize == 1){
            start = end = -1;
        }
        else{
            start = (start+1) % capacity;
        }
        currSize--;
        return el;
    }
    int front(){
        return currSize ? arr[start] : -1;
    }
    int size(){
        return currSize;
    }
    void print(){
        for(int i = 0; i < capacity; i++){
            cout << arr[(start + i)%capacity] << ' ';
        }cout << endl;
    }
};
int main(){
    Q q;
    q.enqueue(3);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.print();
    cout << q.front() << endl;
    cout << q.dequeue() << endl;
    q.enqueue(8);
    q.print();
    cout << q.size() << endl;
    return 0;
}
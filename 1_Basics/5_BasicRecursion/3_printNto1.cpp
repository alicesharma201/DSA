#include<bits/stdc++.h>
void forward(int count){
    if(count == 0) return;
    cout << count << " ";
    count--;
    forward(count);
}
void backtrack(int count, int n){
    if(count == n) return;
    count++;
    backtrack(count, n);
    cout << count << " ";
}
int main(){
    int n = 5;
    cout << "Forward tracking: ";
    forward(n);
    cout << endl;
    cout << "Backtrack: ";
    backtrack(0, n);
    return 0;
}
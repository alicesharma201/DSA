#include<bits/stdc++.h>
void Forward(int current, int n){
    if(current > n) return;
    cout << current << " ";
    current++;
    Forward(current, n);
}
void Backtrack(int current){
    if(current == 0) return;
    Backtrack(current-1);
    cout << current << " ";
}
int main(){
    int n = 5;
    cout << "Forward Recursion: ";
    Forward(1, n);
    cout << endl << "Backtracking: ";
    Backtrack(n);
    return 0;
}
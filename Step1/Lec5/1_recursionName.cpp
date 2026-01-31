#include<bits/stdc++.h>

void print(int n, string name, int count){
    if(n == count) return;
    cout << name << " ";
    print(n, name, count+1);
}

int main(){
    int n = 5;
    string name = "Alice";
    print(n, name, 0);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    for(int i=0; i<10; i++){
        if(i == 0){
            cout << "Hey Alice! This is the " << i+1 << "st iteration.\n";
        }
        else if(i == 1){
            cout << "Hey Alice! This is the " << i+1 << "nd iteration.\n";
        }
        else if(i == 2){
            cout << "Hey Alice! This is the " << i+1 << "rd iteration.\n";
        }
        else{
            cout << "Hey Alice! This is the " << i+1 << "th iteration.\n";
        }
    }
    return 0;
}
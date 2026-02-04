#include <bits/stdc++.h>
using namespace std;
int main(){
    int age = 22;
    if(age>=18 && age<=99){
    cout<<"You are eligible to vote";
    }
    else if(age>99){
    cout<<"Invalid age";
    }
    else{
    cout<<"You are not eligible to vote";
    }
    return 0;
}
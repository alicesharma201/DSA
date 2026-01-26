#include <bits/stdc++.h>
using namespace std;
int main(){
    string Arr[5] = {"Hello", "my", "name", "is", "Alice"};
    int size = sizeof(Arr)/sizeof(Arr[0]);
    int smallSize = Arr[4].size();
    for(int i=0; i<size; i++){
        cout << Arr[i] << '\n';
    }
    cout << '\n' << Arr[4][0] << '\n' << '\n';
    for(int j=0; j<smallSize; j++){
        cout << Arr[4][j] << '\n'; // it behaves like a 2d array :D
    }
    return 0;
}

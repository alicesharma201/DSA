#include<bits/stdc++.h>
void rotateArrayByOne(vector<int>& vec){
    int n = vec.size();
    int temp = vec[0];
    for(int i = 0; i < n-1; i++){
        vec[i] = vec[i+1];
    }
    vec[n-1] = temp;
}
int main(){
    vector<int> vec = {1, 2, 3, 4, 5};
    rotateArrayByOne(vec);
    for(int v : vec) cout << v << " ";
    return 0;
}
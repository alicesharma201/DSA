#include<bits/stdc++.h>
void recInsertion(vector<int>& vec, int n, int i){
    if(n == i) return;
    int key = vec[i];
    int j = i-1;
    while(j >= 0 && vec[j] > key){
        vec[j+1] = vec[j];
        j--;
    }
    vec[j+1] = key;
    recInsertion(vec, n, i+1);
}
int main(){
    vector<int> vec = {3, 6, 2, 7, 4, 1, 5};
    int n = vec.size();
    recInsertion(vec, n, 1);
    for(auto it : vec) cout << it << ' ';
    return 0;
}
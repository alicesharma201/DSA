#include<bits/stdc++.h>
void insertion(vector<int>& vec, int n){
    for(int i = 1; i < n; i++){
        int key = vec[i];
        int j = i - 1;
        while(j >= 0 && vec[j] > key){
            vec[j+1] = vec[j];
            j--;
        }
        vec[j+1] = key;
    }
}
int main(){
    vector<int> vec = {3, 6, 2, 7, 4, 1, 5};
    int n = vec.size();
    insertion(vec, n);
    for(auto it : vec) cout << it << ' ';
    return 0;
}
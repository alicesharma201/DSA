#include<bits/stdc++.h>
vector<int> insertion(vector<int>& vec){
    int n = vec.size();
    for(int i = 1; i < n; i++){ // i starts from 1 because idx 0 is already considered sorted
        int key = vec[i];
        int j = i - 1; // j started from 0
        while(j >= 0 && vec[j] > key){
            vec[j+1] = vec[j];
            j--;
        }
        vec[j+1] = key;
    }
    return vec;
}
int main(){
    vector<int> vec = {13, 52, 29, 36, 9, 65, 11};
    vector<int> res = insertion(vec);
    for(auto el : res) cout << el << " ";
    return 0;
}
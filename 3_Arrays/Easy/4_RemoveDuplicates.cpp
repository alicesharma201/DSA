#include<bits/stdc++.h>
vector<int> self(vector<int>& vec){
    int n = vec.size();
    set<int> temp;
    for(int i = 0; i < n; i++){
        temp.insert(vec[i]);
    }
    vec.clear();
    for(int item : temp){
        vec.emplace_back(item);
    }
    return vec;
}
int brute(vector<int>& vec){
    unordered_set<int> seen;
    int index = 0;
    for(int num : vec){
        if(seen.find(num) == seen.end()){ // here, if set doesn't contain the element, seen.find(num) will point to end()
            seen.insert(num);
            vec[index] = num;
            index++;
        }
    }
    return index;
}
int main(){
    vector<int> vec = {1,1,2,2,2,3,3,4};
    // self(vec);
    int k = brute(vec);
    cout << "k = " << k << "\nArray after removing duplicates: ";
    for(int i = 0; i < k; i++){
        cout << vec[i] << " ";
    }
    return 0;
}
#include<bits/stdc++.h>
void rotateArray(vector<int>& vec, int k, string dir){
    int n = vec.size();
    if(n == 0) return;
    k = k % n;
    if(dir == "left"){
        vector<int> leftTemp(k);
        for(int i = 0; i < k; i++) leftTemp[i] = vec[i];
        for(int i = k; i < n; i++) vec[i-k] = vec[i];
        for(int i = 0; i < k; i++) vec[n-k+i] = leftTemp[i];
    }
    else{
        vector<int> rightTemp(k);
        for(int i = 0; i < k; i++) rightTemp[i] = vec[n-k+i];
        for(int i = 0; i < n-k; i++) vec[n-i-1] = vec[n-k-i-1];
        for(int i = 0; i < k; i++) vec[i] = rightTemp[i];
    }
}
void constantSpace(vector<int>& vec, int k, string dir){
    int n = vec.size();
    if(n == 0) return;
    k = k % n;
    if(dir == "left"){
        int l = 0;
        int r = n-1;
        while(l < r){
            swap(vec[l],vec[r]);
            l++; r--;
        }
        l = 0;
        r = n-k-1;
        while(l < r){
            swap(vec[l], vec[r]);
            l++; r--;
        }
        l = n-k;
        r = n-1;
        while(l < r){
            swap(vec[l], vec[r]);
            l++; r--;
        }
    }
    else{
        int l = 0;
        int r = n-1;
        while(l < r){
            swap(vec[l],vec[r]);
            l++; r--;
        }
        l = 0;
        r = k-1;
        while(l < r){
            swap(vec[l], vec[r]);
            l++; r--;
        }
        l = k;
        r = n-1;
        while(l < r){
            swap(vec[l], vec[r]);
            l++; r--;
        }
    }
}
void stl(vector<int>& vec, int k, string dir){
    int n = vec.size();
    if(n == 0) return;
    k = k % n;
    if(dir == "left"){
        reverse(vec.begin(), vec.end());
        reverse(vec.begin(), vec.end()-k);
        reverse(vec.end()-k, vec.end());
    }
    else{
        reverse(vec.begin(), vec.end());
        reverse(vec.begin(), vec.begin()+k);
        reverse(vec.begin()+k, vec.end());
    }
}
int main(){

    // vector<int> vec1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // int k1 = 3;
    // string dir1 = "left";
    // rotateArray(vec1, k1, dir1);
    // for(int v : vec1) cout << v << " ";

    // cout << endl;

    // vector<int> vec2 = {1, 2, 3, 4, 5, 6, 7}; 
    // int k2 = 3;
    // string dir2 = "right";
    // constantSpace(vec2, k2, dir2);
    // for(int v : vec2) cout << v << " ";

    // cout << endl;

    vector<int> vec3 = {1, 2, 3, 4, 5, 6, 7};
    int k3 = 2;
    string dir3 = "right";
    stl(vec3, k3, dir3);
    for(int v : vec3) cout << v << " ";

    return 0;
}
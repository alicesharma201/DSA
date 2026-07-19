#include<bits/stdc++.h>
int kthElement(vector<int>& a, vector<int>& b, int k){
    int i = 0, j = 0, cnt = 0, val;
    while(i < a.size() && j < b.size()){
        if(a[i] <= b[j]){
            val = a[i];
            cnt++;
            i++;
        }
        else{
            val = b[j];
            cnt++;
            j++;
        }
        if(cnt == k) return val;
    }
    while(i < a.size()){
        val = a[i];
        cnt++;
        i++;
        if(cnt == k) return val;
    }
    while(j < b.size()){
        val = b[j];
        cnt++;
        j++;
        if(cnt == k) return val;
    }
    return -1;
}
int main(){
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    int k = 7;
    cout << kthElement(a, b, k) << endl;
    return 0;
}
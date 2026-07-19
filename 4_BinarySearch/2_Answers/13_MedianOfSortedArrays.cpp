#include<bits/stdc++.h>
float bruteMedian(vector<int>& arr1, vector<int>& arr2){
    // similar to merge sort
    // TC: O(n+m)
    // SC: O(n+m)
    int n = arr1.size(), m = arr2.size();
    vector<int> temp;
    int a1 = 0, a2 = 0;
    while(a1 < n && a2 < m){
        if(arr1[a1] <= arr2[a2]){
            temp.push_back(arr1[a1]);
            a1++;
        }else{
            temp.push_back(arr2[a2]);
            a2++;
        }
    }
    while(a1 < n){
        temp.push_back(arr1[a1]);
        a1++;
    }
    while(a2 < n){
        temp.push_back(arr2[a2]);
        a2++;
    }
    if((n+m)%2 == 1) return temp[(n+m)/2];
    else{
        float val = temp[((n+m)/2)-1] + temp[(n+m)/2];
        return val/2;
    }
}
float betterMedian(vector<int>& arr1, vector<int>& arr2){
    int n = arr1.size(), m = arr2.size();
    int cnt1 = 0, cnt2 = 0;
    int a1 = 0, a2 = 0;
    while(a1 < n && a2 < m){
        if(arr1[a1] <= arr2[a2]){
            cnt1++;
            if(cnt1 == ((n+m)/2)){
                

            }
            a1++;
        }else{
            cnt1++;
            if(cnt1 == ((n+m)/2)){

            }
            a2++;
        }
    }
 
}
int main(){
    vector<int> arr1 = {2, 4, 7};
    vector<int> arr2 = {1, 3, 5, 6};
    cout << bruteMedian(arr1, arr2) << endl;
    cout << betterMedian(arr1, arr2) << endl;
    return 0;
}
#include<bits/stdc++.h>
int studentsRecieved(vector<int>& books, int maxPages){
    int studentsAllocated = 1;
    int pageSum = 0;
    for(int pages : books){
        if(pageSum + pages <= maxPages){
            pageSum += pages;
        } else {
            pageSum = pages;
            studentsAllocated++;
        }
    }
    return studentsAllocated;
}
int linearBookAllocate(vector<int>& books, int m){
    // TC: O(N * (high-low+1))
    if(m > books.size()) return -1;
    int low = *max_element(books.begin(), books.end());
    int high = accumulate(books.begin(), books.end(), 0);
    for(int i = low; i <= high; i++){
        if(studentsRecieved(books, i) <= m) return i;
    }
    return -1;
}
int binaryBookAllocate(vector<int>& books, int m){
    // TC: O(N * log(high-low+1))
    if(m > books.size()) return -1;
    int low = *max_element(books.begin(), books.end());
    int high = accumulate(books.begin(), books.end(), 0);
    while(low <= high){
        int mid = low + (high - low)/2;
        int studentsAllocated = 1;
        int pageSum = 0;
        if(studentsRecieved(books, mid) <= m){
            high = mid - 1;
        } else low = mid + 1;
    }
    return low; // opposite polarity: before low pointed at not possible, so in the end it would point at possible which will be our answer
}
int main(){
    vector<int> books = {12, 34, 67, 90};
    int students = 2;
    cout << linearBookAllocate(books, students) << endl;
    cout << binaryBookAllocate(books, students) << endl;
    return 0;
}
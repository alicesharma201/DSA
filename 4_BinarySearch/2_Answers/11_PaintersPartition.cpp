#include<bits/stdc++.h>
int painterCount(vector<int>& boards, int limit){
    int boardCount = 1, boardSum = 0;
    for(int board : boards){
        if(boardSum + board <= limit){
            boardSum += board;
        }else{
            boardSum = board;
            boardCount++;
        }
    }
    return boardCount;
}
int linearBoardPartition(vector<int>& boards, int k){
    // TC: O(N * (high-low+1))
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);
    for(int i = low; i <= high; i++){
        if(painterCount(boards, i) <= k) return i;
    }
    return -1;
}
int binaryBoardPartition(vector<int>& boards, int k){
    // TC: O(N * log(high-low+1))
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);
    while(low <= high){
        int mid = low + (high - low)/2;
        if(painterCount(boards, mid) <= k) high = mid - 1;
        else low = mid + 1;
    }
    return low;
}
int main(){
    vector<int> boards = {10, 20, 30, 40};
    int k = 2;
    cout << linearBoardPartition(boards, k) << endl;
    cout << binaryBoardPartition(boards, k) << endl;
    return 0;
}
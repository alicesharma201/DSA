#include <bits/stdc++.h>
int linear(int N, int M) {
    // TC: O(M)
    // SC: O(1)
    for (int i = 1; i <= M; i++){
        long long val = pow(i, N);
        if (val == M) return i;
        if (val > M) break;
    }
    return -1;
}
long long calcPower(int mid, int N, int M){
    long long ans = 1;
    for(int i = 0; i < N; i++){
        ans *= mid;
        if(ans > M) return ans;
    }
    return ans;
}
int binary(int N, int M){
    // TC: O(N * logM)
    // SC: O(1)
    if(M == 0) return 0;
    int low = 1, high = M;
    while(low <= high){
        int mid = low + (high - low)/2;
        long long power = calcPower(mid, N, M);
        if(power == M)
            return mid;
        if(power > M)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
int main(){
    int N = 3, M = 216;
    cout << linear(N, M) << endl;
    cout << binary(N, M) << endl;
    return 0;
}
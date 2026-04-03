#include<bits/stdc++.h>

// To return the value of element at row and column
long long elementValue(int n, int r){ 
    // nCr = (row-1) C (col-1)
    // TC: O(n)
    // SC: O(1)
    long long res = 1;
    for(int i = 0; i < r; i++){
        // eg: element is 6 (row-1 = 5-1 = 4 | col-1 = 3-1 = 2)
        res = res * (n-i); // 4*3 (numerator)
        res = res / (i+1); // 1*2 (denominator)
    }
    return res;
}

// To print the nth row
void brutePrintRow(int N){ 
    // TC: O(N*r)
    // SC: O(1)
    for(int col = 1; col <= N; col++){ 
        cout << elementValue(N-1, col-1) << " ";
    }
}
void optimalPrintRow(int N){
    // TC: O(N)
    // SC: O(1)
    long long ans = 1;
    int row = N;
    for(int col = 1; col <= row; col++){
        // row - col (numerator) = 5*4*3*2*1
        // col (denominator)     = 1*2*3*4*5
        cout << ans << " "; 
        ans = (ans * (row - col)) / col;
    }
}

// print the whole triangle
auto bruteTriangle(int N){
    // TC: O(n*n*r) = O(n^3)
    // SC: for storing ans

    // for(row -> N)
    //     for(column -> N)
    //         temp.add(brutePrintRow(N))
    //     ans.add(temp)
}
vector<long long> generateRow(int i){
    long long ans = 1;
    vector<long long> temp;
    for(int col = 1; col <= i; col++){
        temp.push_back(ans);
        ans = (ans * (i-col))/col;
    }
    return temp;
}
vector<vector<long long>> optimalTriangle(int N){
    // TC: O(N^2)
    // SC: for returning vector
    vector<vector<long long>> result;
    for(int i = 1; i <= N; i++){
        result.push_back(generateRow(i));
    }
    return result;
}

int main(){
    int N = 5;
    int row = 5, col = 3;

    cout << "Index of the element at (row,col): " << elementValue(row-1, col-1); // Pascals Triangle uses zero based indexing
    
    cout << "\nBrute Nth row: "; brutePrintRow(N);
    cout << "\nOptimal Nth row: "; optimalPrintRow(N);

    cout << "\nOptimal Triangle:\n";
    vector<vector<long long>> result = optimalTriangle(N);
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
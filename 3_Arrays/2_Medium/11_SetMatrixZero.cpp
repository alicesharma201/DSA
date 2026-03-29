#include<iostream>
using namespace std;
vector<vector<int>> self(vector<vector<int>> nums){
    // for time complexity: matrix traversal + (pair traversal * assigning zero)
    // TC: O(m*n + (m*n)*(m*n)) = O((m^2 n^2)
    // SC: O(m*n) for storing indices of zeroes, worst case is all elements of the matrix are zero
    int m = nums.size(), n = nums[0].size();
    vector<pair<int, int>> makeZero;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(nums[i][j] == 0){
                makeZero.push_back({i, j});
            }
        }
    }
    for(int k = 0; k < makeZero.size(); k++){
        int row = makeZero[k].first;
        int column = makeZero[k].second;
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < nums[i].size(); j++){
                if(row == i) nums[row][j] = 0;
                if(column == j) nums[i][column] = 0;
            }
        }
    }
    return nums;
}
vector<vector<int>> brute(vector<vector<int>> nums){
    // TC: O(m*n*(m+n) + m*n*(m+n)) = O(m*n*(m+n))
    // SC: O(1)
    int m = nums.size(), n = nums[0].size();
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(nums[i][j] == 0){
                for(int row = 0; row < m; row++) if(nums[row][j] != 0) nums[row][j] = -1;
                for(int column = 0; column < n; column++) if(nums[i][column] != 0) nums[i][column] = -1;
            }
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(nums[i][j] == -1){
                for(int row = 0; row < m; row++) if(nums[row][j] == -1) nums[row][j] = 0;
                for(int column = 0; column < n; column++) if(nums[i][column] == -1) nums[i][column] = 0;
            }
        }
    }
    return nums;
}
vector<vector<int>> better(vector<vector<int>> nums){
    // TC: O(m*n + m*n) = O(m*n)
    // SC: O(m+n)

    /* Matrix: (3x4)
    ◼️ 🟩 🟩 🟩 🟩
    🟥 ⬜️ ⬜️ ⬜️ ⬜️
    🟥 ⬜️ ⬜️ ⬜️ ⬜️
    🟥 ⬜️ ⬜️ ⬜️ ⬜️
    */

    int m = nums.size(), n = nums[0].size();
    vector<int> rows(m, 0);
    vector<int> columns(n, 0);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(nums[i][j] == 0){
                rows[i] = 1;
                columns[j] = 1;
            }
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(rows[i] == 1 || columns[j] == 1){
                nums[i][j] = 0;
            }
        }
    }
    return nums;
}
vector<vector<int>> optimal(vector<vector<int>> nums){ // in-placed
    // TC: O(mn)
    // SC: O(1)
    /*
    🟥: nums[i][0] (first column, it makes changes in the rows)
    🟩: nums[0][j] (first row, it makes changes in the cols)

    Matrix: (3x4)
    🟩 <- col0 
    🟥 🟩 🟩 🟩
    🟥 ⬜️ ⬜️ ⬜️
    🟥 ⬜️ ⬜️ ⬜️

    col0: 
    if this auxiliary block is 0, then nums[0][0] will be marked as 0
    if block is 1, then nums[0][0] will be unchanged

    steps:
    - iterate the matrix to mark zeroes in 🟥 🟩 if any zero is spotted 
        - here, all the 🟥 🟩 will get correctly be marked for making ⬜️ zero later
        - edge case: if j = 0 make col0 = 0, otherwise col0 will stay 1
    - start iterating ⬜️ to check if 🟥 🟩 have any zeros and make ⬜️ zero according to them
    - when will all 🟥 be zero? when col0 is zero
    - when will all 🟩 be zero? when (0,0) is zero
    */

    int col0 = 1;
    int m = nums.size(), n = nums[0].size();

    // marking 🟥 🟩 as zero
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(nums[i][j] == 0){
                nums[i][0] = 0;
                if(j != 0) nums[0][j] = 0;
                else col0 = 0;
            }
        }
    }

    // marking ⬜️ as zero
    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            if(nums[i][j] != 0){ // if it is already zero then what's the point of checking and changing it into zero, that's why we only change the ones who are not already zero
                if(nums[0][j] == 0 || nums[i][0] == 0){
                    nums[i][j] = 0;
                }
            }
        }
    }

    if(nums[0][0] == 0){ // making all 🟩 zero
        for(int j = 0; j < n; j++){
            nums[0][j] = 0;
        }
    }

    if(col0 == 0){ // making all 🟥 zero
        for(int i = 0; i < m; i++){
            nums[i][0] = 0;
        }
    }

    cout << "{ " << col0 << "       }" << endl;
    return nums;
}
int main(){
    vector<vector<int>> nums = {
        {1, 1, 1, 1},
        {0, 1, 0, 1},
        {1, 1, 1, 1}
    };
    // vector<vector<int>> result = self(nums);
    // vector<vector<int>> result = brute(nums);
    // vector<vector<int>> result = better(nums);
    vector<vector<int>> result = optimal(nums);
    for(int i = 0; i < result.size(); i++){
        cout << "{ ";
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << "}" << endl;
    }
    return 0;
}
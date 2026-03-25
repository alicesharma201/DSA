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
int main(){
    vector<vector<int>> nums = {
        {3, 4, 7, 1},
        {9, 6, 0, 2},
        {8, 1, 8, 5}
    };
    // vector<vector<int>> result = self(nums);
    // vector<vector<int>> result = brute(nums);
    vector<vector<int>> result = better(nums);
    for(int i = 0; i < result.size(); i++){
        cout << "{ ";
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << "}" << endl;
    }
    return 0;
}
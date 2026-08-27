#include<bits/stdc++.h>
using namespace std;
void dfs(int i, string valid_str, long long total, long long prev, string& num, int target, vector<string>& res){ // prev represents the last operand including its sign
    if(i == num.size()){
        if(total == target) res.push_back(valid_str);
        return;
    }
    for(int j = i; j < num.size(); j++){
        string curr_str = num.substr(i, j-i+1);
        long long curr_num = stoll(curr_str);

        if(i == 0) dfs(j+1, curr_str, curr_num, curr_num, num, target, res);
        else{
            dfs(j+1, valid_str + "+" + curr_str, total + curr_num, curr_num, num, target, res);
            dfs(j+1, valid_str + "-" + curr_str, total - curr_num, -curr_num, num, target, res);
            dfs(j+1, valid_str + "*" + curr_str, total - prev + curr_num * prev, curr_num * prev, num, target, res);
        }
        if(num[i] == '0') break; // here we skip the leading zeros
    }
}
vector<string> addOperators(string num, int target) {
    vector<string> res;
    dfs(0, "", 0, 0, num, target, res);
    return res;
}
int main(){
    string num = "123";
    int target = 6;
    for(auto i : addOperators(num, target)) cout << i << ' ';
    return 0;
}
#include<bits/stdc++.h>
vector<int> self(vector<int> nums){
    vector<int> missrep(2, 0);
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for(int i = 0; i < n-1; i++){
        if(nums[i] == nums[i+1]){
            missrep[0] = nums[i];
        }
    }
    for(int i = 0; i < n; i++){
        if(nums[i] != i+1){
            missrep[1] = i+1;
            break;
        }
    }
    return missrep;
}
vector<int> brute(vector<int>& nums){
    // TC: O(n^2)
    // SC: O(1)
    int n = nums.size();
    int repeating = -1, missing = -1;
    for(int i = 1; i <= n; i++){
        int count = 0;
        for(int j = 0; j < n; j++){ // linear search
            if(nums[j] == i) count++;
        }
        if(count == 2) repeating = i; 
        else if(count == 0) missing = i;
        if(repeating != -1 && missing != -1) break;
    }
    return {repeating, missing};
}
vector<int> better(vector<int>& nums){
    // TC: O(n)
    // SC: O(n)
    int n = nums.size();
    vector<int> hash(n+1, 0);
    for(int i = 0; i < n; i++){
        hash[nums[i]]++;
    }
    int repeating = -1, missing = -1;
    for(int i = 1; i <= n; i++){
        if(hash[i] == 2) repeating = i;
        else if(hash[i] == 0) missing = i;
        if(repeating != -1 && missing != -1) break;
    }
    return {repeating, missing};
}
vector<int> optimal1(vector<int>& nums){ 
    // TC: O(n)
    // SC: O(1)

    /* {x = repeating, y = missing}
    actualSum   - naturalSum   =   x - y   = val1                  ---(1)
    actualSqSum - naturalSqSum = x^2 - y^2 = (x - y)(x + y) = val2 ---(2) 

    put (1) in (2)
    val1 (x + y) = val2
    (x + y) = val2 / val1 (we calling it val2 again)

    x + y = val2
    x - y = val1 
    ------------------ (add)
       2x = val2 + val1
        x = (val2 + val1) / 2
        x = {repeating}

    from (1)
    x - y = val1
    x - val1 = y {missing} 
    */

    int n = nums.size();
    long long Sn = (long long)n * (n + 1) / 2;
    long long S2n = (long long)n * (n + 1) * (2 * n + 1) / 6; // sum of square of n natural numbers
    long long S = 0;
    long long S2 = 0; // sum of square of elements in the array
    for(int i = 0; i < n; i++){
        S += nums[i];
        S2 += (long long)nums[i] * (long long)nums[i];
    }
    long long val1 = S - Sn; // equation 1
    long long val2 = S2 - S2n; // equation 2
    val2 = val2 / val1;
    long long repeating = (val1 + val2) / 2; // equation (1) + (2)
    long long missing = repeating - val1;    // from equation (1)
    return {(int)repeating, (int)missing};
}
vector<int> optimal2(vector<int>& nums) {
    int n = nums.size(); 
    int xr = 0;
    for (int i = 0; i < n; i++) {
        xr = xr ^ nums[i]; 
        xr = xr ^ (i + 1);  
    }
    int number = (xr & ~(xr - 1));
    int zero = 0; 
    int one = 0;  
    for (int i = 0; i < n; i++) {
        if ((nums[i] & number) != 0) {
            one = one ^ nums[i];
        } else {
            zero = zero ^ nums[i]; 
        }
    }
    for (int i = 1; i <= n; i++) {
        if ((i & number) != 0) {
            one = one ^ i; 
        } else {
            zero = zero ^ i; 
        }
    }
    int cnt = 0; 
    for (int i = 0; i < n; i++) {
        if (nums[i] == zero) {
            cnt++;
        }
    }
    if (cnt == 2) {
        return {zero, one}; 
    }
    return {one, zero}; 
}
int main(){
    vector<int> nums = {1, 2, 3, 6, 7, 5, 7};
    // for(int i : self(nums)) cout << i << " "; cout << endl;
    for(int i : brute(nums)) cout << i << " "; cout << endl;
    for(int i : better(nums)) cout << i << " "; cout << endl;
    for(int i : optimal1(nums)) cout << i << " "; cout << endl;
    for(int i : optimal2(nums)) cout << i  << " "; cout << endl;
    return 0;
}
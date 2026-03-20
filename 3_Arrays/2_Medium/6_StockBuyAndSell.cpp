#include<bits/stdc++.h>
int brute(vector<int>& prices){
    // TC: O(n^2)
    // SC: O(1)
    int n = prices.size();
    int maxProfit = 0;
    for(int buy = 0; buy < n; buy++){
        for(int sell = buy+1; sell < n; sell++){
            int profit = prices[sell] - prices[buy];
            if(profit > maxProfit) maxProfit = profit;
        }
    }
    if(maxProfit > 0) return maxProfit;
    return 0;
}
int optimal(vector<int>& nums){
    // TC: O(n)
    // SC: O(1)

    // Carry the lowest price with you, and at every step, check how much profit you’d make if you sold now.

    // If you update mini before calculating profit, you’ll break logic.
    // Correct order is to calculate profit first, then update minimum

    int n = nums.size();
    int mini = nums[0]; // lowest price seen so far (day 0)
    int profit = 0; // max profit
    for(int i = 1; i < n; i++){ // starting from day 1
        int cost = nums[i] - mini; // buy at mini, sell at nums[i]
        profit = max(cost, profit);
        mini = min(mini, nums[i]); // update mini
    }
    return profit;
}
int main(){
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << brute(prices) << endl;
    cout << optimal(prices) << endl;
    return 0;
}
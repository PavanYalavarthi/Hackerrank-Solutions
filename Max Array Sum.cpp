/*
problem credits: https://www.hackerrank.com/challenges/max-array-sum/problem

Given an array of integers, find the subset of non-adjacent elements with the maximum sum. Calculate the sum of that subset. It is possible that the maximum sum is , the case when all elements are negative.

*/

int maxSubsetSum(vector<int> arr) {
    int n = arr.size();
    vector<int>dp(n+1);
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        int ele = arr[i-1];
        dp[i] = max(dp[i-2] + ele, dp[i-1]);
    }
    return dp[n];
}
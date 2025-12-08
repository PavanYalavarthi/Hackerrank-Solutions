int birthdayCakeCandles(vector<int> candles) {
    sort(candles.begin(), candles.end());
    int ans = 1, n = candles.size();
    for(int i = n-2; i >= 0; i--) {
        if (candles[i] == candles[n-1]) ans++;
        else break;
    }
    return ans;
}

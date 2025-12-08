long aVeryBigSum(vector<long> ar) {
    long ans = 0;
    for(int i =0; i < ar.size(); i++) {
        ans += ar[i];
    }
    return ans;
}
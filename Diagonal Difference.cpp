int diagonalDifference(vector<vector<int>> arr) {
    int n = arr.size(), diag1 = 0, diag2 = 0;
    for(int i = 0; i < n;i++) {
        diag1 += arr[i][i], diag2 +=arr[i][n-1-i];
    }
    return abs(diag1 - diag2);
}
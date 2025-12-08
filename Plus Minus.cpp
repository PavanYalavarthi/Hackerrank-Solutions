void plusMinus(vector<int> arr) {
    float n = arr.size(), zeros = 0, pos = 0, neg = 0;
    for (int i =0; i < n; i++) {
        if (arr[i] == 0) zeros++;
        else if (arr[i] < 0) neg++;
        else pos++;
    }
    cout << pos/n << '\n' << neg/n << '\n' << zeros/n;
}
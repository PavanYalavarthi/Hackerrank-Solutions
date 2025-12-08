void miniMaxSum(vector<int> arr) {
    long mn = arr[0], mx = arr[0], sum = arr[0];
    for(int i = 1; i < 5; i++) {
        if (mn > arr[i]) mn = arr[i];
        else if (mx < arr[i]) mx = arr[i];
        sum += arr[i];
    }
    cout << sum - mx << " " << sum - mn;
}
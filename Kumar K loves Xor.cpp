/*
https://www.hackerrank.com/contests/desiqna-oa-practice-contest-00/challenges/a-356/problem
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    unordered_map<int, int>mp;
    mp[0] = -1;
    int prevXor = 0, ans = 0;
    for(int i = 0, b; i < n; i++) {
        cin >> b;
        int Xor = prevXor ^ a[i] ^ b;
        if (mp.count(Xor)) {
            ans = max(ans, i - mp[Xor]);
        } else {
            mp[Xor] = i;
        }
        prevXor = Xor;
    }
    cout << ans;
    return 0;
}
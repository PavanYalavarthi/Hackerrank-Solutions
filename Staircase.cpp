void staircase(int n) {
    string s(n, ' ');
    for(int i = n-1; i>= 0; i--) {
        s[i] = '#';
        cout << s << endl;
    }
}

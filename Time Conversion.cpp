string timeConversion(string s) {
    int hr = (s[0] - '0')*10 + (s[1] - '0');
    if(s[8] == 'P' ^ hr == 12) {
        hr = (hr + 12) % 24;
        s[0] = hr /10 + '0';
        s[1] = hr % 10 + '0';
    }
    return s.substr(0, 8);
}

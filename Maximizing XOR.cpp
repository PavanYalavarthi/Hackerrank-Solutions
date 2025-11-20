/*
Problem description: https://www.hackerrank.com/challenges/maximizing-xor/problem

Solution: We need to see till bit changes in l and r. 

Once bit changes, we are free to take opposite bits to set XOR to be 1

If at i, bit flips, ans = 2^i-1
*/
int maximizingXor(int l, int r) {
    if(l == r) return 0;
    int i = 31 - __builtin_clz(r);
    for(; i >= 0; i--) {
        if((l & (1 << i)) != (r & (1 << i))) break;
    }
    i++;
    return (1 << i) - 1;
}
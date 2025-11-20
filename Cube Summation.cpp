/*
    Problem credits: https://www.hackerrank.com/challenges/cube-summation/problem

    SOlution:

    Used 3D fenwick tree. used Inclusion / exclusion for range query

    #3DFenwickTree
*/
struct BIT {
    static const int MAX_SIZE = 102;
    long BIA[MAX_SIZE][MAX_SIZE][MAX_SIZE] = {{{0}}};
    
    void update(int x, int y, int z, int val) {
        for (int i = x; i < MAX_SIZE; i += i & -i)
            for (int j = y; j < MAX_SIZE; j += j & -j)
                for (int k = z; k < MAX_SIZE; k += k & -k)
                    BIA[i][j][k] += val;
    }
    
    long query(int x, int y, int z) {
        long sum = 0;
        for(int i = x; i > 0; i -= i & -i)
            for(int j = y; j > 0; j -= j & -j)
                for(int k = z; k > 0; k -= k & -k)
                    sum += BIA[i][j][k];
        return sum;
    }
    
    long range_query(int x1, int y1, int z1, int x2, int y2, int z2) {
        return  query(x2, y2, z2)
            - query(x1 - 1, y2, z2)
            - query(x2, y1 -1, z2)
            - query(x2, y2, z1 -1)
            + query(x1 -1, y1 - 1, z2)
            + query(x2, y1 - 1, z1 - 1)
            + query(x1 - 1, y2, z1 -1)
            - query(x1 -1, y1 -1, z1 -1);
    }
};

/*
 * Complete the 'cubeSum' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING_ARRAY operations
 */

 // This needed to return long only. Else, it is failing
vector<long> cubeSum(int n, vector<string> operations) {
    BIT bit;
    int no_of_operations = operations.size();
    vector<long>res;
    for(int i =0; i< no_of_operations; i++) {
        stringstream ss(operations[i]);
        string word;
        ss >> word;
        if (word == "UPDATE") {
            int x, y, z, val;
            ss >> x >> y >> z >> val;
            long cur_val = bit.range_query(x, y, z, x, y, z);
            bit.update(x, y, z, val - cur_val);
        } else {
            int x1, y1, z1, x2, y2, z2;
            ss >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
            res.push_back(bit.range_query(x1, y1, z1, x2, y2, z2));
        }
    }
    return res;
}
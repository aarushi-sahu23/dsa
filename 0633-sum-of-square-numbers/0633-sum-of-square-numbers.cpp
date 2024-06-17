class Solution {
public:
    bool judgeSquareSum(int c) {
        for (int a = 0; a <= sqrt(c); ++a) {
        int b_squared = c - a * a;
        int b = sqrt(b_squared);
        if (b * b == b_squared) {
            return true;
        }
    }
    return false;
    }
};
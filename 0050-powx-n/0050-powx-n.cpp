class Solution {
public:
    double myPow(double x, int n) {
       if (n == 0) {
            return 1.0;
        }
        if (n == 1) {
            return x;
        }
        if (n < 0) {
            x = 1 / x;
            if (n == INT_MIN) {  // Handle INT_MIN case separately to avoid overflow
                return x * myPow(x, INT_MAX);
            } else {
                n = -n;
            }
        }
        double half = myPow(x, n / 2);
        if (n % 2 == 0) {
            return half * half;
        } else {
            return half * half * x;
        }

    }
};
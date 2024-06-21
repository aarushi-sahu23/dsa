class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
         int n = customers.size();
    int total_satisfied = 0;
    
    // Calculate the number of customers satisfied without any technique
    for (int i = 0; i < n; ++i) {
        if (grumpy[i] == 0) {
            total_satisfied += customers[i];
        }
    }

    // Calculate the additional satisfied customers if we use the technique
    int extra_satisfied = 0;
    for (int i = 0; i < minutes; ++i) {
        if (grumpy[i] == 1) {
            extra_satisfied += customers[i];
        }
    }

    int max_extra_satisfied = extra_satisfied;

    // Sliding window to find the maximum extra satisfied customers
    for (int i = minutes; i < n; ++i) {
        if (grumpy[i - minutes] == 1) {
            extra_satisfied -= customers[i - minutes];
        }
        if (grumpy[i] == 1) {
            extra_satisfied += customers[i];
        }
        max_extra_satisfied = max(max_extra_satisfied, extra_satisfied);
    }

    return total_satisfied + max_extra_satisfied;
    }
};
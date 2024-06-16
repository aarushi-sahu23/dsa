class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
          long long miss = 1; // The smallest number that we cannot form
    int patches = 0;    // The number of patches we have added
    int i = 0;          // Index to traverse the array

    while (miss <= n) {
        if (i < nums.size() && nums[i] <= miss) {
            miss += nums[i];
            i++;
        } else {
            miss += miss;
            patches++;
        }
    }

    return patches;
    }
};
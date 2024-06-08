class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
         unordered_map<int, int> prefixModMap;
    prefixModMap[0] = -1; // This handles the case where the subarray starts from index 0
    int prefixSum = 0;

    for (int i = 0; i < nums.size(); ++i) {
        prefixSum += nums[i];
        int mod = prefixSum % k;
        // Adjusting negative mod value to be positive
        if (mod < 0) mod += k;

        if (prefixModMap.find(mod) != prefixModMap.end()) {
            if (i - prefixModMap[mod] > 1) {
                return true;
            }
        } else {
            prefixModMap[mod] = i;
        }
    }
    return false;
    }
};
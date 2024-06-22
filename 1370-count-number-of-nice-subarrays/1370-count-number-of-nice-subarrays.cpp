class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
         unordered_map<int, int> count;
    count[0] = 1;
    int oddCount = 0, result = 0;
    
    for (int num : nums) {
        oddCount += num % 2;
        if (count.find(oddCount - k) != count.end()) {
            result += count[oddCount - k];
        }
        count[oddCount]++;
    }
    
    return result;
    }
};
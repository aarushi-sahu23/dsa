class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected = heights;
        
        // Sort the expected array
        sort(expected.begin(), expected.end());
        
        // Count the number of indices where heights[i] != expected[i]
        int count = 0;
        for (size_t i = 0; i < heights.size(); ++i) {
            if (heights[i] != expected[i]) {
                ++count;
            }
        }
        
        return count;
    }
};
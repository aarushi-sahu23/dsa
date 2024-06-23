class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
       deque<int> maxDeque; // will store indices of elements in decreasing order
    deque<int> minDeque; // will store indices of elements in increasing order
    int start = 0, result = 0;

    for (int end = 0; end < nums.size(); ++end) {
        // Maintain the max deque
        while (!maxDeque.empty() && nums[maxDeque.back()] <= nums[end]) {
            maxDeque.pop_back();
        }
        maxDeque.push_back(end);

        // Maintain the min deque
        while (!minDeque.empty() && nums[minDeque.back()] >= nums[end]) {
            minDeque.pop_back();
        }
        minDeque.push_back(end);

        // Ensure the current window satisfies the condition
        while (nums[maxDeque.front()] - nums[minDeque.front()] > limit) {
            if (maxDeque.front() == start) maxDeque.pop_front();
            if (minDeque.front() == start) minDeque.pop_front();
            start++;
        }

        // Update the result
        result = max(result, end - start + 1);
    }

    return result; 
    }
};
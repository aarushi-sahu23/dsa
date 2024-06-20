class Solution {
public:
bool canPlaceBalls(vector<int>& position, int m, int mid) {
    int count = 1; // Place the first ball
    int last_position = position[0]; // First ball is placed at the first basket position

    for (int i = 1; i < position.size(); i++) {
        if (position[i] - last_position >= mid) {
            count++;
            last_position = position[i];
            if (count == m) {
                return true;
            }
        }
    }
    return false;
}

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
    int left = 1; // Minimum possible distance
    int right = position.back() - position.front(); // Maximum possible distance
    int result = 0;

    // Binary search for the maximum minimum distance
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canPlaceBalls(position, m, mid)) {
            result = mid; // Update the result to the current mid
            left = mid + 1; // Try for a larger distance
        } else {
            right = mid - 1; // Try for a smaller distance
        }
    }

    return result;
    }
};
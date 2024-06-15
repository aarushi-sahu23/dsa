class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
         vector<pair<int, int>> projects;
        int n = profits.size();
        
        for (int i = 0; i < n; ++i) {
            projects.push_back({capital[i], profits[i]});
        }
        
        // Sort projects by the required capital
        sort(projects.begin(), projects.end());
        
        // Max-Heap to store the profits of the projects we can afford to start
        priority_queue<int> maxProfitHeap;
        
        int currentCapital = w;
        int index = 0;
        
        for (int i = 0; i < k; ++i) {
            // Add all projects that can be started with the current capital to the max-heap
            while (index < n && projects[index].first <= currentCapital) {
                maxProfitHeap.push(projects[index].second);
                index++;
            }
            
            // If we cannot start any project, break out of the loop
            if (maxProfitHeap.empty()) {
                break;
            }
            
            // Select the project with the maximum profit
            currentCapital += maxProfitHeap.top();
            maxProfitHeap.pop();
        }
        
        return currentCapital;
    }
};
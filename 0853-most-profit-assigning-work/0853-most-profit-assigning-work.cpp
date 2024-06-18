class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
    vector<pair<int, int>> jobs(n);
    
    for (int i = 0; i < n; ++i) {
        jobs[i] = {difficulty[i], profit[i]};
    }
    
    // Sort jobs by difficulty, and in case of tie, by profit descending
    sort(jobs.begin(), jobs.end());
    
    // Sort workers by their abilities
    sort(worker.begin(), worker.end());
    
    int maxProfit = 0;
    int jobIndex = 0;
    int bestProfitSoFar = 0;
    
    for (int ability : worker) {
        // Move jobIndex to the right position where jobs[jobIndex].first <= ability
        while (jobIndex < n && jobs[jobIndex].first <= ability) {
            bestProfitSoFar = max(bestProfitSoFar, jobs[jobIndex].second);
            ++jobIndex;
        }
        maxProfit += bestProfitSoFar;
    }
    
    return maxProfit;
 
        
    }
};
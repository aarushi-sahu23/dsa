class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
  unordered_map<int, int> orderMap;
        for (int i = 0; i < arr2.size(); ++i) {
            orderMap[arr2[i]] = i;
        }

        // Custom comparator function for sorting arr1
        auto comparator = [&orderMap](int a, int b) {
            auto it_a = orderMap.find(a);
            auto it_b = orderMap.find(b);
            // If both elements are in arr2, sort by their positions in arr2
            if (it_a != orderMap.end() && it_b != orderMap.end()) {
                return it_a->second < it_b->second;
            }
            // If only one element is in arr2, that element should come first
            if (it_a != orderMap.end()) return true;
            if (it_b != orderMap.end()) return false;
            // If neither element is in arr2, sort by their natural order
            return a < b;
        };

        // Sort arr1 using the custom comparator
        sort(arr1.begin(), arr1.end(), comparator);
        return arr1;
}
};
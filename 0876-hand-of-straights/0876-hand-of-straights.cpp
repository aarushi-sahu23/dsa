class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
     if (hand.size() % groupSize != 0) return false;

    map<int, int> count;
    for (int card : hand) {
        count[card]++;
    }

    for (auto& [card, cnt] : count) {
        if (cnt > 0) {
            for (int i = 1; i < groupSize; ++i) {
                if (count[card + i] < cnt) return false;
                count[card + i] -= cnt;
            }
        }
    }

    return true;
    }
};
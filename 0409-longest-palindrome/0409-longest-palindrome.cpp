class Solution {
public:
    int longestPalindrome(string s) {
        int ans=0;
        unordered_map<char,int>mp;
        for(int i =0; i<s.size(); i++){
           mp[s[i]]+=1;
                   
        }
        bool hasOdd = false;
       for (auto it = mp.begin(); it != mp.end(); it++) {
            if (it->second % 2 != 0) {
                hasOdd = true;
            }
            ans += it->second / 2 * 2;
        }
        return ans + (hasOdd ? 1 : 0);
    }
};
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int c=0;
        for(int i =1; i< nums.size(); i++){           
            if(nums[i]<= nums[i-1]){
                int inc=  nums[i-1]- nums[i]+1;
                nums[i] += inc;
                c += inc;
                
            }

        }
        return c;
    }
};
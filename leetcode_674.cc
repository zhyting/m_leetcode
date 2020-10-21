class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(0 == nums.size() || 1 == nums.size())
        {
            return nums.size();
        }

        int cur = 1;
        int max = 0;
        for(int i = 0;i < nums.size()-1;++i)
        {
            if(nums[i]< nums[i+1])
            {
                cur++;
            }
            else
            {
                if(max < cur)
                {
                    max = cur;
                }
                cur = 1;
            }
        }
        if(max < cur)
        {
            max = cur;
        }
        return max;
    }
};
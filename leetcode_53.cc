class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(0 == nums.size())
        {
            return 0;
        }

        if(1 == nums.size())
        {
            return nums[0];
        }

        int cur = nums[0];
        int max = cur;

        for(int i = 1;i < nums.size();++i)
        {
            if(cur+nums[i] < nums[i])
            {
                cur = nums[i];
            }
            else
            {
                cur += nums[i];
            }
            
            if(max < cur)
            {
                max = cur;
            }
        }
        return max;
    }
};
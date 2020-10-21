
//超时版本
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(0 == nums.size())
        {
            return 0;
        }
        vector<int> sum(nums.size()+1,0);
        int count = 0;

        for(int i = 1;i <= nums.size();++i)
        {
            sum[i] = sum[i-1] + nums[i-1];
        }

        for(int i = 0; i < sum.size();++i)
        {
            for(int j = i+1; j < sum.size();++j)
            {
                if(sum[j] - sum[i] == k)
                {
                    count++;
                }
            }
        }
        return count;
    }
};



class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(0 == nums.size())
        {
            return 0;
        }
        map<int,int> mp;
        mp[0] = 1;
        int sum = 0;
        int count = 0;
        for(int i = 0;i < nums.size();++i)
        {
            sum += nums[i];
            count += mp[sum-k];
            ++mp[sum];
        }
        return count;
    }
};
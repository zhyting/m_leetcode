//效率比较低
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(0 == nums.size())
        {
            return 0;
        }
        sort(nums.begin(),nums.end());
        int len = nums.size();
        return nums[len/2];
    }
};

//改进
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(0 == nums.size())
        {
            return 0;
        }

        int prev = nums[0];
        int ret = prev;
        int count = 1;
        for(int i = 1;i < nums.size();++i)
        {
            if(nums[i]!=prev)
            {
                if(0 == count)
                {
                    prev = nums[i];
                    ret = nums[i];
                }
                else 
                {
                    count--;
                }
            }
            else 
            {
                if(0 == count)
                {
                    ret = nums[i];
                }
                count++;
            }
        }
        return ret;
    }
};
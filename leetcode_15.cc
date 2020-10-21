class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > ret;
        if(nums.size() < 3)
        {
            return ret;
        }

        sort(nums.begin(),nums.end());
        if(nums[0] > 0)
        {
            return ret;
        }

        int i = 0;
        while(i < nums.size())
        {
            if(nums[i]>0)
            {
                break;
            }
            int left = i+1;
            int right = nums.size()-1;
            while(left < right)
            {
                int x = nums[i];
                int y = nums[left];
                int z = nums[right];

                if(x + y > 0-z)
                {
                    right--;
                }
                else if(x + y < 0 - z)
                {
                    left++;
                }
                else
                {
                    ret.push_back({x,y,z});

                    while(left < right && nums[left] == nums[left+1])
                    {
                        left++;
                    }
                    while(left < right && nums[right-1] == nums[right])
                    {
                        right--;
                    }
                    left++;
                    right--;
                }
            
            }
            while(i + 1 < nums.size() && nums[i] == nums[i+1])
            {
                i++;
            }
            i++;
        }
        return ret;
    }
};
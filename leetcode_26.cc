class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(0 == nums.size() || 1 == nums.size())
        {
            return nums.size();
        }

        int cur = 0;
        int next = 0;
        while(next+1 < nums.size())
        {
            if(nums[next] != nums[next+1])
            {
            	if(cur != next)
            	{
            		nums[cur] = nums[next];  //注意 cur++ 不能放置在此处，要放到下面。比如 [1,2] 这种情况。
            	}
                cur++;
            }
            next++;
        }
        nums[cur++] = nums[next];
        
        nums.erase(nums.begin()+cur,nums.end());

        return nums.size();
    }
};
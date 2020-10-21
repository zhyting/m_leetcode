class Solution {
public:
    void permuteCore(vector<int>& nums,vector<vector<int> >& ret,int start)
    {
        if(start == nums.size()-1)
        {
            ret.push_back(nums);
            return;
        }
        for(int i = start;i < nums.size();++i)
        {
            swap(nums[i],nums[start]);
            permuteCore(nums,ret,start+1);
            swap(nums[i],nums[start]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > ret;
        if(0 == nums.size() || 1 == nums.size())
        {
            ret.push_back(nums);
            return ret;
        }
        permuteCore(nums,ret,0);
        return ret;
    }
};
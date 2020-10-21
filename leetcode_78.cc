class Solution {
public:
    void subsetsCore(vector<vector<int> >& ret,vector<int>temp,int start,vector<int>& nums)
    {
        ret.push_back(temp);

        for(int i = start;i < nums.size();++i)
        {
            temp.push_back(nums[i]);
            subsetsCore(ret,temp,i+1,nums);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > ret;
        if(0 ==nums.size())
        {
            return ret;
        }
        vector<int> temp;
        subsetsCore(ret,temp,0,nums);
        return ret;
    }
};
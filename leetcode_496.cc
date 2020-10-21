class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret(nums1.size());
        stack<int> stk;
        map<int,int> m;

        //先使用栈来求解 nums2 的下一个最大值，然后将结果保存在栈中

        for(int i = 0;i < nums2.size();++i)
        {
            if(stk.empty() || nums2[stk.top()] > nums2[i] )
            {
                stk.push(i);
                continue;
            }

            while(!stk.empty() && nums2[stk.top()] < nums2[i])
            {
                int top = stk.top();
                stk.pop();
                m[nums2[top]] = nums2[i];
            }
            stk.push(i);
        }

        while(!stk.empty())
        {
            int top = stk.top();
            stk.pop();
            m[nums2[top]] = -1;
        }

        for(int i = 0;i < nums1.size(); ++i)
        {
            ret[i] = m[nums1[i]];
        }

        return ret;
    }
};
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> stk;
        vector<int> ret(T.size());
        if(T.size() ==0)
        {
            return ret;
        }

        stk.push(0);
        for(int i = 1;i < T.size();++i)
        {
            if(stk.empty())
            {
                stk.push(i);
                continue;
            }

            int top = stk.top();
            if(T[top] >= T[i])
            {
                stk.push(i);
            }
            else
            {
                stk.pop();
                ret[top] = i - top; 
                while(!stk.empty() && T[stk.top()] < T[i])
                {
                    top = stk.top();
                    stk.pop();
                    ret[top] = i - top;
                }
                stk.push(i);
            }
        }
        ret[T.size()-1]=0;
        return ret;
    }
};
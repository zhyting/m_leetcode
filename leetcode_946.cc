class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int idx = 0;
        for(int i = 0;i < pushed.size();++i)
        {
            stk.push(pushed[i]);
            int top = pushed[i];
            while(!stk.empty() && top == popped[idx])
            {
                stk.pop();
                if(!stk.empty())
                    top = stk.top();
                idx++;
            }
        }

        return stk.empty();
    }
};
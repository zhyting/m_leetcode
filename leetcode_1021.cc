class Solution {
public:
    string removeOuterParentheses(string S) {
        string ret="";
        if(0 == S.size())
        {
            return ret;
        }

        stack<char> stk;
        for(int i = 0;i < S.size();++i)
        {
            if(')' == S[i])
            {
                stk.pop();
            }
            if(!stk.empty())
            {
                ret += S[i];
            }
            if('(' == S[i])
            {
                stk.push(S[i]);
            }
        }
        return ret;
    }
};
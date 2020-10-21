class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> stkS;
        stack<char> stkT;
        
        for(int i = 0;i < S.size();++i)
        {
            if(!stkS.empty() &&  '#' == S[i])
            {
                stkS.pop();
            }
            else if('#' != S[i])
            {
                stkS.push(S[i]);
            }
        }

        for(int i = 0;i < T.size();++i)
        {
            if(!stkT.empty() && '#' == T[i])
            {
                stkT.pop();
            }
            else if('#' != T[i])  //注意此处的判断，防止当栈为空时，并且string 中有多个 #，将 # 添加到栈中。
            {
                stkT.push(T[i]);
            }
        }

        while((!stkS.empty()) && (!stkT.empty()))
        {
            char tops = stkS.top();
            stkS.pop(); 
            char topt = stkT.top();
            stkT.pop();
            if(tops != topt)
            {
                return false;
            }
        }
        return (stkS.empty() && stkT.empty());
    }
};
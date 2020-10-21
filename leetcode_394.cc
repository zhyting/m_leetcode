//第一次写的代码，无法通过 
class Solution {
public:
    string decodeString(string s) {
        if(0 == s.size())
        {
            return 0;
        }

        string ret("");
        stack<char> stk;

        for(int i = 0;i < stk.size();++i)
        {
            if(s[i] != ']' || stk.empty())
            {
                stk.push(s[i]);
            }
            else 
            {
                string temp("");
                //while(!stk.empty() && (!isdigit(stk.top())))
                while(!stk.empty() && stk.top() != '[')
                {
                    char top = stk.top();
                    stk.pop();
                    temp += top;
                }
                stk.pop();
                reverse(temp.begin(),temp.end());

                temp = temp + ret;
                
                if(isdigit(stk.top()))
                {
                    string dup("");
                    int times = (stk.top() - '0');
                    stk.pop();
                    while((times--) > 0)
                    {
                        dup += temp;
                    }
                    temp  = dup;
                }
                
                ret = temp;
            }
        }
        return ret;
    }
};





//参考别人写的代码
class Solution {
public:
    string decodeString(string s) {
        string ret("");
        if(0 == s.size())
        {
            return ret;
        }

        stack<int> numstack;
        stack<string> strstack;
        string cur("");
        int num = 0;

        for(int i = 0;i < s.size();++i)
        {
            if(s[i] >= '0' && s[i] <= '9')
            {
                num = num*10 + (s[i]-'0');
            }
            else if('[' == s[i])
            {
                numstack.push(num);
                strstack.push(cur);
                cur = "";
                num = 0;
            }
            else if(']' == s[i])
            {
                int times = numstack.top();
                numstack.pop();
                while((times--) > 0)
                {
                    strstack.top() += cur;
                }
                cur = strstack.top();
                strstack.pop();
            }
            else
            {
                cur += s[i];
            }
        }
        ret = ret + cur;
        return ret;
    }
};
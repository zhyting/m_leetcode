class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        /*
        g --> children;
        s --> cookie;
        */
        int count = 0;
        if(0 == g.size() || 0 == s.size())
        {
            return count;
        }

        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int flag = false;

        for(std::vector<int>::iterator it_g = g.begin(); it_g != g.end();++it_g)
        {
            flag = false;
            for(std::vector<int>::iterator it_s = s.begin(); it_s != s.end();++it_s)
            {
                if(*it_s >= *it_g)
                {
                    flag = true;
                    count++;
                    s.erase(it_s,it_s+1);
                    break;
                }
            }
            if(!flag)
            {
                break;
            }
        }
        return count;
    }
};




/*
    执行效率会有所提高
*/
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        /*
        g --> children;
        s --> cookie;
        */
        if(0 == g.size() || 0 == s.size())
        {
            return 0;
        }

        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        
        int g_index = 0,s_index = 0;
        while(g_index < g.size() && s_index < s.size())
        {
            if(s[s_index]>=g[g_index])
            {
                s_index++;
                g_index++;
            }
            else 
            {
                s_index++;
            }
        }

        return g_index;
    }
};
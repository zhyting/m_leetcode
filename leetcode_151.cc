class Solution {
public:
    string reverseWords(string s) {
        if(0 == s.size())
        {
            return s;
        }

        string str;
        int i = 0;
        while(i < s.size() && s[i] == ' ')
        {
            i++;
        }

        while(i < s.size())
        {
            if(s[i]!= ' ')
            {
                str+=s[i++];
            }
            else 
            {
                int start = i;
                while(i < s.size() && s[i] == ' ')
                {
                    i++;
                }
                if(i != s.size())
                {
                    str += ' ';
                }
            }
        }

        reverse(str.begin(),str.end());
        int start = 0;
        int end = 0;
        
        while(end < str.size())
        {
            if(str[end] != ' ')
            {
                end++;
            }
            else
            {
                reverse(str.begin()+start,str.begin()+end);
                end++;
                start = end;
            }
        }

        if(start != end)
        {
            reverse(str.begin()+start,str.begin()+end);
        }

        
        return str;
    }
};




/*
    看到有人使用stringstream 来做，stringstream 不是很熟悉
*/
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss;
        string ans="",temp;
        ss<<s;
        while(ss>>temp){
            ans=" "+temp+ans;
        }
        if(ans!="")
            ans.erase(ans.begin());
        return ans; 
    }
};
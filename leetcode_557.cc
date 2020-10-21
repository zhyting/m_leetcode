class Solution {
public:
    string reverseWords(string s) {
        if(0 == s.size())
        {
            return s;
        }

        int start = 0;
        int end = 0;

        while(end < s.length())
        {
            if(s[end] == ' ')
            {
                reverse(s.begin()+start,s.begin()+end);
                end++;
                start = end;
            }
            else
            {
                end++;
            }
        }

        if(start != end)
        {
            reverse(s.begin()+start,s.begin()+end);
        }
        return s;
    }
};
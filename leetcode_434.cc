class Solution {
public:
    int countSegments(string s) {
        if(0 == s.size())
        {
            return 0;
        }

        int count = 0;
        int next = 0;
        while(next < s.size())
        {
            if(s[next] != ' ' && next+1 < s.size() && ' ' == s[next+1])
            {
                count++;
            }
            next++;
        }
        
        return (s[next-1] != ' ' ? ++count : count);
    }
};
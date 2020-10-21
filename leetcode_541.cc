class Solution {
public:
    string reverseStr(string s, int k) {
        if(0 == s.length() || k <=0)
        {
            return s;
        }

        int idx = 0;
        int i = 1;
        while(idx < s.length())
        {
            if(idx+k > s.length())
            {
                reverse(s.begin()+idx,s.end());
            }
            else 
            {
                reverse(s.begin()+idx,s.begin()+idx+k);
            }
            idx = i*2*k;
            i++;
        }
        return s;
    }
};
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(0 == s.size() && 0 == t.size())
        {
            return true;
        }
        if(0 == t.size())
        {
            return false;
        }

        int idxs = 0;
        int idxt = 0;

        while(idxs < s.size() && idxt < t.size())
        {
            if(s[idxs] == t[idxt])
            {
                idxt++;
                idxs++;
            }
            else 
            {
                idxt++;
            }
        }
        return idxs == s.size() ? true  : false;
    }
};
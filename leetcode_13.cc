class Solution {
public:
    int romanToInt(string s) {
        if(0 == s.size())
        {
            return 0;
        }

        int ret = 0;
        map<string,int> mp{
            {"I",1},
            {"V",5},
            {"X",10},
            {"L",50},
            {"C",100},
            {"D",500},
            {"M",1000},
            {"IV",4},
            {"IX",9},
            {"XL",40},
            {"XC",90},
            {"CD",400},
            {"CM",900}
        };

        int idx = 0;
        int val = 0;
        while(idx < s.size())
        {
            string temp("");
            string t("");
            temp += s[idx];
            if(idx+1 < s.size())
            {
                t+=temp;
                t+=s[idx+1];
            }
            map<string,int>::iterator find = mp.find(t);
            if(find != mp.end())
            {
                val += mp[t];
                idx+=2;
            }
            else 
            {
                val += mp[temp];
                idx++;
            }
        }
        return val;
    }
};
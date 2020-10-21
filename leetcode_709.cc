class Solution {
public:
    string toLowerCase(string str) {
        if(0 == str.size())
        {
            return str;
        }
        for(int i = 0;i < str.size();++i)
        {
            if(str[i] >= 'A' && str[i] <= 'Z')
            {
                str[i] = str[i]+32;
            }
        }
        return str;
    }
};
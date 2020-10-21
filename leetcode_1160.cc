class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        if(0 == words.size() || "" == chars)
        {
            return 0;
        }
        int hashtable[26]={0};
        int count = 0;
        for(int i = 0;i < chars.length();++i)
        {
            hashtable[chars[i]-'a']++;
        }

        for(int i = 0;i < words.size();++i)
        {
            int hash[26]={0};
            string str = words[i];
            for(int i = 0;i < str.length();++i)
            {
                hash[str[i]-'a']++;
            }

            bool has = false;
            for(int i = 0;i < 26;++i)
            {
                if(hash[i] > hashtable[i])
                {
                    has = true;
                }
            }
            
            if(!has)
            {
                count += str.length();
            }
        }
        return count;
    }
};
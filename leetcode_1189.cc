class Solution {
public:
    int maxNumberOfBalloons(string text) {
        if(0 == text.size())
        {
            return 0;
        }
        
        map<char,int> mp ={
            {'a',0},
            {'b',0},
            {'l',0},
            {'o',0},
            {'n',0}
        };
        for(int i = 0; i < text.size();++i)
        {
            if(text[i] == 'a')
            {
                mp['a']++;
            }
            else if('b' == text[i])
            {
                mp['b']++;
            }
            else if('l' == text[i])
            {
                mp['l']++;
            }
            else if('o' == text[i])
            {
                mp['o']++;
            }
            else if('n' == text[i])
            {
                mp['n']++;
            }
        }

        int min=0x7fffffff;
        for(std::map<char,int>::iterator it = mp.begin(); it != mp.end();++it)
        {
            if('l' == it->first || 'o' == it->first)
            {
                (it->second)/2 > min ? min = min : min = (it->second)/2;
            }
            else
            {
                it->second > min ? min = min : min = it->second;
            }
            
        }
        return min;
    }
};
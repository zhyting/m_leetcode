class Solution {
public:
    int findLUSlength(string a, string b) {
        if(0 == a.size() || 0 == b.size())
        {
            return 0;
        }
        
        if(a.size() != b.size())
        {
            return a.size() > b.size() ? a.size() : b.size();
        }
        

        int max = -1;

        for(int i = 0;i < a.size();++i)
        {
            string temp(a.begin()+i,a.end());
            std::size_t found = b.find(temp);
            if(found == std::string::npos)
            {
                max = temp.size();
                break;
            }
        }
        return max;
    }
};
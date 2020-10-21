class Solution {
public:
    string countAndSay(int n) {
        string str("");
        if(n <= 0)
        {
            return str;
        }

        str += "1";
        
        int i = 2;
        while((i++) <= n)
        {
            int start = 0;
            int end = 0;
            string temp("");
            while(end < str.size())
            {
                int count = 1;
                while(end + 1 < str.size() && str[end+1] == str[end])
                {
                    end++;
                    count++;
                }
                temp += to_string(count);
                temp += str[start];
                end++;
                start = end;
            }
            str.clear();
            str = temp;
        }

        return str;
    }
};
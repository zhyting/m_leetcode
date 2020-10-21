class Solution {
public:
    int myAtoi(string str) {
        if(0 == str.size())
        {
            return 0;
        }
        long long ret=0;
        int flag = 1;
        int idx = 0;
        while(idx < str.size() && str[idx] == ' ')
        {
            idx++;
        }
        
        if( '+' == str[idx] || '-' == str[idx])
        {
            if('-'== str[idx])
            {
                flag = -1;
            }
            idx++;
        }
        if(str[idx] < '0' || str[idx] > '9')
        {
            return 0;
        }

        while(idx < str.size() && str[idx] >= '0' && str[idx] <= '9')
        {
            ret = ret * 10 + (str[idx] - '0');
            if(flag==1 && ret > 2147483647)
            {
                return INT_MAX;
            }
            else if(flag == -1 && ret > 2147483648)
            {
                return INT_MIN;
            }
            idx++;
        }

        ret = ret * flag;
        
        return ret;
    }
};
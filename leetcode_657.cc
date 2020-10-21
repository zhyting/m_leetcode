class Solution {
public:
    bool judgeCircle(string moves) {    
        if(0 == moves.size())
        {
            return true;
        }

        int i = 0;
        int j = 0;
        for(int m = 0;m < moves.size();++m)
        {
            char ch = moves[m];
            switch(ch)
            {
                case 'R':
                    j++;
                    break;
                case 'L':
                    j--;
                    break;
                case 'U':
                    i--;
                    break;
                case 'D':
                    i++;
                    break;
            }
        }

        return (0 == i && 0 == j);
    }
};
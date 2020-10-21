class Solution {
public:
    string intToRoman(int num) {
        string str = "";
        if(0 == num)
        {
            return str;
        }
        
        int ret = 0;
        vector<int> val{1000,900,500,400,100,90,50,40,10,9,5,4,1};

        vector<string> vecstr{"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        for(int i = 0;i < val.size();++i)
        {
            while(num >= val[i])
            {
                num -= val[i];
                str += vecstr[i];
            }
        }

        return str;
        
    }
}; 
            
            
            
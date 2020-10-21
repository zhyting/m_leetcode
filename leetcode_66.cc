class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ret;
        if(0== digits.size())
        {
            return ret;
        }

        int carry = (digits[digits.size()-1] + 1)/10;
        digits[digits.size()-1] = (digits[digits.size()-1] + 1) % 10;

        for(int i = digits.size()-2; i >= 0;--i)
        {
            digits[i] = digits[i] + carry;
            carry = digits[i] / 10;
            digits[i] = digits[i] % 10;
            if(0 == carry)
            {
                break;
            }
        }

        if(carry != 0)
        {
            ret.push_back(1); 
        }    
        for(int i = 0;i < digits.size();++i)
        {
            ret.push_back(digits[i]);
        } 
        
        return ret;
    }
};
class Solution {
public:
    string addStrings(string num1, string num2) {
        string str=""; 
        if(0 == num1.size() && 0 == num2.size())
        {
            return str;
        }

        int carry = 0;
        int len1 = num1.size()-1;
        int len2 = num2.size()-1;
        int sum;

        while(len1 >= 0 && len2 >= 0)
        {
            sum = (num1[len1--] - '0') + (num2[len2--] - '0') + carry;
            carry = sum / 10;
            sum = sum % 10;
            str += (sum + '0');
        }

        while(len1 >= 0)
        {
            sum = (num1[len1--] - '0') + carry;
            carry = sum / 10;
            sum = sum % 10;
            str += (sum + '0');
        }

        while(len2 >= 0)
        {
            sum = (num2[len2--] - '0') + carry;
            carry = sum / 10;
            sum = sum % 10;
            str += (sum + '0');
        }

        if(carry != 0)
        {
            str += (1 + '0');
        }

        reverse(str.begin(),str.end());
        return str;
    }
};
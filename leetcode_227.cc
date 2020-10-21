class Solution {
public:
    int calculate(string s) {
stack<int> nums;
        stack<char> symbol;


        for(int i = 0;i < s.size();++i)
        {
            if('+' == s[i] || '-' == s[i] || '*' == s[i] || '/' == s[i])
            {
                symbol.push(s[i]);
            }
            else if(isdigit(s[i]))
            {
                int temp = 0;
                while(i < s.size() && isdigit(s[i]))
                {
                    temp = temp*10 + (s[i++]-'0');
                }
                i--;
                if(symbol.empty())
                {
                    nums.push(temp);
                }
                else 
                {
                    if(symbol.top() == '*')
                    {
                        symbol.pop();
                        nums.top() = nums.top() * temp;

                    }
                    else if(symbol.top() == '/')
                    {
                        symbol.pop();
                        nums.top() = nums.top() / temp; 

                    }
                    else if(symbol.top() == '+' || symbol.top() == '-')
                    {
                        nums.push(temp); 
                    }
                    else
                    {
                        nums.push(temp);
                    }
                } 
            }
        }

        stack<int> nums_temp;
        stack<char> symbol_temp;

        while(!nums.empty())
        {
            nums_temp.push(nums.top());
            nums.pop();
        }

        while(!symbol.empty())
        {
            symbol_temp.push(symbol.top());
            symbol.pop();
        }

        while(!symbol_temp.empty())
        {
            char ch = symbol_temp.top();
            symbol_temp.pop();
            int num1 = nums_temp.top();
            nums_temp.pop();
            int num2 = nums_temp.top();
            nums_temp.pop();
            if('+' == ch)
            {
                nums_temp.push(num1 + num2);
            }
            else if('-' == ch)
            {
                nums_temp.push(num1 - num2);  //注意这里不能再使用 num2 -num1 
            }
        }


        return nums_temp.top();
    }
};




//还有一种是使用双端队列去做
class Solution {
public:
    int calculate(string s) {
        deque<char> sign;
        deque<int> nums;
        int i = 0, s_len = s.size();
        int nums_top2, nums_top1; char sign_top;
        while(i < s_len){
            if(s[i] == '*' || s[i] == '/' 
            || s[i] == '+' || s[i] == '-') sign.push_back(s[i]);
            else if(isdigit(s[i])){
                int temp = 0;
                while(i < s_len && isdigit(s[i])) temp = temp * 10 + (s[i++]-'0');
                i--;
                if(!sign.empty() && (sign.back() == '*' || sign.back() == '/')){
                    nums_top2 = nums.back(); nums.pop_back();
                    sign_top = sign.back(); sign.pop_back();
                    if(sign_top == '*') nums.push_back(nums_top2 * temp);
                    else if(sign_top == '/') nums.push_back(nums_top2 / temp);
                }
                else nums.push_back(temp);
            }
            i++;
        }
        while(!sign.empty()){
            nums_top1 = nums.front(); nums.pop_front();
            nums_top2 = nums.front(); nums.pop_front();
            sign_top = sign.front(); sign.pop_front();
            if(sign_top == '+') nums.push_front(nums_top1 + nums_top2);
            else if(sign_top == '-') nums.push_front(nums_top1 - nums_top2);
        }
        return nums.front();
    }
};
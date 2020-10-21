class Solution {
public:
    int calculate(string s) {
        stack<int> nums;
        stack<char> symbol;

        for(int i = 0;i < s.size();++i)
        {
            if('(' == s[i] || '+' == s[i] || '-' == s[i])
            {
                symbol.push(s[i]);
            }
            else if(isdigit(s[i]))
            {
                int temp = 0;
                while(i < s.size() && isdigit(s[i]))
                {
                    temp = temp*10 + (s[i++] - '0');
                }
                i--;
                /*
                1> 取出nums symbol 栈顶的元素，计算后进行压栈操作
                2> 对temp 直接压栈操作
                */
                if(symbol.empty() || symbol.top() == '(')
                {
                    nums.push(temp);
                }
                else 
                {
                    int top = nums.top();
                    nums.pop();
                    char ch = symbol.top();
                    symbol.pop();
                    if('+' == ch)
                    {
                        nums.push(top + temp);
                    }
                    else if('-' == ch)
                    {
                        nums.push(top - temp);
                    }
                }
            }
            else if(')' == s[i])
            {
                /*
                    刚开始以为，此种情况只需要 symbol.pop() 即可，其实不然。比如计算如下的这种情况
                    1+(1+2+3)
                    当遇到 )时，括号中的内容已经计算完成，此时将"("弹出,但是此时一方面已经到了string的末尾，
                    另外一方面，符号栈中还有 '+',而数字栈中还有 数字1,也就是还有数据没有计算完成。 
                    (1+2+3) 可以看出一个数，也就是 1+num,而且1 num 都在栈中，此时需要查看符号栈中是否还有运算符号。
                */

                symbol.pop();
                if(!symbol.empty() && symbol.top() != '(')
                {
                    int num1 = nums.top();
                    nums.pop();
                    int num2 = nums.top();
                    nums.pop();
                    int ch = symbol.top();
                    symbol.pop();
                    if('+' == ch)
                    {
                        nums.push(num1 + num2);
                    }
                    else if('-' == ch)
                    {
                        nums.push(num2 - num1);
                    }
                }
            }
        }
        return nums.top();
    }
};
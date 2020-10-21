class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int num1,num2;
        
        for(string str : tokens)
        {
            char ch = str[0];
            if(ch == '-' && str.length() > 1)
            {
                ch = str[1];
            }
            int temp = 0;
            switch(ch)
            {
                case '+':
                    num1 = stk.top();
                    stk.pop();
                    num2 = stk.top();
                    stk.pop();
                    temp = num1 + num2;
                    stk.push(temp);
                    break;
                case '-':
                    num1 = stk.top();
                    stk.pop();
                    num2 = stk.top();
                    stk.pop();
                    temp = num2 - num1;
                    stk.push(temp);
                    break;
                case '*':
                    num1= stk.top();
                    stk.pop();
                    num2 = stk.top();
                    stk.pop();
                    temp = num1 * num2;
                    stk.push(temp);
                    break;
                case '/':
                    num1 = stk.top();
                    stk.pop();
                    num2 = stk.top();
                    stk.pop();
                    temp = num2 / num1;
                    stk.push(temp);
                    break;
                default:
                    stk.push(atoi(str.c_str()));
                    break;
            }
        }
        return stk.top();
    }
};
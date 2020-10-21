class Solution {
public:
    /*
        sum 总的符号个数
        half 可用于配对的 ( 的个数
        n 剩余 ( 个数
    */
    void generateParenthesisCore(vector<string>& vecstr,string str,int sum,int half,int n)
    {
        if(0 == sum)
        {
            vecstr.push_back(str);
            return ;
        }

        sum--;
        if(half > 0) 
        {
            generateParenthesisCore(vecstr,str+")",sum,half-1,n);
        }
        if(n > 0)
        {
            generateParenthesisCore(vecstr,str+"(",sum,half+1,n-1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> vecstr;
        if(n <= 0)
        {
            return vecstr;
        }
        string str;
        generateParenthesisCore(vecstr,str,2*n,0,n);
        return vecstr;
    }
};
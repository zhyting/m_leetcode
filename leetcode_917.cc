class Solution {
public:
    string reverseOnlyLetters(string S) {
        if(0 == S.size())
        {
            return S;
        }
        int begin = 0;
        int end = S.size()-1;

        while(begin < end)
        {
            //同时为字符
            if(isalpha(S[begin]) && isalpha(S[end]))
            {
                swap(S[begin],S[end]);
                begin++;
                end--;
            }
            else if(!isalpha(S[begin]))
            {
                begin++;
            }
            else if(!isalpha(S[end]))
            {
                end--;
            }
        }
        return S;
    }

};
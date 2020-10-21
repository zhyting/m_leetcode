/*
    第一次的代码/思路
*/
/*
class Solution {
public:
    void letterCasePermutationCore(vector<string>& ret,string str,int start)
    {
        if(start >= str.length())
        {
            ret.push_back(str);
        }

        for(int i = start;i < str.length();++i)
        {
            if(isdigit(str[i]))
            {
                letterCasePermutationCore(ret,str,start+1);
            }
            else
            {
                char orig = str[start];
                char upper = toupper(str[start]);
                str[start] = upper;
                letterCasePermutationCore(ret,str,start+1);    
                char lower = tolower(str[start]);
                str[start] = lower;
                letterCasePermutationCore(ret,str,start+1); 
                str[start] = orig;
            }
        }
    }
    vector<string> letterCasePermutation(string S) {
        vector<string> ret;
        if(S.length() == 0)
        {
            return ret;
        }

        letterCasePermutationCore(ret,S,0);
        return ret;
    }
};
*/


/*
    提交的代码
*/
class Solution {
public:
    void letterCasePermutationCore(vector<string>& ret,string str,int start)
    {
        if(start >= str.length())
        {
            ret.push_back(str);
            return;
        }
    
        if(isdigit(str[start]))
        {
            letterCasePermutationCore(ret,str,start+1);
        }
        else
        {
            char upper = toupper(str[start]);
            str[start] = upper;
            letterCasePermutationCore(ret,str,start+1);    
            char lower = tolower(str[start]);
            str[start] = lower;
            letterCasePermutationCore(ret,str,start+1);     
        }
    }
    vector<string> letterCasePermutation(string S) {
        vector<string> ret;
        if(S.length() == 0)
        {
            return ret;
        }

        letterCasePermutationCore(ret,S,0);
        return ret;
    }
};


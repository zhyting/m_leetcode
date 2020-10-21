class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int> > ret;
        if(0 == intervals.size())
        {
            return ret;
        }

        sort(intervals.begin(),intervals.end());

        int i = 0;
        while(i < intervals.size())
        {
            int begin = intervals[i][0];
            int end = intervals[i][1];

            int j = i;
            while(j < intervals.size())
            {
                if(j+1 < intervals.size() && (intervals[j+1][0] >= begin && intervals[j+1][0] <= end))
                {
                    if(end < intervals[j+1][1])
                    {
                        end = intervals[j+1][1];
                    }
                    j++;
                }
                else 
                {
                    break;
                }
            }
            i = j+1;
            vector<int> temp;
            temp.push_back(begin);
            temp.push_back(end);
            ret.push_back(temp);
        }
        return ret;
    }
};
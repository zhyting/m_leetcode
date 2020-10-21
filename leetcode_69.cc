//还是有溢出的风险
class Solution {
public:
    int mySqrt(int x) {
        if(0 == x || 1 == x)
        {
            return x;
        }

        int start = 1;
        int end = x / 2;
        while(start <= end)
        {
            long long mid = start + ((end-start)>>1);
            if(mid*mid <= x && ((mid+1)*(mid+1)) > x)
            {
                return mid;
            }
            else if(mid * mid > x)
            {
                end = mid -1;
            }
            else
            {
                start = mid+1;
            }
        }
        return -1;
    }
};



class Solution {
public:
    int mySqrt(int x) {
        if(0 == x || 1 == x)
        {
            return x;
        }

        int start = 0;
        int end = x;

        while(start+1 < end)
        {
            int mid = start + ((end-start)>>1);
            if(x / mid >= mid)
            {
                start = mid;
            }
            else
            {
                end = mid;
            }
        }
        return start;
    }
};
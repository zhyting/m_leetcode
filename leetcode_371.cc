class Solution {
public:
    int getSum(int a, int b) {
        do
        {
            int carry =  (unsigned int)(a & b) << 1;   //注意此处需要添加 (unsigned int) 主要针对负数，否则会出现溢出的问题。
            int sum = a ^ b;

            a = sum;
            b = carry;
        }while(b != 0);
        return a;
    }
};
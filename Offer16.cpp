题目：实现函数double Power(double base, int exponent)，求base的exponent次方。不得使用库函数，同时不需要考虑大数问题。


class Solution {
public:
    //题解：快速幂
    double myPow(double x, int n) {
        double res=1.0;
        int i=n;
        while(i){
            if(i&1)res*=x;  //i的低位存在，res*x      用于判断n为奇数还是偶数
            x*=x;           //x扩大为它的平方，因为二进制每位的差距是平方关系
            i/=2;           //i向0靠近
        }
        return n<0?1/res:res;
    }
};

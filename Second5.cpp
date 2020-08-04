题目：一条包含字母 A-Z 的消息通过以下方式进行了编码：
      'A' -> 1
      'B' -> 2
      ...
      'Z' -> 26
给定一个只包含数字的非空字符串，请计算解码方法的总数。

解法：若s[i]='0'，则
        若s[i-1]='1'或‘2’，则dp[i]=dp[i-2]
        否则不存在，无解
      若s[i]='1'则dp[i]=dp[i-1]+dp[i-2]
      若s[i-1]='2'，并且s[i]在1~6之间，则同上dp[i]=dp[i-1]+dp[i-2]

class Solution {
public:
    int numDecodings(string s) 
    {
        if (s[0] == '0') 
    	return 0;
        int pre = 1, curr = 1;//初始化
    
        for (int i = 1; i < s.size(); i++) 
        {
            int tmp = curr;
            if (s[i] == '0')
            {
                if (s[i - 1] == '1' || s[i - 1] == '2') 
                    curr = pre;
                else return 0;
            }
            else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6'))//十几到26之间
            { 
                curr = curr + pre;
            }
            pre = tmp;
        }
        return curr;
    }
};

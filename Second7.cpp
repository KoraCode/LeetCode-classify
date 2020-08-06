题目：给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。

解法：dp[i]=dp[j] && check(s[j..i−1]) 增加的字符有相匹配的单词且切割后的长度也存在相匹配的单词

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set <string> wordDictSet;
        int minSize = INT_MAX, maxSize = 0;
        for (auto word: wordDict) {
            wordDictSet.insert(word);
            if(word.size() < minSize) minSize = word.size();
            if(word.size() > maxSize) maxSize = word.size();
        }
        
        vector <bool> dp(s.size() + 1);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = max(i - maxSize, 0); i - j >= minSize; ++j) {      //由于已经知道dp[i-1]的情况，多增加的i字符就是从这开始向前找相匹配的单词，但是单词最长就maxsize所以找的是
                                                                            //[i-maxsize,i]即可,而且i-j的单词长度要比最小的单词大。
                if (dp[j] && wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end()) {   //状态转移方程的调用
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp.back();
    }
};  

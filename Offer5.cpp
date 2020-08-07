题目：请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

解法：由于替换的字符串比空字符串要多2个字符，所以要移动字符；

class Solution {
public:
    string replaceSpace(string s) {
        int len1=s.length()-1;
        for(int i=0;i<=len1;i++){
            if(s[i]==' ')
            {
                s+="00";
            }
        }
        int len2=s.length()-1;
        if(len2<=len1){
            return s;
        }
        for(int i=len1;i>=0;i--){
            char c=s[i];
            if(c==' '){
                s[len2--]='0';
                s[len2--]='2';
                s[len2--]='%';
            }
            else{
                s[len2--]=c;
            }
        }
        return s;
    }
};

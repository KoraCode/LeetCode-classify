题目：你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。

解法：dp[i]=max(dp[i-2]+nums[i],dp[i-1])

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int size = nums.size();
        if (size == 1) {
            return nums[0];
        }
        int first = nums[0], second = max(nums[0], nums[1]);
        for (int i = 2; i < size; i++) {
            int temp = second;
            second = max(first + nums[i], second);
            first = temp;
        }
        return second;
    }
};


//房屋变成环形，分两种情况一种是偷第一间就不偷最后一间[0，i-1]，另外一种是偷最后一间就不偷第一间[1，i]；
class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int length=nums.size();
        if(length==0) return 0;
        if(length==1) return nums[0];

        int first=nums[0];
        int second=max(nums[0],nums[1]);
        for(int i=2;i<length-1;i++)
        {
            int tmp=second;
            second=max(first+nums[i],second);
            first=tmp;
        }
        int result=second;
        first=0;second=nums[1];
        for(int i=2;i<length;i++)
        {
            int tmp=second;
            second=max(first+nums[i],second);
            first=tmp;
        }
        int ans=second;
        result=max(result,ans);
        return result;
    }
};

题目：给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

解法：[状态]是最大和 跟 可选择数，[选择]是添加数 和 不添加数。
dp数组：用 f(i)f(i) 代表以第 ii 个数结尾的「连续子数组的最大和」： max(f(i)),选择就是 max(f(i-1)+ai,ai)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0, maxAns = nums[0];
        for (const auto &x: nums) {
            pre = max(pre + x, x);
            maxAns = max(maxAns, pre);
        }
        return maxAns;
    }
};

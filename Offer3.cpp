题目：找出数组中重复的数字。
在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

解法：交换法；重排遍历法；哈希法

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(i != nums[i])
            {
                if(nums[i] == nums[nums[i]])
                    return nums[i];
                else
                    swap(nums[i],nums[nums[i]]);
            }
        }

        return -1;
    }
};
//重排序遍历
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();++i)
        {
            if(nums[i]==nums[i-1])
            {
                return nums[i];
            }
        }

        return -1;
    }
};
//哈希
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int, int> map;
        for(int i : nums) 
            if(map[i] ++ == 1) return i;
        return -1;
    }
};

```cpp
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int zero = 0;
        int lenth = 0;
        //进窗口
        for (right; right < nums.size(); ++right)
        {
            //判断
            if (nums[right] == 0)
            {
                ++zero;
            }
            //更新结果
            if (zero > k)
            {
                lenth = max(lenth, right - left);
                while (nums[left] != 0)
                {
                    ++left;
                }
                ++left;
                --zero;
            }
        }
        lenth = max(lenth, right - left);//最后都是1
        if (zero < k)//当翻转的0个数小于k时，循环不会进去
        {
            lenth = max(lenth, (int)nums.size());
        }
        return lenth;
    }
};
```

[1004. 最大连续1的个数 III - 力扣（LeetCode）](https://leetcode.cn/problems/max-consecutive-ones-iii/)
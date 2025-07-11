```cpp
class Solution {
public:
    int mySqrt(int x) {
        if (x < 1) return 0;
        int ret;
        int left = 1, right = x;
        while (left < right)
        {
            int mid = left + (right - left + 1) / 2;
            if (mid <= x / mid) left = mid;//防止溢出
            else right = mid - 1;
        }
        return left;
    }
};
```

[69. x 的平方根 - 力扣（LeetCode）](https://leetcode.cn/problems/sqrtx/)
[560. 和为 K 的子数组 - 力扣（LeetCode）](https://leetcode.cn/problems/subarray-sum-equals-k/)

```c++
#include<unordered_map>
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //1. 创建hash表
        unordered_map<int, int> hash;
        //2. 初始hash表
        hash[0] = 1;//处理sum - k 等于0时的情况
        int sum = 0, ret = 0;
        for (auto x : nums)
        {
            sum += x;
            if (hash.count(sum - k)) ret += hash[sum - k];
            hash[sum]++;
        }
        return ret;
    }
};
```


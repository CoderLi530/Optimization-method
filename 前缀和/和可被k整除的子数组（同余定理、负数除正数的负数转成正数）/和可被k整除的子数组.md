```c++
#include<unordered_map>
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        //1. 创建哈希表
        unordered_map<int, int> hash;
        int sum = 0, ret = 0;
        hash[0 % k] = 1;//处理边界问题
        for (auto x : nums)
        {
            sum += x;
            if (hash.count((sum % k + k) % k))
                ret += hash[(sum % k + k) % k];
            hash[(sum % k + k) % k]++;
        }
        return ret;
    }
};
```

[974. 和可被 K 整除的子数组 - 力扣（LeetCode）](https://leetcode.cn/problems/subarray-sums-divisible-by-k/)
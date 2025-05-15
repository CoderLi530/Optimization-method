[存在重复元素II]: https://leetcode.cn/problems/contains-duplicate-ii/



```c++
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        //只有一个元素返回false
        if (nums.size() == 1) return false;

        //创建哈希表
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); ++i)
        {
            //找到了下标相减与k比较
            if (hash.count(nums[i]) && i - hash[nums[i]] <= k) return true;
            hash[nums[i]] = i;
        }        
        //遍历结束说明没找到
        return false;
    }
};
```


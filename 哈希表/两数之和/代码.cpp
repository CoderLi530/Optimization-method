class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hash;
        for (int i = 0; i < nums.size(); ++i)
        {
            //可以找到就返回
            if (hash.count(target - nums[i])) return {hash[target - nums[i]], i};
            //没找到，进行插入操作
            hash[nums[i]] = i;
        }
        //为了照顾编译器
        return {-1, -1};
    }
};
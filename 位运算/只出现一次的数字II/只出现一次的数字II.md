[只出现一次的数字II]: https://leetcode.cn/problems/WGki4K/



```c++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;//返回出现一次的元素
        for (int i = 0; i < 32; ++i)//32个比特位，循环32次
        {
            //求出数组中每个比特位之和
            int sum = 0;//某个比特位上的数之和
            for (int& e : nums)//遍历这个数组
            {
                if ((e >> i) & 1)//这个位为1就加到sum中去，不为0不用加
                {
                    ++sum;
                }
            }
            //得出了某个比特位的sum，求出出现一次的元素的某个比特位
            if (sum % 3 == 1)//为1代表出现一次的元素的那个比特位为1
            {
                ret |= 1 << i;
            }
        }
        return ret;
    }
};
```


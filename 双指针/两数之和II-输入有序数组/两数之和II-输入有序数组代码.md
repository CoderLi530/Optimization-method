```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> answer;//接收两个下标
        int left = 0;
        int right = numbers.size() - 1;
        while (left < right)
        {
            if (numbers[left] + numbers[right] > target)
            {
                --right;
            }
            else if (numbers[left] + numbers[right] < target)
            {
                ++left;
            }
            else
            {
                answer.push_back(left);
                answer.push_back(right);
                break;//相等就跳出循环，否则就会一直走下去
            }
            
        }
        return answer;  
    }
};
```

[LCR 006. 两数之和 II - 输入有序数组 - 力扣（LeetCode）](https://leetcode.cn/problems/kLl5u1/)
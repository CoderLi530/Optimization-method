[数组中的第K个最大元素]: https://leetcode.cn/problems/kth-largest-element-in-an-array/



```c++
class Solution 
{
public:
        int quick_sort(vector<int>& nums, int left, int right, int k)
    {
        if (left == right) return nums[left];
        //计算出基准元素key
        int key = nums[rand() % (right - left + 1) + left];
        //数组分成三块
        int i = left, l = left - 1, r = right + 1;
        while (i < r)
        {
            if (nums[i] < key) swap(nums[++l], nums[i++]);
            else if (nums[i] == key) ++i;
            else swap(nums[--r], nums[i]);
        }
        //判断第k大在哪个区间中
        int greater_count = right - r + 1;
        int equal_count = r - 1 - l;
        if (greater_count >= k) return quick_sort(nums, r, right, k);
        else if (greater_count + equal_count >= k) return key;
        else return quick_sort(nums, left, l, k - greater_count - equal_count);
    }
    int findKthLargest(vector<int>& nums, int k) 
    {
        srand(time(NULL));
        return quick_sort(nums, 0, nums.size() - 1, k);
    }
};
```


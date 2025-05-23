[排序数组]: https://leetcode.cn/problems/sort-an-array/



分治-归并

```c++
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // 归并排序
        mergesort(nums, 0, nums.size() - 1);
        return nums;
    }

    void mergesort(vector<int>& nums, int left, int right)
    {
        if (left >= right) return;
        // 进行分割数组
        int mid = (left + right) / 2;
        // 进行排序
        mergesort(nums, left, mid);
        mergesort(nums, mid + 1, right);
        //进行合并
        vector<int> tmp(right - left + 1);
        int i = 0;
        int left1 = left, left2 = mid + 1;
        while (left1 <= mid && left2 <= right)
        {
            if (nums[left1] > nums[left2]) tmp[i++] = nums[left2++];
            else tmp[i++] = nums[left1++];
        } 
        //合并未遍历的数组
        while (left1 <= mid) tmp[i++] = nums[left1++];
        while (left2 <= right) tmp[i++] = nums[left2++];
        //进行替换元素
        for (int i = left; i <= right; ++i) nums[i] = tmp[i - left];
    }

};
```



分治-快排

```c++
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        srand(time(NULL));
        quick_sort(nums, 0, nums.size() - 1);
        return nums;
    }

    void quick_sort(vector<int>& nums, int left, int right){
        if (left >= right) return ;
        //1. 算出基准值
        int key = getRandom(nums, left, right);
        //2. 对数组进行分成三类的快速排序
        int i = left, l = left - 1, r = right + 1;
        while (i < r)//对数组分成三类
        {
            if (nums[i] < key) swap(nums[++l], nums[i++]);
            else if (nums[i] == key) ++i;
            else swap(nums[--r], nums[i]);  
        }
        //3. 进行递归
        //[left, l][l + 1, r - 1][r, right]
        quick_sort(nums, left, l);//对<key的数进行排序
        quick_sort(nums, r, right);//对>key的数进行排序
    }

    int getRandom(vector<int>& nums, int left, int right){
        int a = rand();
        return nums[a % (right - left + 1) + left];
    }

};
```


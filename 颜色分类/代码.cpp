class Solution {
public:
    void sortColors(vector<int>& nums) {
        // //1. 冒泡排序
        // int n = nums.size();
        // for (int i = 0; i < n; ++i)
        // {
        //     for (int j = i; j < n; ++j)
        //     {
        //         if (nums[i] > nums[j])
        //         {
        //             swap(nums[i], nums[j]);
        //         }
        //     }
        // }

        //2. 快速排序（三路划分）
        int left = -1, right = nums.size();
        int i = 0;
        while (i < right)
        {
            if (nums[i] == 0) swap(nums[++left], nums[i++]);
            else if (nums[i] == 1) ++i;
            else swap(nums[--right], nums[i]);  
        }
    }
};
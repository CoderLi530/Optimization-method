//题目链接：https://leetcode.cn/problems/rotate-array/?envType=study-plan-v2&envId=top-100-liked

class Solution 
{
public:

    void reverse(vector<int>& nums, int start, int end)
    {
        while (start <= end)
        {
            swap(nums[start], nums[end]);
            ++start;
            --end;
        }
    }

    void rotate(vector<int>& nums, int k)
    {
        // //1. 暴力解法 -- 创建一个数组拷贝到原数组中
        // //时间复杂度O(n) 空间复杂度O(k % n)
        // //拷贝元素到对头
        // int n = nums.size();
        // int wheel = k % n;
        // vector<int> tmp(wheel);
        // //拷贝一定的元素
        // for (int i = n - wheel; i < n; ++i)
        // {
        //     tmp[i - (n - wheel)] = nums[i]; 
        // }
        // //加原数组中部分元素后移k位
        // for (int i = n - 1; i - wheel >= 0; --i)
        // {
        //     nums[i] = nums[i - wheel];
        // }
        // //将轮转数覆盖
        // for (int i = 0; i < wheel; ++i)
        // {
        //     nums[i] = tmp[i];
        // }


        // //2. 将未轮转的数尾插，然后头删未轮转的数
        // //时间复杂度O(n) 空间复杂度O(n)
        // int n = nums.size();
        // int wheel = k % n; //需要轮转的数量
        // for (int i = 0; i < n - wheel; ++i)
        // {
        //     nums.push_back(nums[i]);
        // }
        // nums.erase(nums.begin(), nums.begin() + n - wheel);

        
        //3. （1将数组进行翻转，（2将轮转的数进行翻转，（3. 将未轮转的数进行翻转
        //时间复杂度O(n) 空间复杂度O(1)
        int n = nums.size();
        int wheel = k % n;
        reverse(nums, 0, n - 1);
        reverse(nums, 0, wheel - 1);
        reverse(nums, wheel, n - 1);
    }
};
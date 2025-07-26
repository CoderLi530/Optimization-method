//题目链接：https://leetcode.cn/problems/trapping-rain-water/?envType=study-plan-v2&envId=top-100-liked

class Solution
{
public:
    int trap(vector<int>& height)
    {
        int sum = 0; //雨水量
        int left = 0, right = height.size() - 1; //左右开始遍历位置
        int left_max = 0, right_max = 0; //左边和右边最大柱子高度
        //left和right相遇代表接雨水结束
        while (left < right)
        {
            //height[left]和height[right]比较，谁小谁先走
            if (height[left] < height[right])
            {
                //柱子高度连续递增说明没有雨水
                if (height[left] >= left_max)
                {
                    left_max = height[left];
                }
                //有高度差说明有雨水可收集
                else
                {
                    sum += left_max - height[left];
                }
                ++left;
                cout << sum << " ";
            }
            else
            {
                if (height[right] >= right_max)
                {
                    right_max = height[right];
                }
                else
                {
                    sum += right_max - height[right];
                }
                --right;
            }
        }
        return sum;
    }
};
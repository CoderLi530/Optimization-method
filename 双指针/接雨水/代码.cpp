//��Ŀ���ӣ�https://leetcode.cn/problems/trapping-rain-water/?envType=study-plan-v2&envId=top-100-liked

class Solution
{
public:
    int trap(vector<int>& height)
    {
        int sum = 0; //��ˮ��
        int left = 0, right = height.size() - 1; //���ҿ�ʼ����λ��
        int left_max = 0, right_max = 0; //��ߺ��ұ�������Ӹ߶�
        //left��right�����������ˮ����
        while (left < right)
        {
            //height[left]��height[right]�Ƚϣ�˭С˭����
            if (height[left] < height[right])
            {
                //���Ӹ߶���������˵��û����ˮ
                if (height[left] >= left_max)
                {
                    left_max = height[left];
                }
                //�и߶Ȳ�˵������ˮ���ռ�
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
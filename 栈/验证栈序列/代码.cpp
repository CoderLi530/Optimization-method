class Solution 
{
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
        stack<int> stack;//模拟进栈和出栈过程
        int j = 0;//遍历popped
        for (int i = 0; i < pushed.size(); ++i)
        {
            //元素进栈
            stack.push(pushed[i]);

            //判断是否出栈。
            //两个值不相等或者栈为空就结束比较。
            while (!stack.empty() && stack.top() == popped[j])
            {
                stack.pop();
                ++j;
            }
        }
        //遍历pushed结束，判断栈是否为空或者j是否小于popped.size()
        if (stack.empty()) return true;
        else return false;
    }
};
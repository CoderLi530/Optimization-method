class Solution 
{
public:
    int calculate(string s) 
    {
        //一个元素直接返回
        if (s.size() == 1) return s[0] - '0';

        stack<int> stack;
        char op = '+';
        int i = 0;
        while (i < s.size())
        {
            //遇到空格，往后走
            if (s[i] == 32)
            {
                ++i;
                continue;
            }
            //遇到操作符，更新op
            if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') op = s[i++];
            //遇到数字，分情况讨论
            else
            {
                int tmp = 0;
                //提取数字
                //+ - * / 的ASCII值都是小于48
                while (s[i] >= '0')
                {
                    tmp = tmp * 10 + (s[i] - '0');
                    ++i;//直到遇到操作符停止提取数字
                }
                //根据op符号决定怎么操作
                if (op == '+') stack.push(tmp);
                else if (op == '-') stack.push(-tmp);
                else if (op == '*') stack.top() = (stack.top() * tmp);
                else stack.top() = (stack.top() / tmp);
            }
        }
        //遍历结束，对栈中进行相加操作
        int ret = 0;
        while (!stack.empty())
        {
            ret += stack.top();
            stack.pop();
        }
        return ret;
    }
};
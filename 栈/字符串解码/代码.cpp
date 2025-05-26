class Solution {
public:
    string decodeString(string s) {
        //字符串只有一个字符
        if (s.size() == 1) return s;

        //“字符串栈”和“数字栈”
        vector<string> stack1 = {""};//不进行初始化，会有越界访问
        vector<int> stack2;

        int i = 0;
        while (i < s.size())
        {
            //遇到数字，提取数字，放入“数字栈”
            if (s[i] >= '0' && s[i] <= '9')
            {
                int num = 0;
                while (s[i] >= '0' && s[i] <= '9') num = num * 10 + (s[i++] - '0');
                stack2.push_back(num);
            }

            //遇到'['，提取后面的字符串，放入“字符串栈”
            else if (s[i] == '[')
            {
                ++i;//提取'['后面的字符串
                string tmp;
                while (s[i] >= 'a' && s[i] <= 'z') tmp += s[i++];
                stack1.push_back(tmp);
            }

            //遇到']'，执行复制操作，将结果放到栈顶元素后面
            else if (s[i] == ']')
            {
                string str = stack1.back();
                int x = stack2.back();
                stack1.pop_back(), stack2.pop_back();
                while (x--) stack1.back() += str;
                ++i;
            }

            //遇到单独的字符，直接放入“字符串栈”的栈顶元素后面
            //有可能越界，注意判断i的位置
            else while (i < s.size() && s[i] >= 'a' && s[i] <= 'z') stack1.back() += s[i++];
        }
        //遍历结束，“字符串栈”中存放的是最终字符串
        return stack1.back();
    }
};
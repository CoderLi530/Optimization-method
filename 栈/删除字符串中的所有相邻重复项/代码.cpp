class Solution {
public:
    string removeDuplicates(string s) {
        //字符串只有一个元素直接返回本身
        if (s.size() == 1) return s;
        string ret;//利用string模拟栈操作
        for (int i = 0; i < s.size(); ++i)
        {
            //ret不为空进行比较是否相同
            if (ret.size())
            {
                //相同尾删操作
                if (ret.back() == s[i]) ret.pop_back();
                //不相同放进元素
                else ret += s[i];
            }
            //ret为空放进元素
            else ret += s[i];
        }
        //遍历结束，ret存放最终的值
        return ret;
    }
};
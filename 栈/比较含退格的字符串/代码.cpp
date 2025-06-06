class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string tmp1, tmp2;//进行最终的比较的字符串
        //进行消除操作
        int cur1 = 0, cur2 = 0;
        while (cur1 < s.size() || cur2 < t.size())
        {
            //对s进行消除操作
            if (cur1 < s.size())
            {
                if (tmp1.size() && s[cur1] == '#') tmp1.pop_back();
                else    
                {
                    if (s[cur1] != '#')tmp1 += s[cur1];
                }
                ++cur1;
            }
            //对t进行消除操作
            if (cur2 < t.size())
            {
                if (tmp2.size() && t[cur2] == '#') tmp2.pop_back();
                else
                {
                    if (t[cur2] != '#')tmp2 += t[cur2];
                }
                ++cur2;
            }
        }
        //遍历结束消除#完毕，比较tmp1和tmp2是否相等
        cur1 = 0, cur2 = 0;
        if (tmp1.size() != tmp2.size()) return false;
        while (cur1 < tmp1.size() && cur2 < tmp2.size())
            if (tmp1[cur1++] != tmp2[cur2++]) return false;
        return true;
    }
};
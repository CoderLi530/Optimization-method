class Solution {
public:
    string longestPalindrome(string s) {
        //中心扩展算法
        int begin = 0, len = 0, n = s.size();
        for (int i = 0; i < s.size(); ++i)//列举所有的中点
        {
            //往中点两边扩展
            //奇数情况
            int left = i, right = i;
            while (left >= 0 && right < s.size() && s[left] == s[right])
            {
                left--;
                right++;
            }
            if (right - left - 1 > len)
            {
                begin = left + 1;
                len = right - left - 1;
            }
            //偶数情况
            left = i - 1, right = i;
            while (left >= 0 && right < s.size() && s[left] == s[right])
            {
                left--;
                right++;
            }
            if (right - left - 1 > len)
            {
                begin = left + 1;
                len = right - left - 1;
            }
        }
        return s.substr(begin, len);
    }
};
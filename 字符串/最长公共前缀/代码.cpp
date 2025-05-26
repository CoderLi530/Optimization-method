class Solution {
public:

    string findCommon(string& s1, string& s2)
    {
        string tmp;
        for (int i = 0; i < s1.size(); ++i)
        {
            if (s1[i] == s2[i]) tmp += s1[i];
            else return tmp;//不相同就返回
        }
        return tmp;
    }
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) return strs[0];
        //两两寻找
        string ret = strs[0];
        for (int i = 1; i < strs.size(); ++i)
        {
            ret = findCommon(ret, strs[i]);
        }
        return ret;
    }
};
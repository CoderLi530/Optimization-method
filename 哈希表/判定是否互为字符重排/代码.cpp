class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        //判断：字符串长度不相等，直接返回false
        if (s1.size() != s2.size()) return false;

        //使用数组模拟哈希表。
        int hash[26];//该数组一一对应字母个数
        //将s1存放到hash中
        for (auto ch : s1) hash[ch - 'a']++;
        //遍历s2，在hash中寻找字符，找到就--，如果为负数直接返回false。
        for (auto ch : s2)
        {
            if (hash[ch - 'a']--);
            else return false;
        }
        //循环结束后，不存在数组大于0的情况
        return true;
    }
};
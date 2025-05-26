//逆序两个字符串
class Solution {
public:
    string addBinary(string a, string b) {
        //字符1对应ASCII值为49，字符0对应ACSII值为48，计算时应当进行字符转换
        //逆序一下
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int t = 0, i = 0;
        string ret;
        while (i < a.size() && i < b.size())//遍历两个字符串，进行计算
        {
            t += a[i] + b[i] - '0' - '0';
            ret += t % 2 + '0';
            t /= 2;
            ++i;
        }
        while (i < a.size())//a比b长
        {
            t += a[i++] - '0';
            ret += t % 2 + '0';
            t /= 2;
        }
        while (i < b.size())//b比a长
        {
            t += b[i++] - '0';
            ret += t % 2 + '0';
            t /= 2;
        }
        //t等于1，还要进行进位
        if (t == 1) ret += '1';
        reverse(ret.begin(), ret.end());
        return ret;
    }
};




//逆序两个字符串–优化代码
class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string ret;
        int cur1 = 0, cur2 = 0, t = 0;
        while (cur1 < a.size() || cur2 < b.size() || t)//两个字符串遍历完或者进位值等于0就结束循环
        {
            //存在字符进行计算
            if (cur1 < a.size()) t += a[cur1++] - '0';
            if (cur2 < b.size()) t += b[cur2++] - '0';
            //放进ret中
            ret += t % 2 + '0';
            t /= 2;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};



//不进行逆序操作
class Solution {
public:
    string addBinary(string a, string b) {
        string ret;
        int cur1 = a.size() - 1, cur2 = b.size() - 1, t = 0;
        while (cur1 >= 0 || cur2 >= 0 || t)//两个字符串遍历完和进位值等于0就结束循环
        {
            //存在字符进行计算
            if (cur1 >= 0 ) t += a[cur1--] - '0';
            if (cur2 >= 0 ) t += b[cur2--] - '0';
            //放进ret中
            ret += t % 2 + '0';
            t /= 2;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
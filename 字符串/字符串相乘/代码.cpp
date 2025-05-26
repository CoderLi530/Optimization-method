//解法一：模拟列竖式相乘再相加
class Solution {
public:
    string multiply(string num1, string num2) {
        //字符串为0返回0
        if (num1[0] == '0' || num2[0] == '0') return "0";
        string tmp, ret;
        //逆序字符串好操作
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        //进行计算
        for (int i = 0; i < num2.size(); ++i)
        {
            int t = 0;//进位值
            //初始化tmp，后续要空串来设置前导0
            tmp.clear();
            //设置前导0
            int n = i;
            while (n--) tmp += '0';
            for (int j = 0; j < num1.size(); ++j)
            {
                //计算
                int x = (num2[i] - '0') * (num1[j] - '0') + t;
                t = x / 10;
                tmp += x % 10 + '0';
                ret += '0';//为后续相加提供了空间赋值
            }
            //进行一次计算要进行进位操作，例如个位数相乘需要进位时但没有进位
            if (t)
            {
                tmp += t + '0';
                ret += '0';
                t /= 10;
            }

            //tmp相加到ret中
            int cur1 = 0, cur2 = 0, c = 0;
            while (cur1 < tmp.size() || cur2 < ret.size() || c)
            {
                if (cur1 < tmp.size()) c += tmp[cur1] - '0';
                if (cur2 < ret.size()) c += ret[cur2] - '0';
                ret[cur2] = c % 10 + '0';//进行替换字符
                c /= 10;
                ++cur1, ++cur2;
            }
        }
        //ret中已经存放了最终的答案，但是需要逆序和除掉前导0
        reverse(ret.begin(), ret.end());
        //消除前导0
        while (ret[0] == '0') ret.erase(0, 1);
        return ret;
    }
};



//解法二：无进位相乘再相加，最后消除前导0
class Solution {
public:
    string multiply(string num1, string num2) {
        
        //有一个字符串为0返回0
        if (num1[0] == '0' || num2[0] == '0')
            return "0";
        // int tmp[num1.size() + num2.size()];
        vector<int> tmp(num1.size() + num2.size());
        string ret;
        // 对两个字符串进行逆序操作
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        // 进行无进位相乘相加放进tmp中
        for (int i = 0; i < num1.size(); ++i) {
            for (int j = 0; j < num2.size(); ++j) {
                tmp[i + j] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        // 进行进位操作
        int t = 0;
        for (int i = 0; i < tmp.size(); ++i)
        {
            int x = tmp[i];
            x += t;
            ret += x % 10 + '0';
            t = x / 10;
        }
        if (t) ret += t + '0';
        reverse(ret.begin(), ret.end());
        //消除前导0
        while (ret[0] == '0') ret.erase(0, 1);
        return ret;
    }
};
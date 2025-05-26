class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        //1. 创建哈希表，创建一个字符串croak
        unordered_map<char, int> hash;
        string tmp("croak");
        //2. 遍历字符串
        for (int i = 0; i < croakOfFrogs.size(); ++i)
        {
            int index = tmp.find(croakOfFrogs[i]);//在tmp找到当前字符的下标
            if (index == 0)//遍历到c字符
            {
                if (hash[tmp[4]]) hash[tmp[4]]--;
                hash[tmp[index]]++;
            }
            else//遍历到其它字符
            {
                //找到前一个字符，判断是否存在
                if (hash[tmp[index - 1]])
                {
                    hash[tmp[index - 1]]--;
                    hash[tmp[index]]++;
                }
                else return -1;
            }
        }
        //遍历完毕，哈希表中croa个数大于0，说明蛙鸣声（croak）不全，返回-1
        if (hash['c'] || hash['r'] || hash['o'] || hash['a'])   return -1;
        return hash['k'];
    }
};
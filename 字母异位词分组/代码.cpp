class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size() == 1) return {strs};

        unordered_map<string, vector<string>> hash;
        //进行分组
        for (auto& s : strs)
        {
            //哈希表先查找是否存在排序好的字符串，不存在创建，存在写入
            //哈希表放进（排序好的字符串，原本的字符串）
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            hash[tmp].push_back(s);
        }
        //放入数据
        vector<vector<string>> ret;
        // for (auto& [x, y] : hash)
        // {
        //     ret.push_back(y);
        // }
        for (auto& x : hash)
        {
            ret.push_back(x.second);
        }
        return ret;
    }
};
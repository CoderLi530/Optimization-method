#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<functional>
#include<vector>
#include<unordered_map>
#include<queue>
#include<stack>

using namespace std;

void InsertSort(vector<int>& num, int val)
{
    //数组可能为空
    if (num.size() == 0) num.push_back(val);
    //遍历数组，num[i]与val比较，在合理位置进行插入，后面的元素进行覆盖
    for (int i = 0; i < num.size(); ++i)
    {
        if (val >= num[i])
        {
            //在i+1位置进行插入val，后面的元素进行覆盖
            num.resize(num.size() + 1);
            for (int j = num.size() - 1; j > i + 1; ++j)
            {
                num[j] = num[j - 1];
            }
            num[i + 1] = val;
        }
    }
}

int main()
{
    vector<int> num;
    InsertSort(num, 1);
    InsertSort(num, 2);
    InsertSort(num, 3);
    InsertSort(num, 1);
    InsertSort(num, 2);
    InsertSort(num, 3);
    InsertSort(num, 4);
    InsertSort(num, 2);
    return 0;
}
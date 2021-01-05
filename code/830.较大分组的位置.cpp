#include<vector>
#include<string>
using namespace std;

//双指针遍历解法
//当两个位置的元素相等时，快指针++，遇到不相等时，判断是否>3
//若大于3则放入答案中，若不是则更新慢指针位置
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        int i = 0, j = 1;
        vector<vector<int>> ans;
        vector<int> res;
        for (int i = 0, j = 1; j <= s.length(); j++)
        {
            if (s[j] != s[i] || j >= s.length())
            {
                if (j - i >= 3)
                {
                    res.clear();
                    res.push_back(i);
                    res.push_back(j - 1);
                    ans.push_back(res);

                }
                i = j;
            }
        }
        return ans;
    }
};
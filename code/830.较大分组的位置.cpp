#include<vector>
#include<string>
using namespace std;

//˫ָ������ⷨ
//������λ�õ�Ԫ�����ʱ����ָ��++�����������ʱ���ж��Ƿ�>3
//������3�������У��������������ָ��λ��
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
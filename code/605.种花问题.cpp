#include<vector>
using namespace std;


class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for (int i = 0; i < flowerbed.size(); i++) {
            if (flowerbed[i] == 0
                && !(i == 0 ? 0 : flowerbed[i - 1])
                && !(i == flowerbed.size() - 1 ? 0 : flowerbed[i + 1]))
                //�����жϵ�ǰλ��Ϊ0����ô��i=0||��β��ʱ��
                //�жϵ�ӦΪ��ǰֵ����һ��Ϊ0
            {
                n--;
                flowerbed[i] = 1;
            }
        }
        return n <= 0;
    }
};
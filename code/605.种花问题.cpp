#include<vector>
using namespace std;


class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for (int i = 0; i < flowerbed.size(); i++) {
            if (flowerbed[i] == 0
                && !(i == 0 ? 0 : flowerbed[i - 1])
                && !(i == flowerbed.size() - 1 ? 0 : flowerbed[i + 1]))
                //首先判断当前位置为0，那么当i=0||结尾的时候
                //判断的应为当前值，则一定为0
            {
                n--;
                flowerbed[i] = 1;
            }
        }
        return n <= 0;
    }
};
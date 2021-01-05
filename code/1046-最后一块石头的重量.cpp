#include<vector>
#include <queue>
using namespace std;



//递归求解
 class Solution {
 public:
     int lastStoneWeight(vector<int>& stones) {
         int n = stones.size();
         if (1 == n) return stones[0];
         if (2 == n) return abs(stones[0] - stones[1]);
         sort(stones.begin(), stones.end());
         if (0 == stones[n - 3]) return stones[n - 1] - stones[n - 2];
         stones[n - 1] -= stones[n - 2];
         stones[n - 2] = 0;
         return lastStoneWeight(stones);
     }
 };

//STL优先队列
class Solution2 {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> queue;
        for (int i : stones) {
            queue.push(i);
        }
        while (queue.size() > 1) {
            int first = queue.top();
            queue.pop();
            int second = queue.top();
            queue.pop();
            if (first > second) {
                queue.push(first - second);
            }
        }
        return queue.empty() ? 0 : queue.top();
    }
};

//手写大顶堆



#include<queue>
using namespace std;

//优先队列求解
class Solution1 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> queue;
        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
            queue.emplace(nums[i], i);
        }
        ans.push_back(queue.top().first);
        for (int i = k; i < nums.size(); i++)
        {
            queue.emplace(nums[i], i);
            while (queue.top().second < i - k + 1)
            {
                queue.pop();
            }
            ans.push_back(queue.top().first);
        }

        return ans;
    }
};

//单调队列求解：头尾都可以高效插入弹出的双向队列，和vector的区别是
/*
* back指塞入元素的一方，front则指寻常意义的队列另一端
1. 假使序列为5，3，4，1
2.首先将5压入单调队列，然后判断3，3<5，所以5继续在队列里，此时在将来的滑动窗口里，当5弹出后，3有可能成为最大值
  所以应该将3保留在队列里
3.接下来判断4，4>3,所以只要4进入了队列，3永远不可能成为最大值，所以从尾部弹出
4.即每次队列首部都是最大值，但是需要判断当前最大值是否还在滑动窗口内，若不在则从头部弹出
*/
class Solution2 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> queue;
        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
            while (!queue.empty() && nums[i] >= nums[queue.back()])
            {
                queue.pop_back();
            }
            queue.push_back(i);
        }
        ans.push_back(nums[queue.front()]);
        for (int i = k; i < nums.size(); i++)
        {
            while (!queue.empty() && nums[i] >= nums[queue.back()])
            {
                queue.pop_back();
            }
            queue.push_back(i);
            while (queue.front() <= i - k)
            {
                queue.pop_front();
            }
            ans.push_back(nums[queue.front()]);
        }
        return ans;
    }
};

//单调队列压缩写法
//会有多判断的基础操作
//但是写法优雅
class Solution3 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> queue;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            if (!queue.empty() && queue.front() < i - k + 1)
                queue.pop_front();
            while (!queue.empty() && nums[queue.back()] < nums[i])
            {
                queue.pop_back();
            }
            queue.push_back(i);
            if (i >= k - 1)
                ans.emplace_back(nums[queue.front()]);
        }
    }
};

//分块+预处理
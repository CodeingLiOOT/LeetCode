#include<queue>
using namespace std;

//���ȶ������
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

//����������⣺ͷβ�����Ը�Ч���뵯����˫����У���vector��������
/*
* backָ����Ԫ�ص�һ����front��ָѰ������Ķ�����һ��
1. ��ʹ����Ϊ5��3��4��1
2.���Ƚ�5ѹ�뵥�����У�Ȼ���ж�3��3<5������5�����ڶ������ʱ�ڽ����Ļ����������5������3�п��ܳ�Ϊ���ֵ
  ����Ӧ�ý�3�����ڶ�����
3.�������ж�4��4>3,����ֻҪ4�����˶��У�3��Զ�����ܳ�Ϊ���ֵ�����Դ�β������
4.��ÿ�ζ����ײ��������ֵ��������Ҫ�жϵ�ǰ���ֵ�Ƿ��ڻ��������ڣ����������ͷ������
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

//��������ѹ��д��
//���ж��жϵĻ�������
//����д������
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

//�ֿ�+Ԥ����
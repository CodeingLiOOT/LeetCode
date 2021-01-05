#include <cstddef>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

//分隔链表，因为要求保留两节点的初始相对位置，所以不能采用头插+尾插的方法
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(0), * large = new ListNode(0);
        ListNode* p = small, * q = large;
        while (head)
        {
            if (head->val >= x)
            {
                q->next = head;
                q = q->next;
            }
            else {
                p->next = head;
                p = p->next;
            }
            head = head->next;
        }
        //重中之重，如果head最后一个元素不是大元素
        //那么大元素链表后面的链表都会保留，和小元素的链表后元素是同一个结点
        //占用同一个内存，此时若让小元素链表指向大元素链表，则链表出现环
        q->next = nullptr;
        p->next = large->next;
        return small->next;
    }
};
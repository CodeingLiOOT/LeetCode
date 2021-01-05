#include <cstddef>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

//�ָ�������ΪҪ�������ڵ�ĳ�ʼ���λ�ã����Բ��ܲ���ͷ��+β��ķ���
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
        //����֮�أ����head���һ��Ԫ�ز��Ǵ�Ԫ��
        //��ô��Ԫ���������������ᱣ������СԪ�ص������Ԫ����ͬһ�����
        //ռ��ͬһ���ڴ棬��ʱ����СԪ������ָ���Ԫ��������������ֻ�
        q->next = nullptr;
        p->next = large->next;
        return small->next;
    }
};
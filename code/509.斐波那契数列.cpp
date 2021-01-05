//��������ⷨ
//���С��2ֱ�ӷ���
//�������2�����ʱaΪf(2)��ֵ��bΪf(1)��ֵ
//��a=a+b����aΪf(3)��ֵ����ʱb=a-b����bΪԭ��a��ֵ��f(2)��ֵ
//�Դ����ƹ����������
class Solution1 {
public:
    int fib(int n) {
        if (n < 2) return n;
        int a = 1, b = 1;
        for (int i = 2; i < n; i++)
        {
            a += b;
            b = a - b;
        }
        return a;
    }
};

class Solution2 {
public:
    int fib(int n) {
        if (n < 2) return n;
        int p=0,q=1,r=p+q;
        for (int i = 2; i < n; i++)
        {
            p=q;
            q=r;
            r=p+q;

        }
        
        return r;
    }
};
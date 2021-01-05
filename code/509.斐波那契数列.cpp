//滚动数组解法
//如果小于2直接返回
//如果大于2，则此时a为f(2)的值，b为f(1)的值
//令a=a+b则让a为f(3)的值，此时b=a-b则让b为原来a的值即f(2)的值
//以此类推滚动数组求解
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
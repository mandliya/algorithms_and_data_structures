// https : // leetcode.com/problems/implement-stack-using-queues/

class MyStack
{
public:
    queue<int> q1;
    queue<int> q2;

    void push(int x)
    {

        q2.push(x);

        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        swap(q1, q2);
    }

    int pop()
    {
        int result = top();
        q1.pop();
        return result;
    }

    int top()
    {
        return q1.front();
    }

    bool empty()
    {
        return q1.empty();
    }
};
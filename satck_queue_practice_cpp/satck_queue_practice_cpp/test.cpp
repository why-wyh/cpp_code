#define _CRT_SECURE_NO_WARNINGS 
//最小栈
class MinStack {
    stack<int>min;
    stack<int>st;
public:
    MinStack() {
        while (!st.empty())
        {
            st.pop();
        }
        while (!min.empty())
        {
            min.pop();
        }
    }

    void push(int val) {
        st.push(val);
        if (min.empty() || val <= min.top())
        {
            min.push(val);
        }
    }

    void pop() {


        if (st.top() <= min.top())
        {
            min.pop();
        }
        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return min.top();
    }
};
class Solution {
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        int n = pushV.size();
        //辅助栈
        stack<int> s;
        //遍历入栈的下标
        int j = 0;
        //遍历出栈的数组
        for (int i = 0; i < n; i++) {
            //入栈：栈为空或者栈顶不等于出栈数组
            while (j < n && (s.empty() || s.top() != popV[i])) {
                s.push(pushV[j]);
                j++;
            }
            //栈顶等于出栈数组
            if (s.top() == popV[i])
                s.pop();
            //不匹配序列
            else
                return false;
        }
        return true;
    }
};

#define _CRT_SECURE_NO_WARNINGS 
//×îÐ¡Õ»
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
    bool IsPopOrder(vector<int>& pushV, vector<int>& popV) {
        stack<int>st;
        size_t sz = pushV.size();
        int j = 0;
        for (int i = 0; i < sz; ++i)
        {

            while (j < sz && (st.empty() || (st.top() != popV[i])))
            {
                st.push(pushV[j]);
                ++j;
            }
            if (st.top() == popV[i])
                st.pop();
            else
                return false;
        }
        return true;
    }
};


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        size_t i = 0;
        for (; i < k; ++i)
            pq.push(nums[i]);
        for (; i < nums.size(); ++i)
        {
            if (nums[i] > pq.top())
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        int val1, val2;
        for (auto e : tokens)
        {
            if (e != "+" && e != "-" && e != "*" && e != "/")
            {
                st.push(stoi(e));
            }
            if (e == "+")
            {
                val1 = st.top();
                st.pop();
                val2 = st.top();
                st.pop();
                st.push(val1 + val2);
            }
            else if (e == "-")
            {
                val1 = st.top();
                st.pop();
                val2 = st.top();
                st.pop();
                st.push(val2 - val1);
            }
            else if (e == "*")
            {
                val1 = st.top();
                st.pop();
                val2 = st.top();
                st.pop();
                st.push(val1 * val2);
            }
            else if (e == "/")
            {
                val1 = st.top();
                st.pop();
                val2 = st.top();
                st.pop();
                st.push(val2 / val1);
            }
        }
        return st.top();
    }
};

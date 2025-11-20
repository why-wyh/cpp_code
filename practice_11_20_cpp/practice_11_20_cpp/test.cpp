#define _CRT_SECURE_NO_WARNINGS 
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = INT_MIN, temp = 0;//本题中可能会有负数（nums={-1}k=-1）
        for (int i = 0; i < nums.size(); i++)
        {

            temp += nums[i];
            if (i < k - 1)
                continue;
            ans = max(ans, temp);
            temp -= nums[i - k + 1];
        }
        return (double)ans / k;
    }
};


class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum = 0, ans = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];
            if (i < k - 1)
                continue;
            if (sum >= threshold * k)
                ans++;
            sum -= arr[i - k + 1];
        }
        return ans;
    }
};



class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int len = 2 * k + 1;
        long long temp = 0;
        vector<int>ans(nums.size(), -1);//利用vector构造全为-1再用下标插入
        for (int i = 0; i < nums.size(); i++)
        {
            temp += nums[i];
            if (i < 2 * k)
            {
                continue;
            }
            ans[i - k] = temp / (2 * k + 1);
            temp -= nums[i - k * 2];
        }
        return ans;
    }
};
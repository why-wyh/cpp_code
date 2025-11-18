#define _CRT_SECURE_NO_WARNINGS 
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int right=arr.size()-1;
        int left=0;
        while(left<right)
        {
            int mid=(left+right)/2;
            if(arr[mid]>arr[mid+1])
           { 
            right=mid;
           }
           else{
            left=mid+1;
           }
        }
        return right;
    }
};



class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int i = 0, count = 0;
        for (i = left; i < right + 1; i++)
        {
            int sz = words[i].size() - 1;
            if (words[i][0] == 'a' || words[i][0] == 'e' || words[i][0] == 'i' || words[i][0] == 'o' || words[i][0] == 'u')
            {
                if (words[i][sz] == 'a' || words[i][sz] == 'e' || words[i][sz] == 'i' || words[i][sz] == 'o' || words[i][sz] == 'u')

                    count++;
            }

        }
        return count;
    }
};

class Solution {
public:
    int maxScore(string s) {
        size_t sz = s.size();
        int score = ranges::count(s, '1');
        int ans = 0;
        for (int i = 0; i + 1 < sz; i++)
        {
            score += s[i] == '0' ? 1 : -1;
            ans = max(ans, score);
        }
        return ans;
    }
};



class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector ans(n, vector<int>(m));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                ans[j][i] = matrix[i][j];
        }
        return ans;
    }
};



class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>ans(2 * n);
        int k = 0;
        int j = n;
        for (int i = 0; i < 2 * n; i += 2, j++, k++)
        {
            ans[i] = nums[k];
            ans[i + 1] = nums[j];
        }
        return ans;
    }
};



class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0)
            return false;
        while (n % 3 == 0)
            n /= 3;
        while (n % 5 == 0)
            n /= 5;
        return(n & (n - 1)) == 0;
    }
};

class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;
    }
};


class Solution {
public:
    bool isPowerOfTwo(int n) {
        int cout = 0;
        for (int i = 0; i < 32; i++)
        {
            if ((n >> i) & 1)
                cout++;
        }
        return n > 0 && cout == 1;
    }
};



class Solution {
public:
    int subtractProductAndSum(int n) {
        int m = 1, sum = 0;
        while (n)
        {
            sum += n % 10;
            m *= n % 10;
            n /= 10;
        }
        return m - sum;
    }
};


class Solution {
public:
    int addDigits(int num) {
        int sum;
        do {
            sum = 0;
            while (num)
            {
                sum += (num % 10);
                num /= 10;
            }
            num = sum;
        } while (num / 10);
        return sum;
    }
};


class Solution {
public:
    string toLowerCase(string s) {
        for (char& ch : s)
        {
            ch = tolower(ch);
        }
        return s;
    }
};
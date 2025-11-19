#define _CRT_SECURE_NO_WARNINGS 
class Solution {
public:
    int maxVowels(string s, int k) {
        int i, count = 0;
        for (i = 0; i + k <= s.size(); i++)
        {
            int con = 0;
            for (int m = i; m < i + k; m++)
            {
                if (s[m] == 'a' || s[m] == 'e' || s[m] == 'i' || s[m] == 'o' || s[m] == 'u')
                    con++;
            }
            count = max(con, count);
            if (count == k)
                break;
        }
        return count;
    }
};


class Solution {
public:
    int maxVowels(string s, int k) {
        int ans = 0, count = 0;
        int sz = s.size();
        for (int i = 0; i < sz; i++)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                count++;
            int left = i - k + 1;
            if (left < 0)
                continue;
            ans = max(ans, count);
            if (ans == k)
                break;
            if (s[left] == 'a' || s[left] == 'e' || s[left] == 'i' || s[left] == 'o' || s[left] == 'u')
                count--;
        }
        return ans;
    }
};


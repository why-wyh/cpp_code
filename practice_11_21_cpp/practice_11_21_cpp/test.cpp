#define _CRT_SECURE_NO_WARNINGS 
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int sz = blocks.size();
        int ans = 200, count = 0;
        for (int i = 0; i < sz; i++)
        {
            if (blocks[i] == 'W')
                count++;
            if (i < k - 1)
                continue;
            ans = min(count, ans);
            if (blocks[i - k + 1] == 'W')
                count--;
        }
        return ans;
    }
};
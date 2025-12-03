#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
struct SignalNode
{

};

int main()
{
	char s[80], c = 'a';                   // 问题：为何是s[80]，s[20]不可以吗，s[800]呢？ 
	int i = 0;
	scanf("%s", s);
	while (s[i] != '\0')
	{
		if (s[i] == c) s[i] = s[i] - 32;         // 问题：语句含义？为什么是32。
		else if (s[i] == c - 32) s[i] = s[i] + 32; // 问题：语句含义？为什么是32。
		i++;
	}
	puts(s);
	return 0;
}


class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int s[2] = { 0 }, max_s = 0;
        for (int i = 0; i < customers.size(); i++)
        {
            s[grumpy[i]] += customers[i];
            if (i - minutes + 1 < 0)
                continue;
            max_s = max(max_s, s[1]);
            s[1] -= grumpy[i - minutes + 1] ? customers[i - minutes + 1] : 0;
        }

        return s[0] + max_s;
    }
};


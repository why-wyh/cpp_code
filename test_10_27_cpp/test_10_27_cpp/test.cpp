#define _CRT_SECURE_NO_WARNINGS 
using namespace std;
#include <iostream>
#include<vector>
//singal dog¢ñ
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int e : nums)
        {
            ans ^= e;
        }
        return ans;
    }
};
//singal dog¢ò
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int arr[32] = { 0 };
        for (auto e : nums)
        {
            for (size_t i = 0; i < 32; ++i)
            {
                if (e & (1 << i))
                {
                    arr[i]++;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < 32; i++)
        {
            if (arr[i] % 3 == 1)
            {
                ans |= (1 << i);
            }
        }
        return ans;
    }
};
//singal dog¢ó
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = 0, ans1 = 0, ans2 = 0;
        vector<int> ret;
        for (auto e : nums)
        {
            n ^= e;
        }
        for (int i = 0; i < 32; ++i)
        {
            if (n & (1 << i))
            {
                for (auto j : nums)
                {
                    if (j & (1 << i))
                        ans1 ^= j;
                    else
                        ans2 ^= j;
                }
                break;
            }
        }
        ret.push_back(ans1);
        ret.push_back(ans2);
        return ret;
    }
};
int main()
{
	
	return 0;
}